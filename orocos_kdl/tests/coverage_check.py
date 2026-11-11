#!/usr/bin/env python3
"""Gate an lcov tracefile against coverage.json.

usage: coverage_check.py <kdl.info> <coverage.json>

Exit codes:
  0  all floors met, every listed file fully covered
  1  a total is below its floor, or a listed file has uncovered functions
  2  a listed file is missing from the tracefile (or bad usage)

Function names in FN records are demangled with c++filt when it is available.
"""
import json
import shutil
import subprocess
import sys


def parse(path):
    """Return {source file: {"lf", "lh", "fnf", "fnh", "fn", "fnda"}}."""
    files, cur = {}, None
    with open(path) as f:
        for line in f:
            line = line.strip()
            if line.startswith("SF:"):
                cur = files.setdefault(line[3:], dict(lf=0, lh=0, fnf=0, fnh=0, fn={}, fnda={}))
            elif cur is None:
                continue
            elif line.startswith("FN:"):
                # FN:<first line>[,<last line>],<name>
                parts = line[3:].split(",", 2)
                cur["fn"][parts[2] if len(parts) == 3 and parts[1].isdigit() else parts[1]] = True
            elif line.startswith("FNDA:"):
                count, name = line[5:].split(",", 1)
                cur["fnda"][name] = cur["fnda"].get(name, 0) + int(count)
            elif line.split(":", 1)[0] in ("LF", "LH", "FNF", "FNH"):
                key, val = line.split(":", 1)
                cur[key.lower()] += int(val)
    return files


def demangle(names):
    if not names or not shutil.which("c++filt"):
        return list(names)
    out = subprocess.run(["c++filt"], input="\n".join(names), capture_output=True, text=True)
    return out.stdout.splitlines() if out.returncode == 0 else list(names)


def main(argv):
    if len(argv) != 3:
        print(__doc__, file=sys.stderr)
        return 2
    files = parse(argv[1])
    with open(argv[2]) as f:
        cfg = json.load(f)

    status = 0
    # Tests like solvertest are randomized, so the totals wobble slightly between
    # runs; the totals may fall this many percentage points below their floors.
    tol = cfg.get("tolerance", 0.0)
    totals = {k: sum(d[k] for d in files.values()) for k in ("lf", "lh", "fnf", "fnh")}
    for what, hit, found, floor in (
        ("lines", totals["lh"], totals["lf"], cfg["min_lines"]),
        ("functions", totals["fnh"], totals["fnf"], cfg["min_functions"]),
    ):
        pct = 100.0 * hit / found if found else 0.0
        print(f"{what}: {pct:.2f}% ({hit}/{found}), floor {floor}% - tolerance {tol} = {floor - tol:.2f}%")
        if pct < floor - tol:
            print(f"FAIL: {what} coverage {pct:.2f}% is below {floor - tol:.2f}%")
            status = 1

    for entry in cfg["full_function_coverage"]:
        suffix = "/orocos_kdl/" + entry
        match = [d for sf, d in files.items() if sf.endswith(suffix)]
        if not match:
            print(f"ERROR: {entry} is not in the tracefile (renamed or deleted?)")
            return 2
        d = match[0]
        if d["fnh"] < d["fnf"]:
            missed = sorted(n for n in d["fn"] if d["fnda"].get(n, 0) == 0)
            print(f"FAIL: {entry} has {d['fnf'] - d['fnh']} of {d['fnf']} functions uncovered:")
            for name in sorted(demangle(missed)):
                print(f"  {name}")
            status = 1
    return status


if __name__ == "__main__":
    sys.exit(main(sys.argv))

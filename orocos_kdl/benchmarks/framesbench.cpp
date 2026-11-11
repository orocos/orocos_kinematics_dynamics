// Micro-benchmarks for the frame types and the recursive forward kinematics solvers.
// Prints "<case>\t<ns/op>" per case, followed by a "checksum" line so that the
// optimizer cannot drop the work and two builds can be checked to measure the same thing.
// Uses only API common to KDL 1.5 and 2.0, so it can be built against either.
//
// Each case lives in its own noinline function. That keeps the code layout of one case
// (loop alignment, register allocation) independent of the others, so a change in one
// inlined KDL function can't move another case's loop across an alignment boundary and
// change its timing.
// The binary runs each case once. For best-of-3, run the binary three times and take
// the minimum per case.
#include <chrono>
#include <cstdio>
#include <vector>

#include <frames.hpp>
#include <chain.hpp>
#include <chainfksolverpos_recursive.hpp>
#include <chainfksolvervel_recursive.hpp>
#include <jntarray.hpp>
#include <jntarrayvel.hpp>

using namespace KDL;

namespace {

#if defined(_MSC_VER)
#define KDL_BENCH_NOINLINE __declspec(noinline)
#else
#define KDL_BENCH_NOINLINE __attribute__((noinline))
#endif

using Clock = std::chrono::steady_clock;

double elapsed_ns(Clock::time_point t0)
{
    return std::chrono::duration<double, std::nano>(Clock::now() - t0).count();
}

double sum(const Frame& f)
{
    double s = 0;
    for (int i = 0; i < 3; ++i) {
        s += f.p(i);
        for (int j = 0; j < 3; ++j)
            s += f.M(i, j);
    }
    return s;
}

void report(const char* name, double ns_per_op, double checksum)
{
    std::printf("%s\t%.3f\tchecksum=%.9g\n", name, ns_per_op, checksum);
}

Chain make_chain()
{
    Chain chain;
    for (int i = 0; i < 7; ++i)
        chain.addSegment(Segment(i % 2 == 0 ? Joint(Joint::RotZ) : Joint(Joint::RotY),
                                 Frame(Vector(0, 0, 0.3))));
    return chain;
}

KDL_BENCH_NOINLINE void bench_latency_frame_mul()
{
    const long n = 50000000;
    const Frame G(Rotation::RPY(0.1, 0.2, 0.3), Vector(0.1, 0.2, 0.3));
    Frame F = Frame::Identity();
    auto t0 = Clock::now();
    for (long i = 0; i < n; ++i)
        F = F * G;
    double ns = elapsed_ns(t0);
    report("latency_frame_mul", ns / n, sum(F));
}

KDL_BENCH_NOINLINE void bench_throughput_frame_mul()
{
    const int size = 4096, reps = 20000;
    std::vector<Frame> A(size), B(size), C(size);
    for (int i = 0; i < size; ++i) {
        A[i] = Frame(Rotation::RPY(0.001 * i, 0.2, 0.3), Vector(0.1, 0.2, 0.001 * i));
        B[i] = Frame(Rotation::RPY(0.1, 0.002 * i, 0.3), Vector(0.001 * i, 0.2, 0.3));
    }
    auto t0 = Clock::now();
    for (int r = 0; r < reps; ++r)
        for (int i = 0; i < size; ++i)
            C[i] = A[i] * B[i];
    double ns = elapsed_ns(t0);
    double cs = 0;
    for (int i = 0; i < size; ++i)
        cs += sum(C[i]);
    report("throughput_frame_mul", ns / (double(size) * reps), cs);
}

KDL_BENCH_NOINLINE void bench_vector_add_chain()
{
    const long n = 200000000;
    Vector v(0, 0, 0);
    const Vector d(1e-9, 2e-9, 3e-9);
    auto t0 = Clock::now();
    for (long i = 0; i < n; ++i)
        v = v + d;
    double ns = elapsed_ns(t0);
    report("vector_add_chain", ns / n, v.x() + v.y() + v.z());
}

KDL_BENCH_NOINLINE void bench_rotz_full()
{
    const long n = 20000000;
    double cs = 0;
    auto t0 = Clock::now();
    for (long i = 0; i < n; ++i) {
        Rotation R = Rotation::RotZ(i * 1e-7);
        for (int a = 0; a < 3; ++a)
            for (int b = 0; b < 3; ++b)
                cs += R(a, b);
    }
    double ns = elapsed_ns(t0);
    report("rotz_full", ns / n, cs);
}

KDL_BENCH_NOINLINE void bench_fk_pos_7dof()
{
    const long n = 2000000;
    Chain chain = make_chain();
    ChainFkSolverPos_recursive solver(chain);
    JntArray q(7);
    for (unsigned i = 0; i < 7; ++i)
        q(i) = 0.1 * (i + 1);
    Frame out;
    double cs = 0;
    auto t0 = Clock::now();
    for (long i = 0; i < n; ++i) {
        q(0) = 1e-6 * i;
        solver.JntToCart(q, out);
        cs += sum(out);
    }
    double ns = elapsed_ns(t0);
    report("fk_pos_7dof", ns / n, cs);
}

KDL_BENCH_NOINLINE void bench_fk_vel_7dof()
{
    const long n = 1000000;
    Chain chain = make_chain();
    ChainFkSolverVel_recursive solver(chain);
    JntArrayVel q(7);
    for (unsigned i = 0; i < 7; ++i) {
        q.q(i) = 0.1 * (i + 1);
        q.qdot(i) = 0.05 * (i + 1);
    }
    FrameVel out;
    double cs = 0;
    auto t0 = Clock::now();
    for (long i = 0; i < n; ++i) {
        q.q(0) = 1e-6 * i;
        solver.JntToCart(q, out);
        cs += sum(out.GetFrame());
        cs += out.GetTwist().vel.x() + out.GetTwist().rot.z();
    }
    double ns = elapsed_ns(t0);
    report("fk_vel_7dof", ns / n, cs);
}

} // namespace

int main()
{
    bench_latency_frame_mul();
    bench_throughput_frame_mul();
    bench_vector_add_chain();
    bench_rotz_full();
    bench_fk_pos_7dof();
    bench_fk_vel_7dof();
    return 0;
}

#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DOCKER_DIR="${SCRIPT_DIR}"
OUTPUT_DIR="${SCRIPT_DIR}/packages"

mkdir -p "${OUTPUT_DIR}"

cd "${DOCKER_DIR}"
docker build . --output "type=local,dest=./temp/"
cp ./temp/workspace/build_amd64/*.deb ${OUTPUT_DIR}/
cp ./temp/workspace/build_arm64/*.deb ${OUTPUT_DIR}/

rm -rf ./temp

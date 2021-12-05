#!/usr/bin/env bash

DEFAULT_BUILD_DIR="build"
DEFAULT_DIST_DIR="dist"
DEFAULT_DATA_DIR="data"
BUILD_DIR="${DEFAULT_BUILD_DIR}"
DIST_DIR="${DEFAULT_DIST_DIR}"
DATA_DIR="${DEFAULT_DATA_DIR}"
SCRIPT_NAME=$(basename $0)
PROJECT_DIRNAME=$(dirname $(readlink -f $0))
USAGE="Usage: ${SCRIPT_NAME} [options]...

Options:
  -h, --help                  Print this message
  -b, --build-dir  BUILD_DIR  Build days in BUILD_DIR instead of default '${DEFAULT_BUILD_DIR}'
  -d, --dist-dir   DIST_DIR   Move executables to  DIST_DIR instead of default '${DEFAULT_DIST_DIR}'
  --all                       Build all days
"

function build_day1() {
  mkdir -p "${BUILD_DIR}"
  cmake -S "${PROJECT_DIRNAME}" -B "${BUILD_DIR}" -DBUILD_DAY_1=ON -DENABLE_CLANG_TIDY=ON
  cmake --build "${BUILD_DIR}" -j

  # Copy executable to dist folder
  mkdir -p "${DIST_DIR}"
  cp "${BUILD_DIR}/src/day1/day1" "${DIST_DIR}/"
  # Copy data to dist folder
  cp "${DATA_DIR}/day1.dat" "${DIST_DIR}/"
}

function build_day2() {
  mkdir -p "${BUILD_DIR}"
  cmake -S "${PROJECT_DIRNAME}" -B "${BUILD_DIR}" -DBUILD_DAY_2=ON -DENABLE_CLANG_TIDY=ON
  cmake --build "${BUILD_DIR}" -j

  mkdir -p "${DIST_DIR}"
  cp "${BUILD_DIR}/src/day2/day2" "${DIST_DIR}/"
  # Copy data to dist folder
  cp "${DATA_DIR}/day2.dat" "${DIST_DIR}/"
}

function build_all() {
  build_day1
  build_day2
}

# Parse the available options
PARSED_OPTIONS=$(getopt -n "$0" -o h: --long "all,help,build:" -- "$@")
eval set -- "${PARSED_OPTIONS}"

# Handle all the options
while true;
do
  case "$1" in
    --help|-h)
      echo "${USAGE}"
      shift;;
    --build-dir|-b)
      if [ -n "$2" ];
      then
        BUILD_DIR="$2"
        echo "Using BUILD_DIR='${BUILD_DIR}'"
      fi
      shift 2;;
    --dist-dir|-d)
      if [ -n "$2" ];
      then
        DIST_DIR="$2"
        echo "Using DIST_DIR='${DIST_DIR}'"
      fi
      shift 2;;
    --all)
      build_all $BUILD_DIR
      shift;;
    --)
      shift
      break;;
  esac
done

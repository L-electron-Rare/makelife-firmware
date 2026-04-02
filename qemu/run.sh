#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"

TARGET="${1:?Usage: qemu/run.sh <target> [--gdb] [--timeout N]}"
GDB_MODE=false
TIMEOUT=60
FIRMWARE="${REPO_DIR}/build/${TARGET}/app/firmware"

shift
while [[ $# -gt 0 ]]; do
    case "$1" in
        --gdb) GDB_MODE=true ;;
        --timeout) TIMEOUT="$2"; shift ;;
        --firmware) FIRMWARE="$2"; shift ;;
    esac
    shift
done

if [ ! -f "$FIRMWARE" ]; then
    echo "ERROR: Firmware not found: $FIRMWARE"
    exit 1
fi

TARGET_CFG="${SCRIPT_DIR}/targets/${TARGET}.sh"
if [ ! -f "$TARGET_CFG" ]; then
    echo "ERROR: No QEMU config for target '$TARGET'"
    exit 1
fi

source "$TARGET_CFG"

if $GDB_MODE; then
    case "$RESULT_METHOD" in
        exit_code) QEMU_ARGS=("-g" "1234" "${QEMU_ARGS[@]}") ;;
        *) QEMU_ARGS+=("-S" "-gdb" "tcp::1234") ;;
    esac
    echo "GDB server on :1234"
fi

echo "=== QEMU: ${TARGET} (${RESULT_METHOD}) ==="

case "$RESULT_METHOD" in
    uart|semihosting)
        timeout "${TIMEOUT}" ${QEMU_CMD} "${QEMU_ARGS[@]}" 2>&1 | python3 "${SCRIPT_DIR}/parse_unity.py"
        ;;
    exit_code)
        timeout "${TIMEOUT}" ${QEMU_CMD} "${QEMU_ARGS[@]}"
        ;;
esac

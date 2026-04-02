#!/usr/bin/env python3
"""Parse Unity test output from stdin, exit with appropriate code."""
import sys
import re

passed = 0
failed = 0
ignored = 0

for line in sys.stdin:
    line = line.rstrip()
    print(line, flush=True)
    m = re.match(r"(\d+) Tests (\d+) Failures (\d+) Ignored", line)
    if m:
        total = int(m.group(1))
        failed = int(m.group(2))
        ignored = int(m.group(3))
        passed = total - failed - ignored

if failed > 0:
    print(f"\n--- QEMU RESULT: FAIL ({failed} failures) ---", flush=True)
    sys.exit(1)
elif passed > 0:
    print(f"\n--- QEMU RESULT: PASS ({passed} passed) ---", flush=True)
    sys.exit(0)
else:
    print("\n--- QEMU RESULT: NO TESTS FOUND ---", flush=True)
    sys.exit(2)

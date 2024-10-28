#!/usr/bin/env python3
#
# Testing tool for the Extraterrestrial Exploration problem
#
# Usage:
#
#   python3 testing_tool.py -f inputfile <program invocation>
#
#
# Use the -f parameter to specify the input file, e.g. 1.in.
# Format of the input file:
# - One line with an integer n, the number of bottles.
# - One line with n integers, the values of the bottles.
# e.g.:
# 4
# 1 2 3 3
#
#
# You can compile and run your solution as follows:

# C++:
#   g++ solution.cpp
#   python3 testing_tool.py -f 1.in ./a.out

# Python3
#   python3 testing_tool.py -f 1.in python3 ./solution.py

# Java
#   javac solution.java
#   python3 testing_tool.py -f 1.in java solution

# Kotlin
#   kotlinc solution.kt
#   python3 testing_tool.py -f 1.in kotlin solutionKt


# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it.
#
# The tool attempts to detect and report common errors, but it is not an exhaustive test.
# It is not guaranteed that a program that passes this testing tool will be accepted.


import argparse
import subprocess
import traceback

max_queries = 50

parser = argparse.ArgumentParser(description="Testing tool for problem Extraterrestrial Exploration.")
parser.add_argument(
    "-f",
    dest="inputfile",
    metavar="inputfile",
    default=None,
    type=argparse.FileType("r"),
    required=True,
    help="The input file to use.",
)
parser.add_argument("program", nargs="+", help="Invocation of your solution")

args = parser.parse_args()

with (
    args.inputfile as f,
    subprocess.Popen(
        " ".join(args.program),
        shell=True,
        stdout=subprocess.PIPE,
        stdin=subprocess.PIPE,
        universal_newlines=True,
    ) as p,
):
    def write(line):
        assert p.poll() is None, "Program terminated early"
        print(f"Write: {line}", flush=True)
        p.stdin.write(f"{line}\n")
        p.stdin.flush()


    def read():
        assert p.poll() is None, "Program terminated early"
        line = p.stdout.readline().strip()
        assert line != "", "Read empty line or closed output pipe"
        print(f"Read: {line}", flush=True)
        return line


    # Parse input
    lines = f.readlines()
    assert len(lines) == 2

    n = int(lines[0])
    a = list(map(int, lines[1].split()))

    # Calculate the optimal value for the given input, in O(n³) time
    optval = max(
        abs(a[x] - a[y]) ** 0.5 + abs(a[y] - a[z]) ** 0.5 + abs(a[z] - a[x]) ** 0.5
        for x in range(n) for y in range(n) for z in range(n)
    )

    # Simulate interaction
    try:
        write(n)

        queries = 0
        while True:
            op, *rest = read().split()
            if op == "?":
                queries += 1
                i = int(rest[0])
                assert 1 <= i <= n, f"Your query ({i}) is out-of-bounds (i must be between 1 and {n})."
                write(a[i - 1])
            elif op == "!":
                x, y, z = map(int, rest)
                assert len({x,y,z}) == 3, f"Output values of ({x},{y},{z}) are not distinct."
                val = abs(a[x - 1] - a[y - 1]) ** 0.5 + abs(a[y - 1] - a[z - 1]) ** 0.5 + abs(
                    a[z - 1] - a[x - 1]) ** 0.5
                assert abs(val - optval) < 1e-6, f"Your selection has a value of {val}, but the optimal value is {optval}."
                break
            else:
                assert False, f"Operation '{op}' is not one of '?' or '!'."

        assert p.stdout.readline() == "", "Your submission printed extra data after finding a solution."
        assert p.wait() == 0, "Your submission did not exit cleanly after finishing."

        assert queries <= max_queries, f"Used {queries} queries, which is more than the allowed {max_queries}."

        print(f"\nSuccess.\nQueries used: {queries}\n")

    except AssertionError as e:
        print()
        print(f"Error: {e}")
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()

    except Exception as e:
        print()
        traceback.print_exc()
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()
        raise e

    finally:
        print(f"Exit code: {p.wait()}\n", flush=True)

# Import necessary library
import sys

# Predefined Fibonacci numbers
Fib = [
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 
    4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 
    832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 
    63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170
]
nFib = 46  # Number of predefined Fibonacci numbers

def find_base(n):
    """
    Find the base representation of the number n in terms of Fibonacci numbers.
    """
    for b in range(1, 1000000001):  # Limit for b
        for i in range(2, nFib):  # Skip the first two Fibonacci numbers
            if n < b * Fib[i]:
                break  # No valid (a, b) pair found for this i
            
            # Calculate 'a' and check the conditions
            a = (n - b * Fib[i]) // Fib[i - 1]
            if 0 < a <= b and n == a * Fib[i - 1] + b * Fib[i]:
                return a, b  # Found the valid pair (a, b)


runs = int(input())  # Number of runs
for _ in range(runs):
    n = int(input())  # Number to be decomposed
    a, b = find_base(n)
    print(a, b)


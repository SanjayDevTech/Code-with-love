# Tail-recursive variant of the well-known recursive
# Fibonacci Sequence algorithm.
# fib_aux does not recur if and only if n equals 1.
# Thus, its code is interpreted / compiled as a loop instead
# of a recursion.
def fib_aux(n, acc1, acc2):
    if n == 1: return acc1
    return fib_aux(n - 1, acc2, acc1 + acc2)

# We call the auxiliary tail-recursive algorithm with
# our given initial values.
def fib(n): return fib_aux(n, 1, 1)

print(fib(10))

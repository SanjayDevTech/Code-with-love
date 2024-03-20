def fib(n):
    if n <= 1:
        return n
    else:
        return (fib(n - 1) + fib(n - 2))


n = 5

if n <= 0:
    print("Plese enter a positive integer")
else:
    print("Fibonacci sequence:")
    for i in range(n):
        print(fib(i))

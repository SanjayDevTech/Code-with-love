def factorial(n):
    if n <= 0:
        return 1
    else:
        return n * factorial(n - 1)


n = 5

if n < 0:
    print("Plese enter a valid integer")
else:
    print(str(n) + "! = " + str(factorial(n)))

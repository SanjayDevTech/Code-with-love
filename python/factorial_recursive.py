def fact(n):
    if n == 0:
        return 1
    else:
        return n * fact(n - 1)

num = 13
print(f"{num}! = {fact(num)}")

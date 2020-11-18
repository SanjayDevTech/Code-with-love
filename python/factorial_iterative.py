def fact(n):
    res = 1

    for i in range(2, n):
        res *= i

    return res

num = 13
print(f"{num}! = {fact(num)}")

# An armstrong number is one whose sum of cube of digits is equal to number itself

n = input("enter the no you wanna check as armstrong")
ls = list(n)
tot = sum([int(x)**3 for x in ls])
if tot==int(n):
    print("armstrong number")
else:
    print("not armstrong number")

# Python Function for nth Fibonacci number using recursion 
 
def Fibonacci(n):
    if n<=0:
        print("Incorrect Input !!!")
    # As First Fibonacci number is 0
    elif n==1:
        return 0
    # As Second Fibonacci number is 1
    elif n==2:
        return 1
    else:
        return Fibonacci(n-1)+Fibonacci(n-2)
 
n=int(input()) 
print(Fibonacci(n))
 

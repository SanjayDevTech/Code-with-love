n = int(input())
prime = []
for i in range(n+1):
    prime.append(1)
i = 2
while(i<=n):
    if(prime[i]==1):
        j = i*2
        while(j<=n):
            prime[j]=0
            j+=i
    i+=1
print(prime)



#1 TO CHECK A NUMBER IS PRIME OR NOT  -----------

#SieveOfEratosthenes Method
#Time complexity : O(n*log(log(n)))

def prime_universal(inp):

	# Create a boolean array "list_of_prime[0..n]" and initialize 
    #  all entries it as true. A value in prime[i] will 
    # finally be false if i is Not a prime, else true. 

	list_of_number=[True for _ in range(inp+1)]
	list_of_number[0]=list_of_number[1]=False

	for i in range(2,int(pow(inp+1,1/2))+1):
	    c=i
	    j=i*2
	    while j<inp+1:

	    	# if j is NOT a prime number then update the index of j as False
	        list_of_number[j]=False
	        j+=c

	# return the list of numbers
	return list_of_number       


# Input time
print("Enter number to check ")
inp = int(input())
value = prime_universal(inp)
if value[inp]:
	print("Yes it is Prime")
else:
	print("No it's not")	

# --------------------------------------------------------- #

#2 TO PRINT PRIME NUMBER UPTO A GIVEN NUMBER
# BY USING SAME FUNCTION DEFINE ABOVE


print("Enter number upto which you want to print")
inp = int(input())
value = prime_universal(inp)

#printing of prime number
for num in range(inp+1):
	if value[num]:
		print(num,end=" ")

#by :- kishanpython	


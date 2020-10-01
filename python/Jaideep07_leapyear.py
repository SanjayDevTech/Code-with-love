# Python program to check leap year or not
# Conditions for a year to be leap year
# 1. It must be a multiple of 400.
# 2. It must be a multiple of 4 and not a multiple of 100.

def isLeapYear(year):
    if (year % 4) == 0:
        if (year % 100) == 0:
            if (year % 400) == 0:
                return True
            else:
                return False
        else:
             return True
    else:
        return False
 
# Driver Code 
year = 2020
if(isLeapYear(year)):
    print("Leap Year")
else:
    print("Not a Leap Year")
     
#output: Leap Year     

def isLeapyear(year):
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

print("Check if the year is a leap year or not.")
year = int(input("Enter the year: "))
if isLeapyear(year):
    print(year, "is a leap year")
else:
    print(year, "is not a leap year")

# python program to find if a given year is leap year or not

Algorithm:
    1. If a year is a multiple of 4, 100 and 400 -> it is a leap year
    2. If a year is a multiple of 4, 100 but not 400 -> it is not a leap year
    3. If a year is a multiple of 4 but not -> it is a leap year
    4. If a year is not a multiple of 4-> it is not  leap year

print("Enter the year")
year= int(input())

if(year%4==0):
    if(year%100 == 0):
        if(year%400 == 0):
            print(year + " is a leap year")
        else:
            print(year + " is not a leap year")
    else:
        print(year + " is a leap year")
else:
    print(year + " is not a leap year")
    

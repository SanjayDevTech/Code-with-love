'''
program to check that the year is a leap year or not

author : @sb19
'''

def isleapYear(year):
    if((year%4==0 and year%100!=0) or year%400==0):
        return True
    elif(year%100==0):
        return False
    else:
        return False

print(isleapYear(2004))
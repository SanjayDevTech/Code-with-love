def leapornot(year):
 if year%4==0 and year%100 !=0:
  return(True)
 else:
  return(False)
year = int(input("Enter a year: "))
x=leapornot(year)
if x==True:
 print(year," is a leap year")
else:
 print(year,"is not a leap year")
choice=str(input("Want to enter again?y/n"))
while(choice!= 'n'):
 year = int(input("Enter a year: "))
 x=leapornot(year)
 if x==True:
  print(year," is a leap year")
 else:
  print(year,"is not a leap year")
 choice=str(input("Want to enter again?y/n"))

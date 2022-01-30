void main() { 
   /*A leap year is exactly divisible by 4 except for century years (years ending with 00). 
  The century year is a leap year only if it is perfectly divisible by 400.*/
  var year = 2020;
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        print(" $year, is  a leap year");
      } else {
        print(" $year, is not a leap year");
      }
    } else {
      print(" $year, is  a leap year");
    }
  } else {
    print(" $year, is not a leap year");
  }
}

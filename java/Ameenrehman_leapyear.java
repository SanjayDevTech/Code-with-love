// Java program to check 
// for a leap year 
	
class Test 
{ 
	static boolean checkYear(int year) 
	{ 
		// If a year is multiple of 400, 
		// then it is a leap year 
		if (year % 400 == 0) 
			return true; 
	
		// Else If a year is muliplt of 100, 
		// then it is not a leap year 
		if (year % 100 == 0) 
			return false; 
	
		// Else If a year is muliplt of 4, 
		// then it is a leap year 
		if (year % 4 == 0) 
			return true; 
		return false; 
	} 
		
	// Driver method 
	public static void main(String[] args) 
	{    int year;
		 System.out.println("Enter an Year :: ");
         Scanner sc = new Scanner(System.in);
         year = sc.nextInt();
		 System.out.println( checkYear(year)? "Leap Year" : 
						"Not a Leap Year" ); 
	} 
} 

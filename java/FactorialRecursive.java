import java.util.InputMismatchException;
import java.util.Scanner;

public class FactorialRecursive {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int loop = 1;
        int scannedNumber;
        
        while(loop == 1){                                
            try{
                System.out.println("\nKey a positive number, please:");
                scannedNumber = scanner.nextInt();

                if(scannedNumber < 0){
                    System.out.println("\nFactorial can´t be negative");
                } else if(scannedNumber == 0 ){
                    System.out.println("\nFactorial of 0 is: 1");
                } else {
                    System.out.println("\nFactorial of " + scannedNumber + " is: " + factorial(scannedNumber));
                }

                System.out.println("\nCalculate another Factorial? \n\t[1] Yes / [0] NO");
                loop = scanner.nextInt();
            } catch (InputMismatchException ex){
                System.out.println("\n" + ex + "\nProgram expected number, but no characters");
                loop = 0;                
            }                     
        }
        scanner.close();
    }

    private static int factorial(int number) {
        if(number == 1){
            return 1;
        } 
        return factorial(number - 1) * number;
    }
}

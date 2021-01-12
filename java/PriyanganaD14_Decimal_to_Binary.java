import java.util.Scanner;

/**
 * PriyanganaD14_Decimal_to_Binary
 */
public class PriyanganaD14_Decimal_to_Binary {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the decimal value : ");
        int n=sc.nextInt();

        System.out.println("Equivalent Binary value : "+deciToBinary(n));

        sc.close();
    }

    public static int deciToBinary(int n){
        int bNumber=0;
        int c=0;

        while(n!=0){
            int rem =n%2;
            double d=Math.pow(10, c);
            bNumber+=rem*d;
            n/=2;
            c++;

        }

        return bNumber;
    }
}
import java.util.Scanner;

/**
 * PriyanganaD14_leapyear
 */
public class PriyanganaD14_leapyear {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter any year as a input : ");
        int yr=sc.nextInt();

        if(yr%400==0 ||( yr%4==0 && yr%100!=0)){
            System.out.println(yr+" is a leap year");
        }
        else{
            System.out.println(yr+" is not a leap year");
        }
        sc.close();
    }
}
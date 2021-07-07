import java.util.Scanner;

public class Anagram {

    /**   REARRANGING the terms  **/
    public static void rearrange(String num1,String num2)

    {
        if (num2.length() == 1)
            System.out.println(num2);

        else if (num2.length() == 2) {
            System.out.println(num1 + num2);
            num2 = num2.charAt(1) + "" + num2.charAt(0);
            System.out.println(num1 + num2);
        } else {
            num1 += num2.substring(0, 1);
            num2 = num2.substring(1);
            for (int i = 1; i <= num2.length()+1; i++) {

                rearrange(num1, num2);
                String c = num2.substring(num2.length() - 1);
                num2 = num1.substring(num1.length() - 1) + num2.substring(0, num2.length() - 1);
                num1 = num1.substring(0, num1.length() - 1) + c;
            }
        }
    }

    /**   Taking input   **/
        public static String input()
        {
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter a String:- ");
            String str=sc.next();
            return str;
        }
public static void main(String[] args)
    {
        String n=input();
        System.out.println("The Anagrams are:- ");
        rearrange("",n);
    }
}

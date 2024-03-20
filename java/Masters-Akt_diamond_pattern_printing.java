import java.util.Scanner;
public class DiamondInSingleLoop
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter number of terms to print a Diamond: ");
        int t = s.nextInt();
        int ct = t;
        int counter = 1;
        for (int i = 1; i <= (2 * t - 1) * (t + 1); i++)
        {
            if (counter <= ct)
            {
                System.out.print(" ");
                counter++;
            }else
            {
                System.out.print("* ");
            }
            if (i % (t + 1) == 0)
            {
                System.out.println();
                counter = 1;
                if(i < t *(t + 1))
                {  
                    ct--;
                }
                else
                {
                    ct++;
                }
            }
        }
        } 
}

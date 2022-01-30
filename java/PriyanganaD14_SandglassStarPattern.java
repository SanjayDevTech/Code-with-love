import java.util.Scanner;

/**
 * PriyanganaD14_SandglassStarPattern
 */
public class PriyanganaD14_SandglassStarPattern {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of rows that you want to print : ");
        int n=sc.nextInt();
        pattern(n); 

        sc.close();

    }

    public static void pattern(int n){
        int i, j, k; 
      
        // for loop for printing 
        // upper half 
        for (i = 1; i <= n; i++) { 
      
            // printing i spaces at 
            // the beginning of each row 
            for (k = 1; k < i; k++)  
                System.out.print(" "); 
              
            // printing i to rows value 
            // at the end of each row 
            for (j = i; j <= n; j++)  
                System.out.print("*"+ " ");  
      
            System.out.println(); 
        } 
      
        // for loop for printing lower half 
        for (i = n - 1; i >= 1; i--)  
        { 
            // printing i spaces at the 
            // beginning of each row 
            for (k = 1; k < i; k++)  
                System.out.print(" "); 
              
            // printing i to rows value 
            // at the end of each row 
            for (j = i; j <= n; j++)  
                System.out.print("*" + " ");  
      
            System.out.println(); 
        } 
    
    }

}
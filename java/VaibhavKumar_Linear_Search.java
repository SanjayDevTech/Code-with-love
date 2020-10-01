import java.util.ArrayList;
import java.util.Scanner;

public class linear_search{

    public static int search(ArrayList<String> myList, String searchTerm){
        //the guts of the linear search
        for(int i = 0; i < myList.size(); i++)
        {
            if(myList.get(i).equals(searchTerm))
            {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args){
    
        ArrayList<String> myList = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);
        String sTemp;

        System.out.println("Enter something to be put in a list, or enter 'done' to move on: ");
        while(true)
        {
            sTemp = sc.next();
            if(sTemp.equals("done"))
            {
                break;
            }
            myList.add(sTemp);
            }

        System.out.println("\nYour list looks like: ");
        for(int i = 0; i < myList.size(); i++)
        {
            if(i == myList.size() - 1)
            {
                System.out.println(myList.get(i));
            }
            else
            {
                System.out.print(myList.get(i) + ", ");
            }
        }
        System.out.println("\nWhat would you like to search for: ");  
        
        int pos = search(myList, sc.next());
        if(pos == -1)
        {
            System.out.println("\nYour search term could not be found!");
        }
        else
        {
            pos++;
            System.out.println("\nYour search term was found at position " + pos + "!");
        }

    }

}

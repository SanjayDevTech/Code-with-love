import java.util.Scanner;

/**
 * PriyanganaD14_TernarySearch
 */
public class PriyanganaD14_TernarySearch {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the length of the array : ");
        int n = sc.nextInt();

        System.out.println("Enter the array : ");
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            arr[i] = x;
        }

        System.out.println("Enter the searching element : ");
        int k = sc.nextInt();

        System.out.println("Index of searching element : " + ternarySearch(arr, n, k));

        sc.close();
    }

    public static int ternarySearch(int arr[], int n, int k) {

        int low = 0, high = n - 1;

        while (low <= high) {
            // find mid1 and mid2
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            // check if searching element is present at any mid
            if (arr[mid1] == k) {
                return mid1;
            }
            if (arr[mid2] == k) {
                return mid2;
            }

            // since searching element is not present at mid,check in which region it is
            // present
            // then repeate the searching operation in that region

            if (k < arr[mid1]) {
                // the searching element in lies between low and mid1.
                high = mid1 - 1;
            } else if (k > arr[mid2]) {
                // the searching element lies in between mid2 and high.
                low = mid2 + 1;
            } else {
                // the searching element lies between mid1 and mid2.
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }

        // the searching element is not found.
        return -1;

    }

}
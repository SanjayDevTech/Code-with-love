Find the Kth largest element from the given array using PriorityQueue class?


package Collections.Assignment1;

import java.util.Comparator;
import java.util.PriorityQueue;

public class Question2 {

    public static class ReverseIntComparator implements Comparator<Integer> {
        @Override
        public int compare(Integer x, Integer y) {
            if (x < y) {
                return 1;
            }
            if (x > y) {
                return -1;
            }
            return 0;
        }
    }

    public static void main(String[] args) {
        int[] input = {10, 30, 50, 67, 34, 68};
        int k = 3;
        System.out.println(getTheKthLargestEle(input, k));

    }

    private static int getTheKthLargestEle(int[] input, int k) {
        Comparator<Integer> comparator = new ReverseIntComparator();
        PriorityQueue<Integer> integerPriorityQueue = new PriorityQueue<Integer>(10, comparator);
        if (input.length < k) {
            return -1;
        }
        int kthElement = 0;
        for (int ele : input) {
            integerPriorityQueue.add(ele);
        }
        for (int i = 0; i<k ; i++) {
            kthElement = integerPriorityQueue.poll();
        }
        return kthElement;
    }
}
write a java program to find the number duplicate  using HashSet?
package Collections.Assignment1;

import java.io.BufferedReader;
import java.util.HashSet;
import java.util.Scanner;


public class Question1 {
    private static int countNumberOfDuplicates(String[] inputSet) {
        int countDuplicates = 0;
        HashSet<String> stringHashSet = new HashSet<>();
        for (String inputString : inputSet) {
            if (!stringHashSet.add(inputString)) {
                countDuplicates++;
            }
        }
        return countDuplicates;
    }

    public static void main(String[] args) {
        String[] inputSet =  {"raudra", "ravi", "java", "ravula", "ravi", "ravula"};
        System.out.println(countNumberOfDuplicates(inputSet));
    }
}
public class SelectionSort {

    public static void sort(Comparable[] a){
        //Sort a[] into increasing order.
        int n = a.length;
        for (int i = 0; i < n; i++){
            //Exchange a[i] with smallest entry in a[i],....,a[n-1]
            int min = i;   // index of smallest entry
            for(int j = i + 1; j < n; j ++){
                if(less(a[j], a[min]))
                    { min = j;}
            }
            exchange(a, i, min);
        }
    }
    private static boolean less(Comparable v, Comparable w){
        return v.compareTo(w) < 0;
    }
    private static void exchange(Comparable[]a, int i, int j){
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    private static void show(Comparable [] a){
        for (int i = 0; i < a.length; i++){
            System.out.print(a[i] + " ");
           // System.out.println();
        }
    }

    public static boolean isSorted(Comparable[] a){
        //Test whether the array entries are in order
        for(int i = 1; i < a.length; i++){
            if(less(a[i],  a[i -1])) return false;
        }
        return true;
    }

    public static void main(String [] args){
        Integer [] a = new Integer [] {1, 5, 22, 7, 40, 2};
        sort(a);
        assert isSorted(a);
        show(a);
    }

}
class BinaryPyramid {
    public static void main(String[] args) {
        for(int i = 4; i >= 0; i--) {
            for(int j = i; j > 0; j--) {
                System.out.print("  ");
            }
            for(int j = (4-i); j > 1; j--) {
                if(j % 2 == 0) 
                    System.out.print("0 ");
                else
                    System.out.print("1 ");
            }
            for(int j = 1; j < (5-i); j++) {
                if(j % 2 == 0) 
                    System.out.print("0 ");
                else
                    System.out.print("1 ");
            }
            System.out.println();
        }
    }
}
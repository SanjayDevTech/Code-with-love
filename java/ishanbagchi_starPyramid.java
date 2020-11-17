class StarPyramid {
    public static void main(String[] args) {
        for(int i = 4; i >= 0; i--) {
            for(int j = i; j > 0; j--) {
                System.out.print(" ");
            }
            for(int k = (5-i); k > 0; k--) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
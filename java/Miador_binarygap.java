public class Miador_binarygap {

    /**
         A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
         For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
         The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
         The number 20 has binary representation 10100 and contains one binary gap of length 1.
         The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

        @author miador
        @param N takes an integer
        @return the length of gap
     */

    public int findGap( int N ) {
        String[] split = Integer.toBinaryString( N ).substring( 0, Integer.toBinaryString( N ).lastIndexOf( '1' ) ).split( "1" );

        int a = 0;
        int b = 0;
        while ( b < split.length ) {
            a = Math.max( a, split[ b ].length() );
            b++;
        }
        return a;
    }

    public static void main( String[] args ) {
        Miador_binarygap s = new Miador_binarygap();
        System.out.println( s.findGap( 1041 ) ); //Type the number you want to calculate here.
    }

}
import java.math.*;
import java.util.*;
import java.io.*;

public class Main  {
    
    public static BigInteger sqr(BigInteger x) {
        BigInteger l = BigInteger.valueOf(1);
        BigInteger r = x;
        while (l.compareTo(r) < 0) {
            BigInteger mid = l.add(r).divide(BigInteger.valueOf(2));
            if (mid.multiply(mid).compareTo(x) > 0) r = mid;
            else l = mid.add(BigInteger.valueOf(1));
        }
        return l.subtract(BigInteger.valueOf(1));
    }
    
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        BigInteger n;
        while (cin.hasNext()) {
            n = cin.nextBigInteger();
            int i;
            for (i = 0; i <= 6; i++) {
                if (n.compareTo(BigInteger.valueOf(1)) == 0) break;
                n = sqr(n);
            //    System.out.println(n);
            }
            if (i > 5) System.out.println("TAT");
            else System.out.println(i);
        }
    }
}

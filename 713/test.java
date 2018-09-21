
/**
 * You shouldn't use cpp for this problem. You would need a biginteger, and 
 * stringbuffer is so useful to just revserse a string. 
 */
import java.util.Scanner;
import java.math.BigInteger;

public class test {
	public static void main(String[] args) {
		int n;
		BigInteger num1, num2, num3, num4;

		StringBuffer sb;
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			// get first reversed num
			sb = new StringBuffer(sc.next());
			sb = sb.reverse();
			num1 = new BigInteger(sb.toString());

			sb = new StringBuffer(sc.next());
			sb = sb.reverse();
			num2 = new BigInteger(sb.toString());

			num3 = num1.add(num2);

			sb = new StringBuffer(num3.toString());
			sb = sb.reverse();
			num4 = new BigInteger(sb.toString());
			System.out.println(num4);
		}

		sc.close();
	}
}
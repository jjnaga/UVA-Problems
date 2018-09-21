
/**
 * I think this is easy, but I didn't take single math class so idk.
 * 
 * Post: Wow, figuring out line 20 is something else.. 
 */
import java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int num1;
		BigInteger num2, num3;
		java.util.Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			num1 = Integer.parseInt(sc.next());
			num2 = new BigInteger(sc.next());
			num3 = new BigInteger("0");
			for (int i = 1; i <= num1; i++) {
				num3 = num3.add((num2.pow(i)).multiply(BigInteger.valueOf(i)));
			}
			System.out.println(num3);
		}
	}
}
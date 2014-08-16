/* Filename: UVa369.java
 * Author: Mushiyo
 */

import java.util.Scanner;
import java.math.BigInteger;

public class UVa369 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (input.hasNext()) {
			int N = new BigInteger(input.next()).intValue();
			int M = new BigInteger(input.next()).intValue();
			
			if(N == 0 && M == 0){
				break;
			}
			
			long C = combination(N, M);
			
			System.out.printf("%d things taken %d at a time is %d exactly.\n", N, M, C);
		}
	}
	
	private static long combination(int n, int m) {
		long c = 1;

		for (int i = Math.max(m, n - m) + 1, j = 1; i <= n; ++i, ++j) {
			c = (c * i) / j;
		}

		return c;
	}
}

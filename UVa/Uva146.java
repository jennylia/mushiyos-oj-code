/* Filename: Uva146.java
 * Author: Mushiyo
 */

import java.util.Scanner;

public class Uva146 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (input.hasNext()) {
			char[] code = input.nextLine().toCharArray();

			if (code[0] == '#') {
				break;
			}

			if (nextPermutation(code)) {
				System.out.println(code);
			} else {
				System.out.println("No Successor");
			}
		}
	}

	private static boolean nextPermutation(char[] element) {
		int i = element.length - 2;

		// find the first decreasing point
		while (i >= 0 && element[i] >= element[i + 1]) {
			--i;
		}

		if (i < 0) {
			for (int j = 0, k = element.length - 1; j < k; ++j, --k) {
				char tmp = element[j];
				element[j] = element[k];
				element[k] = tmp;
			}

			return false;
		}

		int j = element.length - 1;
		while (element[i] >= element[j]) {
			--j;
		}

		char tmp = element[i];
		element[i] = element[j];
		element[j] = tmp;

		int r = element.length - 1;
		int s = i + 1;

		while (r > s) {
			tmp = element[r];
			element[r] = element[s];
			element[s] = tmp;

			--r;
			++s;
		}

		return true;
	}
}

package ORIGINAL;

import java.util.*;

public class d614 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int T = Integer.parseInt(input.nextLine());
		//�p�G��nextInt��A�h���U�Ӫ�nextLine()�|���Ŧr��(�o�Odebug�ɬݨ쪺�A�ڤ��M��������|�o��)�A�ҥH�o�̱ĥγo�ؤ覡
		while (T > 0) {
			StringTokenizer arithmeticExpression = new StringTokenizer(
					input.nextLine(), "+");

			long sum = 0;

			while (arithmeticExpression.hasMoreTokens()) {
				String num = arithmeticExpression.nextToken().trim();
				sum += Long.parseLong(num);
			}

			System.out.println(sum);

			--T;
		}
	}

}

import java.util.Scanner;
import java.math.BigInteger;

public class d411 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while (input.hasNext()) {
			String M = input.next();
			BigInteger bigNum = new BigInteger(M);
			int N = input.nextInt();

			if (bigNum.mod(new BigInteger("2").pow(N)).equals(BigInteger.ZERO)) {
				System.out.println("YA!!�ש��X" + M + "�i�Q2��" + N + "���㰣�F!!");
			}
			else {
				System.out.println("�i�c!!��F�o��[" + M + "���M�L�k�Q2��" + N + "���㰣");
			}
		}
	}
}

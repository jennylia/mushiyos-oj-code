import java.util.Scanner;

public class u10970 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNext()){
			int M = input.nextInt();
			int N = input.nextInt();
			
			System.out.println(M * N - 1);
		}
	}
}

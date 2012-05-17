import java.util.Scanner;

public class d010 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNext()){
			int N = input.nextInt();
			int S = sumOfDivisors(N);
			
			if(S > N){
				System.out.println("�ռ�");
			}
			else if(S < N){
				System.out.println("����");
			}
			else{
				System.out.println("������");
			}
		}
	}
	
	public static int sumOfDivisors(int N){
		int divisorSum = 0;
		
		for(int i = 1; i < N; ++i){
			if(N % i == 0){
				divisorSum += i;
			}
		}
		
		return divisorSum;
	}

}

import java.util.Scanner;

public class Timus1349 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNext()){
			int n = input.nextInt();
			
			if(n == 1){
				System.out.println("1 2 3");
			}
			else if(n == 2){
				System.out.println("3 4 5");
			}
			else{
				System.out.println("-1");
			}
		}
	}

}

import java.util.Scanner;

public class d155 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNext()){
			String purple = input.next();
			String dream = input.next();
			int purpleWin = 0;
			int dreamWin = 0;
			
			if(purple.equals("Game")){
				if(dreamWin > purpleWin){
					System.out.println("�d�G���w���_���o��");
				}
				else{
					System.out.println("�ä����ܸ�" );
				}
				break;
			}
			
			if(purple.equals("Paper")){
				if(dream.equals("Stone")){
					++purpleWin;
					System.out.println("�����");
				}
				else if(dream.equals("Scissors")){
					++dreamWin;
					System.out.println("�F�����");
				}
			}
			else if(purple.equals("Scissors")){
				if(dream.equals("Stone")){
					++dreamWin;
					System.out.println("�F�����");
				}
				else if(dream.equals("Paper")){
					++purpleWin;
					System.out.println("�����");
				}
			}
			else{//purple == stone
				if(dream.equals("Paper")){
					++dreamWin;
					System.out.println("�F�����");
				}
				else if(dream.equals("Scissors")){
					++purpleWin;
					System.out.println("�����");
				}
			}
			
		}
	}

}

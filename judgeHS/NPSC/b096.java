package NPSC;

import java.util.Scanner;

public class b096 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNext()){
			int playerLife = input.nextInt();
			int playerAtk = input.nextInt();
			int playerDef = input.nextInt();
			int devilLife = input.nextInt();
			int devilAtk = input.nextInt();
			int devilDef = input.nextInt();
			
			/*�]���D�ؤ������o�ǼƦr����1��10000�A�ҥH�u�n�䤤�@�ӼƦr��0�A
			 * �N�N����@�w�O�{�����������@��A�ҥH�u�ˬd�@�ӴN�n
			 */
			if(playerLife == 0){
				break;
			}
			
			int playerEffectAtk = playerAtk - devilDef;
			int devilEffectAtk = devilAtk - playerDef;
			int round = 0;
			
			while(true){
				++round;
				
				devilLife -= playerEffectAtk;
				if(devilLife <= 0){
					System.out.println("You win in " + round + " round(s).");
					break;
				}
				
				playerLife -= devilEffectAtk;
				if(playerLife <= 0){
					System.out.println("You lose in " + round + " round(s).");
					break;
				}
			}
			
		}
	}

}

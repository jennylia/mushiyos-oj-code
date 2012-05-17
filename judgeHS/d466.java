import java.util.Scanner;

public class d466 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		while(input.hasNext()){
			int year = input.nextInt();
			int month = input.nextInt();
			int day = input.nextInt();
			if(isLeapYear(year)) daysInMonth[1] = 29;
			else daysInMonth[1] = 28;
			
			if(year < 1){
				System.out.println("Error");
				continue;
			}
			
			if(month < 1 || month > 12){
				System.out.println("Error");
				continue;
			}
			
			if(day < 1 || day > daysInMonth[month - 1]){
				System.out.println("Error");
				continue;
			}
			
			int countDays = 0;
			//���p��bmonth�뤧�e���Ҧ�������Ѽ��`�X
			for(int m = 1; m < month; ++m){
				countDays += daysInMonth[m - 1];
			}
			//�]���w�g��F���e�Ҧ�������Ѽ��`�X�A�ҦA�[�Wday�Y�i��Xmonth��day��O�ĴX��
			countDays += day;
			
			if(countDays > 1){
				System.out.println("It is " + countDays + " days in " + year);
			}
			else{
				System.out.println("It is " + countDays + " day in " + year);
			}
		}
	}
	
	public static boolean isLeapYear(int year){
		if(year % 400 == 0) return true;
		if(year % 100 == 0) return false;
		if(year % 4 == 0) return true;
		
		return false;
	}
}

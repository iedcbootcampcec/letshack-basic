import java.util.Scanner;

public class Commission_Percentage {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc =new Scanner (System.in);
		float amount, commission_percent;
		
		System.out.println("Enter the Amount in Rupees : ");
		amount = sc.nextFloat();
		
		System.out.println("Enter the Commission value in percent (Eg. % = 20) : ");
		commission_percent = sc.nextFloat();
		
		System.out.print("Commission on "+amount+" is " +(amount *(commission_percent/100))+" Rupees");
		sc.close();
	}

}

import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		if(b < 45) {
			if(a == 0) {
				a = 23;
				b += 15;
			}
			else {
                a -= 1;
				b += 15;
			}
		}
		else {
			b -= 45;
		}
		System.out.print(a + " " + b);
    }
}
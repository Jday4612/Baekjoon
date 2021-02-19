import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int t = a;
		for(int i = 0; i<a ; i++) {
			t += i;
		}
		System.out.print(t);
    }
}
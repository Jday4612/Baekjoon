import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int tmp = 0;
		
		for(int i = 1; i < N+1; i++) {
			if(0 < i && i < 100) tmp += 1;
			else if(100 <= i && i < 1000) {
				int[] w = new int[3];
				w[0] = i / 100; w[1] = (i / 10) % 10; w[2] = i % 10;
				if(w[0] - w[1] == w[1] - w[2]) tmp += 1;
			}
			else if(i == 1000) break;
		}
		System.out.print(tmp);
    }
}
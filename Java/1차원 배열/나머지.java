import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int[] counts = new int[42];
		int num[] = new int[10];
		int cnt = 0;
		for(int i = 0; i<10; i++) {
			num[i] = sc.nextInt() % 42;
		}
		sc.close();
 
		for (int j = 0; j < num.length; ++j) {
            counts[num[j]]++;
        }
         
        for (int i = 0; i < counts.length; ++i) {
        	if (counts[i] != 0) {
        		cnt++;
        	}
        }
        System.out.print(cnt);
    }
}
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		int sum = 0; int cnt = 0; int min = 0;

		for(int i = M; i < N+1; i++) {
			int tmp = 0;
			
			if(i > 1) {
				for(int j = 2; j < i; j++) {
					if(i % j == 0) {
						tmp = -1;
						break;
					}
				}
				if(tmp == 0) {
					sum += i;
					if(cnt == 0) min = i;
					cnt++;
				}
			}
		}
		
		if(min == 0) System.out.print(-1);
		else {
			System.out.println(sum);
			System.out.println(min);
		}
    }
}
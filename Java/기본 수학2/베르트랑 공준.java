import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		
		while(N != 0) {
			int cnt = 0;
			
			for(int i = N + 1; i < 2*N +1; i++) {
				int tmp = 0;
				
				if(i > 1) {
					int t = (int)Math.sqrt(i);
					for(int j = 2; j < t + 1; j++) {
						if(i % j == 0) {
							tmp = -1;
							break;
						}
					}
				}
				
				if(tmp == 0) cnt++;
			}
			System.out.println(cnt);
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
		}
    }
}
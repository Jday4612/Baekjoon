import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int k = Integer.parseInt(st.nextToken());
		for(int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int h = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken()); 
			int j = 1;
			while(0 < n) {
				if(n - h <= 0) break;
		        n -= h;
		        j += 1;
			}
			System.out.println(100 * n + j);
		}
    }
}
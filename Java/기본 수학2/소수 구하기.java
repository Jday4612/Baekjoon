import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken()); int N = Integer.parseInt(st.nextToken());

		for(int i = M; i < N+1; i++) {
			int tmp = 0;
				if(i > 1) {
					for(int j = 2; j < (int)Math.sqrt(i) + 1; j++) {
						if(i % j == 0) {
			                tmp = -1;
			                break;
						}
					}
			        if(tmp == 0) System.out.println(i);
				}
		}
    }
}
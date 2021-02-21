import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < N; i++) {
			int s = 0;
			double cnt = 0;
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int nums[] = new int[a];
			for(int j = 0; j < a; j++) {
				nums[j] = Integer.parseInt(st.nextToken());
			}
			for(int k = 0; k < a; k++) {
				s += nums[k];
			}
			
			s /= a;
			for(int l = 0; l < a; l++) {
				if(nums[l] > s) {
					cnt += 1;
				}
			}
            cnt = cnt / a * 100;
			System.out.printf("%.3f%%\n", cnt);
		}
    }
}
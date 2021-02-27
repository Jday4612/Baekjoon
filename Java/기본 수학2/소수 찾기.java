import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int num_list[] = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int k = 0; k < N; k++) num_list[k] = Integer.parseInt(st.nextToken());
		int cnt = 0;

		for(int i = 0; i < N; i++) {
			int tmp = 0;

			if(num_list[i] == 1) {
				continue;
			}
			else {
				for(int j = 2; j < num_list[i]; j++) {
					if(num_list[i] % j == 0) {
						tmp = -1;
						break;
					}
				}
			}
			
			if(tmp == 0) cnt++;
		}
		System.out.print(cnt);
    }
}
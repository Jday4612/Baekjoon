import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String a = st.nextToken();

			int cnt = 0;
			int add = 0;
			for(int j = 0; j < a.length(); j++) {
				if(a.charAt(j) == 'O') {
					add++;
					cnt += add;
				}
				else{
					add = 0;
				}
			}
			bw.write(cnt + "\n");
		}
		bw.flush();
    }
}
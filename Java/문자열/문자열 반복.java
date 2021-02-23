import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			String ch = st.nextToken();
			for(int j = 0; j < ch.length(); j++) {
				for(int k = 0; k < num; k++) {
					bw.write(ch.charAt(j));
				}
			}
			bw.write("\n");
		}
		bw.flush();
    }
}
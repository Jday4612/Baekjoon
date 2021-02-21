import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int max = 0; int cnt = 0;
		for(int i = 0; i<9; i++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			if(num > max) {
				max = num;
				cnt = i+1;
			}
		}
		bw.write(max + "\n" + cnt);
		bw.flush();
    }
}
import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int[] counts = new int[10];
		int num[] = new int[3];
		for(int i = 0; i<3; i++) {
			st = new StringTokenizer(br.readLine());
			num[i] = Integer.parseInt(st.nextToken());
		}
		String sum_num = String.valueOf(num[0] * num[1] * num[2]); 
		for (int i = 0; i < sum_num.length(); ++i) {
            counts[sum_num.charAt(i) - '0']++;
        }
         
        for (int i = 0; i < counts.length; ++i) {
        	bw.write(counts[i] + "\n");
        }
		bw.flush();
    }
}
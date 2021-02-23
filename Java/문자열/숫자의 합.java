import java.util.StringTokenizer;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		String b = st.nextToken();
		int sum = 0;
		
		for(int i = 0; i < a; i++) {
			sum += b.charAt(i) - '0';
		}
		System.out.print(sum);
    }
}
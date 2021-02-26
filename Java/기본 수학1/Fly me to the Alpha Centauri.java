import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken()); int y = Integer.parseInt(st.nextToken());
			int z = y - x;
			int a = 1;
			int b = 1;
			
			while(z > 0) {
				z -= a;
				a++;
				if(z >= b) {
					z -= b;
					b++;
				}
			}
			System.out.println(a + b - 2);
		}
    }
}
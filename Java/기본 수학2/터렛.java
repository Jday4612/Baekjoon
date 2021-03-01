import java.io.*;
import java.util.StringTokenizer;
import java.math.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken()); int y1 = Integer.parseInt(st.nextToken());
			int r1 = Integer.parseInt(st.nextToken()); int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken()); int r2 = Integer.parseInt(st.nextToken());
			double d = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1,2));
			int r_1 = r1 + r2;
			int r_2 = Math.abs(r1 - r2);

			if(d == 0) {
				if(r1 == r2) System.out.println(-1);
				else System.out.println(0);
			}
			else {
				if(d == r_1 || d == r_2) System.out.println(1);
				else if(d < r_1 && d > r_2) System.out.println(2);
			    else System.out.println(0);
			}
		}
    }
}
import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x[] = new int[4];
		int y[] = new int[4];
		for(int i = 0; i < 3; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			y[i] = Integer.parseInt(st.nextToken());
		}
		x[3] = (x[1] == x[2]) ? x[0] : (x[0] == x[2] ? x[1] : x[2]);
		y[3] = (y[1] == y[2]) ? y[0] : (y[0] == y[2] ? y[1] : y[2]);
		System.out.print(x[3] + " " + y[3]);
    }
}
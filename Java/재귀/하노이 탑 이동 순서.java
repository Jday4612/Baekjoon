import java.io.*;
import java.math.*;

public class Main{
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static void hanoi(int start, int stop, int end, int n) throws IOException {
		if(n >= 1) {
			hanoi(start, end, stop, n - 1);
	        bw.write(start + " " +end + "\n");
	        hanoi(stop, start, end, n - 1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		bw.write(Integer.toString((int)Math.pow(2, n) - 1) + "\n");

		if(1 <= n && n <= 20) hanoi(1, 2, 3, n);
		bw.flush();
	}
}
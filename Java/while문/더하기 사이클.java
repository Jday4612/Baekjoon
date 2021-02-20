import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int cnt = 0, K = 0;
		int A = N;
		while(true) {
			K = A / 10 + A % 10;
			A = (A % 10) * 10 + (K % 10);
			cnt += 1;
			if(A == N) {
				System.out.print(cnt);
				break;
			}
		}
    }
}
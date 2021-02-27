import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		if(N != 1) {
			for(int i = 2; i < N+1; i++) {
				while(N % i == 0) {
					N /= i;
					System.out.println(i);
				}
				if(N == 0) break;
			}
		}
    }
}
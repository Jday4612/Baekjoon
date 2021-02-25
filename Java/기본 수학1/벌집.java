import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(br.readLine());
		int i = 1; int d = 6; int cnt = 1;
		while(a > i) {
			i += d;
			cnt++;
			d += 6;
		}
		System.out.print(cnt);
    }
}
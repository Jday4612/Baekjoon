import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int i = 1; int a; int b;

		while(n > i) {
			n -= i;
			i += 1;
		}
		
		if(i % 2 == 0) {
			a = n;
			b = i - n + 1;
		}
		else {
			a = i - n + 1;
			b = n;
		}
		System.out.print(Integer.toString(a) + '/' + Integer.toString(b));
    }
}
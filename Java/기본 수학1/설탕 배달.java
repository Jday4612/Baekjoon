import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int i = 0;

		while(true) {
			if(n < 0) {
				System.out.print(-1);
				break;
			}
			else if(n % 5 == 0) {
				i += n / 5;
				System.out.print(i);
				break;
			}
			n -= 3;
			i++;
		}
    }
}
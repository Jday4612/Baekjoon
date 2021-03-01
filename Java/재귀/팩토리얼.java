import java.io.*;

public class Main{
    public static int facto(int n) {
		if(n <= 1) return 1;
		else return facto(n-1)*n;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		System.out.print(facto(n));
	}
}
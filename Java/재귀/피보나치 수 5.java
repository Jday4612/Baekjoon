import java.io.*;

public class Main{
    public int fibo(int n) {
		if(n <= 1) return n;
		else return fibo(n-1) + fibo(n-2);
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Main test = new Main();
		System.out.print(test.fibo(n));
    }
}
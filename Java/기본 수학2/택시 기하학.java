import java.io.*;
import java.math.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		System.out.println(String.format("%.6f", n * n * Math.PI));
		System.out.println(String.format("%.6f", n * n * 2.0));
    }
}
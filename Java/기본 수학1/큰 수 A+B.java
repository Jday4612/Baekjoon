import java.io.*;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		BigInteger a = new BigInteger(st.nextToken()); BigInteger b = new BigInteger(st.nextToken());
		System.out.print(a.add(b));
    }
}
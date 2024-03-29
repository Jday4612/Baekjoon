import java.io.*;
import java.util.StringTokenizer;
import java.math.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		int i = Math.min(x, y);
		int j = Math.min(w-x, h-y);
		System.out.print(Math.min(i, j));
    }
}
import java.util.StringTokenizer;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		do {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			bw.write(a+b+"\n");
			a = Integer.parseInt(st2.nextToken());
			b = Integer.parseInt(st2.nextToken());
		} while(a != 0 && b != 0);
		bw.flush();
		bw.close();
    }
}
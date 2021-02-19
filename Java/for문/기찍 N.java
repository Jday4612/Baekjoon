import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int k = Integer.parseInt(br.readLine());
		for(int i = 0; i<k; i++) {
			bw.write((k-i) + "\n");
		}
		bw.flush();
		bw.close();
    }
}
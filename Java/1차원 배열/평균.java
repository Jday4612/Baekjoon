import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int a[] = new int[N];
		
		st = new StringTokenizer(br.readLine());
		double max = 0;
		for(int i = 0; i < N; i++) {
			a[i] = Integer.parseInt(st.nextToken());
			if(a[i] > max) {
				max = a[i];
			}
		}
		
		int sum = 0;
		for(int j = 0; j < N; j++) {
			a[j] = a[j];
			sum += a[j];
		}
        System.out.print(sum / max * 100.0 /N);
    }
}
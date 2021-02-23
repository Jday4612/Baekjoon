import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String n = br.readLine().toUpperCase();
		int apb[] = new int[26];
		int max = 0;
		char result = 0;
		
		for(int i = 0; i < n.length(); i++) {
			apb[n.charAt(i) - 65]++;
			if(max < apb[n.charAt(i) -65]) {
				max = apb[n.charAt(i) - 65];
				result = n.charAt(i);
			} else if(max == apb[n.charAt(i) - 65]) {
				result = '?';
			}
		}
		
		bw.write(result);
		bw.flush();
    }
}
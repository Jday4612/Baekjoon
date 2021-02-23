import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String N = br.readLine();
		int wordlist[] = new int[26];
		
		for(int i = 0; i < wordlist.length; i++) {
			wordlist[i] = -1;
		}
		
		for(int j = 0; j < N.length(); j++) {
			char num = N.charAt(j);
			if(wordlist[num - 'a'] == -1) {
				wordlist[num - 'a'] = j;
			}
		}
		
		for(int k = 0; k < wordlist.length; k++) {
			bw.write(wordlist[k] + " ");
		}
		bw.flush();
    }
}
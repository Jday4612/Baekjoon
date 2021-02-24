import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String n = br.readLine();
		String[] word = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
		
		for(int i = 0; i < word.length; i++) {
			if(n.contains(word[i])) {
				n = n.replaceAll(word[i], "*");
			}
		}
		
		System.out.print(n.length());
    }
}
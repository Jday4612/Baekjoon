import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x = Integer.parseInt(br.readLine());
        String[] n = new String[x];
        int y = x;

        for (int i = 0; i < x; i++) {
            n[i] = br.readLine();
            boolean[] check = new boolean[26];

            for (int j = 1; j < n[i].length(); j++) {
                if ((j - 1) == 0) {
                    check[n[i].charAt(j - 1) - 'a'] = true;
                }
                if (n[i].charAt(j - 1) != n[i].charAt(j)) {
                    int checker = n[i].charAt(j) - 'a';
                    if (check[checker]) {
                        y--;
                        break;
                    }
                    check[checker] = true;
                }
            }
        }
        System.out.print(y);
    }
}
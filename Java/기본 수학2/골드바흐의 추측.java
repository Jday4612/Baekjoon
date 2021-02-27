import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num_list[] = new int[10000 + 2];
		for(int i = 1; i < 10000 + 1; i++) {
			int tmp = 0;
			
			if(i > 1) {
				for(int j = 2; j < (int)Math.sqrt(i) + 1; j++) {
					if(i % j == 0) {
				    	num_list[i] = 1;
				    	break;
					}
				}
			}
		}

		int T = Integer.parseInt(br.readLine());
		for(int k = 0; k < T; k++) {
		    int N = Integer.parseInt(br.readLine());
		    int a = N / 2;
		    int b = N / 2;
		    while(true) {
		        if(num_list[a] == 0 && num_list[b] == 0) break;
		        a--;
		        b++;
		    }
		    System.out.println(a + " " + b);
		}
    }
}
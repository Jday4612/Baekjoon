import java.io.*;

public class Main{
    public static String star_list[];
	public static String[] get_stars(String[] star) {
		star_list = new String[3 * star.length];
		for(int i = 0; i < 3 * star.length; i++) {
			String tmp = "";
			if(i / star.length == 1) {
				tmp += star[i % star.length];
				for(int j =0; j < star.length; j++) tmp += " ";
				tmp += star[i % star.length];
				star_list[i] = tmp;
			}
			else {
				for(int j =0; j < 3; j++) tmp += star[i % star.length];
				star_list[i] = tmp;
			}
		}
		return star_list;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine()); // n = 3^k (1 <= k < 8)
		String[] star = new String[3];
		star[0] = "***"; star[1] = "* *"; star[2] = "***";
		int cnt = 0;
		while(n != 3) {
			n /= 3;
			cnt++;
		}
		
		for(int i = 0; i < cnt; i++) star = get_stars(star);
		for(int j = 0; j < star.length; j++) System.out.println(star[j]);
	}
}
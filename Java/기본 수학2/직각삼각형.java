import java.io.*;
import java.util.StringTokenizer;
import java.math.*;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			ArrayList<Integer> num_list = new ArrayList<Integer>(3);
		    for(int i = 0; i < 3; i ++) num_list.add(Integer.parseInt(st.nextToken()));
		    
		    if(num_list.get(0) + num_list.get(1) + num_list.get(2) == 0) break;
		    int max_a = num_list.get(0) >= num_list.get(1) ? num_list.get(0) :
		    	(num_list.get(1) >= num_list.get(2) ? num_list.get(1) : num_list.get(2));
		    num_list.remove(num_list.indexOf(max_a));
		    if(Math.pow(max_a, 2) == Math.pow(num_list.get(0), 2) + Math.pow(num_list.get(1), 2)) System.out.println("right");
		    else System.out.println("wrong");
		}
    }
}
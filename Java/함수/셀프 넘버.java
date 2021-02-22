public class Main{
    public static void main(String[] args){
        boolean[] checklist = new boolean[10000];
        
        for(int i = 1; i < 10001; i++){
            int n = i;
            String tmp = Integer.toString(i);
            
            for(int j = 0; j < tmp.length(); j++){
                n += tmp.charAt(j) - '0';
            }
            
            if(n > 10000) continue;
            checklist[n - 1] = true;
        }
        
        for (int t = 0; t < 10000; t++) {
            if (!checklist[t])
                System.out.println(t + 1);
		}
    }
}
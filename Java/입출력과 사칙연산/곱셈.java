import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        int cc[] = new int[3];
        cc[0] = b % 10;
        cc[1] = (b % 100) / 10;
        cc[2] = b / 100;
        System.out.println(a * cc[0]);
        System.out.println(a * cc[1]);
        System.out.println(a * cc[2]);
        System.out.print(a * b);
    }
}
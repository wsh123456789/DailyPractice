package practice;

import java.util.Scanner;
public class MethodDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        System.out.println("最大值为");
        getMax(a,b);
        int num = getMax(a,b,c);
        System.out.println("和为："+num);

}
    public static void getMax(int a,int b){
        System.out.println(a>b?a:b);
    }
    public static int getMax(int a,int b,int c){
        return a+b+c;
    }

}
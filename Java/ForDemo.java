package practice;/*
    输出所有的水仙花数并统计个数
 */
import java.util.Scanner;
public class ForDemo {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int count = 0;
        for(int i = 100;i <= 999;i++){
            //百位数
            int a = i/100;
            //个位数
            int b = i%10;
            //十位数
            int c = i/10-a*10;
            if(a*a*a + b*b*b + c*c*c == i){
                count++;
                System.out.println(i+"是水仙花数");
            }
        }
        System.out.println("一共有"+count+"个水仙花数");
    }
}

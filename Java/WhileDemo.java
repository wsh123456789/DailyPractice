package practice;/*
    输入一个数（毫米）表示纸张厚度，在确保足够大的情况下，折叠多少次可以大于等于珠穆朗玛峰的高度。(珠穆朗玛峰暂且认为是8844.43米)
 */
import java.util.Scanner;
public class WhileDemo {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入纸张的厚度:");
        double a = sc.nextDouble();
        int zf = 8844430;
        int count = 0;
        while(a < zf){
            a *= 2;
            count++;
        }
        //do...while必定执行一次，如果初始厚度大于珠穆朗玛峰高度，答案会出错
//        do{
//            a *= 2;
//            count++;
//        }while(a < zf);
        System.out.println("需要折叠"+count+"次");
    }
}

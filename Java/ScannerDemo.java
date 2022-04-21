package practice;

import java.util.Scanner;
/*
    录入三个数字，比较大小，输出最大的值
*/
public class ScannerDemo {
    public static void main(String[] args){
//        Scanner sc = new Scanner(System.in);
//        int x = sc.nextInt();
//        System.out.println("x:"+x);
        //导包 创建对象
        Scanner sc = new Scanner(System.in);
        //设置存储单元
        int max = -100;
        //循环赋值
        for (int i = 0;i < 3; i++){
            //赋值
            System.out.println("请输入第"+(i+1)+"个值");
            int x = sc.nextInt();
            //比较保留最大值
            max = max > x ? max : x;
//            if(max < x){
//                max = x;
//            }
        }
        //输出最大值
        System.out.println("max:"+max);
    }
}

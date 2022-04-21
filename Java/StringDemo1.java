package practice;

import java.util.Scanner;

public class StringDemo1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String user="wsh",password="123";
        int count = 3;
        for(int i = 0;i < 3;i++){
            System.out.println("请输入用户名");
            String us = sc.nextLine();
            System.out.println("请输入密码");
            String pw = sc.nextLine();
            if(us.equals(user)&&pw.equals(password)){
                System.out.println("登陆成功");
                break;
            }
            else{
                System.out.println("用户名或密码错误");
                System.out.println("你还有"+(count-i-1)+"次机会");
                if(count-1-i==0){
                    System.out.println("您的帐户已锁定");
                    break;
                }
            }
        }
    }
}

//随机生成一个1-100之间的数字，有十次猜数机会，分别提示猜对了，猜大了，猜小了，失败了提示语

import java.util.Random;
import java.util.Scanner;

public class RandomDemo {
    public static void main(String[] args) {
        Random r = new Random();
        Scanner m = new Scanner(System.in);
        int flag = 0;
        int number = r.nextInt(100) + 1;
        for (int i = 0; i < 10; i++) {
            //随机生成1-100的随机数。
            System.out.println("请输入你要猜的数字");
            int num = m.nextInt();
            if (num == number) {
                System.out.println("猜对了");
                flag = 1;
                break;
            } else if (num > number) {
                System.out.println("猜大了");
            } else {
                System.out.println("猜小了");
            }
        }
        if (flag == 0) {
            System.out.println("失败了");
        }



    }
}
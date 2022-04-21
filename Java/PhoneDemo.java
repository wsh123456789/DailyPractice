package practice;

import java.util.Scanner;
public class PhoneDemo {
    public static void main(String[] args) {
        Phone p = new Phone();
        System.out.println(p.brand);
        System.out.println(p.price);
        Scanner sc = new Scanner(System.in);
        p.brand =  sc.nextLine();
        p.price = sc.nextInt();
        System.out.println(p.price);
        System.out.println(p.brand);
        p.call();
        p.sendMassage();
    }
}

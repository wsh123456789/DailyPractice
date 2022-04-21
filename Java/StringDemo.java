package practice;

import java.util.Scanner;
public class StringDemo {
    public static void main(String[] args) {
        //public String():创建一个空白字符串对象，不含有任何内容
        String s1 = new String();
        System.out.println("s1:"+s1);

        //public String(char[] chs): 根据字符数组的内容，来创建字符串对象
        char[] chs = {'a','b','c'};
        String s2 = new String(chs);
        System.out.println("s2:"+s2);

        //public String(byte[] bys): 根据字节数组的内容，来创建字符串对象
        byte[] bys = {97,98,99};
        String s3 = new String(bys);
        System.out.println("s3:"+s3);

        //直接赋值
        String s4;
        Scanner sc = new Scanner(System.in);
        s4 = sc.nextLine();
        System.out.println("s4:"+s4);

        //比较字符串对象地址是否相同
        System.out.println(s2==s3);

        //比较字符串内容是否相同
        System.out.println(s2.equals(s3));
    }
}

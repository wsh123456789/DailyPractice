package practice;

import org.w3c.dom.ls.LSOutput;

/*
StringBuilder构造方法:
    public StringBuilder();,创建一个空白可变字符串对象，不含任何内容
    public StringBuilder("Stinig str"): 根据字符串内容，来创建可变字符串对象

 */
public class StringBuilderDemo1 {
    public static void main(String[] args) {
        //public StringBuilder(),创建一个空白可变字符串对象，不含任何内容
        StringBuilder sb = new StringBuilder();
        System.out.println("sb:"+sb);
        System.out.println("sb.length():"+sb.length());


        // public StringBuilder("Stinig str"): 根据字符串内容，来创建可变字符串对象
        StringBuilder sb2 = new StringBuilder("hello");
        System.out.println("sb2:"+sb2);
        System.out.println("sb2.length():"+sb2.length());

        sb2.append("world");
        System.out.println("sb2:"+sb2);
        System.out.println("sb2.length():"+sb2.length());
    }

}

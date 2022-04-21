package practice;


import java.util.ArrayList;

public class ArrayListDemo01 {
    public static void main(String[] args) {
        //创建集合对象
        ArrayList<String> array = new ArrayList<String>();
        //在尾部添加元素
        array.add("hello");
        array.add("world");
        array.add("java");
        //插入
        array.add(1,"javaee");
        //删除
        array.remove("world");
        array.remove(1);
        //修改
        array.set(1,"javaee");
        //获取
        System.out.println(array.get(0));
        //  获取集合中的数量
        System.out.println(array.size());
        // 输出
        System.out.println("array:" +array);
    }
}

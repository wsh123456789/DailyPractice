package practice.jicheng;

public class Demo01 {
    public static void main(String[] args) {
        //创建老师类进行测试
        Teacher t1 = new Teacher();
        t1.setName("aaa");
        t1.setAge(30);
        System.out.println(t1.getName()+"，"+t1.getAge());
        t1.teach();

        Teacher t2 = new Teacher("bbb",33);
        System.out.println(t2.getName()+","+t2.getAge());
        t2.teach();

        Student s1 = new Student();
        s1.setName("loujinming");
        s1.setAge(18);
        System.out.println(s1.getName()+","+s1.getAge());
        s1.study();

        Student s2 = new Student("litiancheng",19);
        System.out.println(s2.getName()+","+s2.getAge());
        s2.study();


    }
}

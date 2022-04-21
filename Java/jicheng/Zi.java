package practice.jicheng;

public class Zi extends Fu{
//    int age = 3;
//    int height = 170;
    public void method(){
//        int age = 4;
        System.out.println("zi中method方法被调用");
//        System.out.println(age);
//        System.out.println(height);
//        //访问本类的成员变量
//        System.out.println(this.age);
//        //访问父类的成员变量
//        System.out.println(super.age);
    }
    public void show(){
        super.show();
        System.out.println("zi中show方法被调用");

//        System.out.println(age);
    }
}

package practice.jicheng;

public class Student extends Person{
    public Student(){

    }

    public Student(String name,int age){
        super(name,age);
    }
    public void study(){
        System.out.println("好好学习天天向上");
    }
}

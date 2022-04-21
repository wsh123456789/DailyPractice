package practice.jicheng;

public class NewPhone extends Phone{

    @Override//重写注解
    public void call(String name){
        System.out.println("开启视频功能");
//        System.out.println("给"+name+"打电话");
        super.call(name);
    }
}


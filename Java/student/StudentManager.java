package practice.student;

import java.util.ArrayList;
import java.util.Scanner;

public class StudentManager {
    public static void main(String[] args) {
        ArrayList<Student> array = new ArrayList<>();
        while (true) {
            System.out.println("--------欢迎来到学生管理系统--------");
            System.out.println("1.添加学生");
            System.out.println("2.删除学生");
            System.out.println("3.修改学生");
            System.out.println("4.查看所有学生");
            System.out.println("5.退出");
            System.out.println("请输入你的选择:");
            Scanner sc = new Scanner(System.in);
            String line = sc.nextLine();
            switch (line) {
                case "1":
//                    System.out.println("1.添加学生");
                    addStudent(array);
                    break;
                case "2":
//                    System.out.println("2.删除学生");
                    deleteStudent(array);
                    break;
                case "3":
//                    System.out.println("3.修改学生");
                    updateStudent(array);
                    break;
                case "4":
//                    System.out.println("4.查看所有学生");
                    findAllStudent(array);
                    break;
                case "5":
                    System.out.println("谢谢使用");
                    System.exit(0);

            }
        }
    }

    //添加学生信息
    public static void addStudent(ArrayList<Student> array) {
        Scanner sc = new Scanner(System.in);
        int index = -1;
        System.out.println("请输入学生编号:");
        String sid = sc.nextLine();
        Student s = new Student();
        s.setSid(sid);
        for (int i = 0; i < array.size(); i++) {
            Student student = array.get(i);
            if (sid.equals(student.getSid())) {
                index = 1;
            }
        }
        if (index == 1&&array.size()>0) {
            System.out.println("你输入的信息有误，该学号已存在");
        } else {
            System.out.println("请输入学生姓名:");
            String name = sc.nextLine();
            System.out.println("请输入学生年龄:");
            String age = sc.nextLine();
            System.out.println("请输入学生地址:");
            String address = sc.nextLine();


            s.setName(name);
            s.setAge(age);
            s.setAddress(address);


            array.add(s);

            System.out.println("添加成功");

        }


    }

    //查看学生信息
    public static void findAllStudent(ArrayList<Student> array) {
        if (array.size() <= 0) {
            System.out.println("无信息，请添加信息在查询");
        } else {
            System.out.println("学号\t姓名\t年龄\t地址\t");
            for (int i = 0; i < array.size(); i++) {
                Student s = array.get(i);
                System.out.println(s.getSid() + "\t" + s.getName() + "\t" + s.getAge() + "\t" + s.getAddress() + "\t");
            }
        }

    }

    //删除学生信息
    public static void deleteStudent(ArrayList<Student> array) {
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入要删除学生的学号");

        String sid = sc.nextLine();

        int index = -1;
        for (int i = 0; i < array.size(); i++) {
            Student s = array.get(i);
            if (sid.equals(s.getSid())) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            System.out.println("您输入的信息不存在");
        } else {
            array.remove(index);
            System.out.println("删除成功");
        }


    }

    //修改学生信息
    public static void updateStudent(ArrayList<Student> array) {
        Scanner sc = new Scanner(System.in);
        Student s = new Student();
        int index = -1;
        System.out.println("请输入你要修改的学生的学号:");
        String sid = sc.nextLine();
        s.setSid(sid);
        for (int i = 0; i < array.size(); i++) {
            Student student = array.get(i);
            if (student.getSid().equals(s.getSid())) {
                index = i;
                break;
            }

        }
        if (index == -1) {

            System.out.println("您输入的信息有误，请重新输入");
        } else {
            System.out.println("请输入你要修改的学生的姓名:");
            String name = sc.nextLine();
            System.out.println("请输入你要修改的学生的年龄:");
            String age = sc.nextLine();
            System.out.println("请输入你要修改的学生的地址:");
            String address = sc.nextLine();
            s.setName(name);
            s.setAge(age);
            s.setAddress(address);
            array.set(index, s);
        }


    }
}


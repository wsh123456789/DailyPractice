package helloworld;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class hello_1 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        //加载驱动
        Class.forName("com.mysql.jdbc.Driver");

        String url = "jdbc:mysql://localhost:3306/wusihao";
        String user = "root";
        String pwd = "wusihao.@123";

        Connection connection = DriverManager.getConnection(url,user,pwd);
        //获取执行者
        Statement statement = connection.createStatement();

        //判断连接是否成功
        if(connection == null){
            System.out.println("连接失败");
        }
        else{
            System.out.println("连接成功");



            //执行语句
//            String sql = "INSERT INTO `user`(`id`,`username`,`height`,`weight`,`sex`,`info`) VALUES(3,'wangwu',165,106,1,'王五')";
//
//
//            if(statement.executeUpdate(sql) >= 1){
//                System.out.println("插入成功");
//            }
//            else {
//                System.out.println("插入失败");
//            }

//            String sql = "UPDATE `user` SET sex = 0 WHERE id=3;";
//            String sql = "DELETE  FROM `user` WHERE id=3;";
            //关闭连接

            connection.close();
        }


    }
}

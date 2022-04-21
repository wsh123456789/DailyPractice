package helloworld;

import java.sql.*;

public class hello_2 {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver");

            String url = "jdbc:mysql://localhost:3306/wusihao";
            String user = "root";
            String pwd = "wusihao.@123";

            Connection connection = DriverManager.getConnection(url,user,pwd);

            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM `user`;";
            ResultSet resultSet = statement.executeQuery(sql);
            System.out.println("id"+"\t"+"username"+"\t"+"height"+"\t"+"weight"+"\t"+"sex"+"\t");
            while(resultSet.next()){
                System.out.print(resultSet.getString("id")+"\t");
                System.out.print(resultSet.getString("username")+"\t");
                System.out.print(resultSet.getString("height")+"\t\t");
                System.out.print(resultSet.getString("weight")+"\t\t");
                System.out.println(resultSet.getString("sex"));
            }

        } catch (ClassNotFoundException  | SQLException e) {
            e.printStackTrace();
        }
    }
}

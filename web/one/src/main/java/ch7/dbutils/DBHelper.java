package ch7.dbutils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import com.mysql.jdbc.Driver;

public class DBHelper {    //工具类：数据库的连接、创建、释放
	private static Connection conn = null;
	
	//创建连接 加载启动
	static {
		// 静态代码块，加载类时会执行静态代码块，而且只执行一次
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
	public static Connection getConn() { //获取连接对象
		try {
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/wusihao", "root", "wusihao.@123");
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		return conn;
	}
	
	public static Connection closeConn() { 
		if(conn!=null) {
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
		}
		return conn;
	}

}

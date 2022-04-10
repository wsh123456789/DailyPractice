package ch7.dbutils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


import com.mysql.jdbc.Driver;

public class DBHelper2 {    //工具类：数据库的连接、创建、释放
	private static Connection conn = null;
	
	private static ComboPooledDataSource cpds = null;
	static {//保证数据库连接池对象就一个
		cpds = new ComboPooledDataSource("myc3p0");
	}
	
	public static Connection getConn() { //获取连接对象
		try {
			conn=cpds.getConnection();
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

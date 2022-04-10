package ch7.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import ch7.dao.UserDao;
import ch7.dbutils.DBHelper;

public class UserDaoImpl implements UserDao {
	Connection conn = null;
	@Override
	public Boolean queryUserByAndPwd(String username, String password) {
		//1.连接数据库
		conn = DBHelper.getConn();
		//2.获取PreparedStatement
		try {
			PreparedStatement ps = conn.prepareStatement("select * from users where username=?&&password=?");
			//3.赋值
			ps.setString(1, username);
			ps.setString(2, password);
			
			ResultSet rs = ps.executeQuery();
			//查询结果：要么一条，要么没有
			if(rs.next()) {
				return true;
			}else {
				return false;
			}
			
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		
		
		return null;
	}
}

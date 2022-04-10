package ch7.junits;

import static org.junit.jupiter.api.Assertions.*;

import java.beans.PropertyVetoException;
import java.sql.Connection;
import java.sql.SQLException;

import javax.xml.bind.PropertyException;

import org.junit.jupiter.api.Test;

import com.mchange.v2.c3p0.ComboPooledDataSource;

class C3p0Test {
	//普通的java类不能直接运行，因为只有main()方法的类才能独立运行main入口
	@Test
	void test() throws PropertyException, SQLException, PropertyVetoException {//方法上，加了注解@Test
		//c3p0数据库连接池的测试，连接池对象类型：DataSource接口 各个服务器都针对DataSource
		
		ComboPooledDataSource cpds = new ComboPooledDataSource();
		//连接哪儿个数据库，登录名，密码
		cpds.setDriverClass("com.mysql.jdbc.Driver");
		//设置驱动程序
		cpds.setUser("root");
		cpds.setPassword("wusihao.@123");
		//如果数据库在本机，并保持默认端口号，可以省略
		cpds.setJdbcUrl("jdbc:mysql:///wusihao");
		
		Connection conn = cpds.getConnection();
		System.out.println(conn);
		
		//硬编码 连接池的创建管理都用Java实现，不推荐使用
	}
	
	@Test
	void testXml() throws SQLException {
		ComboPooledDataSource cpds = new ComboPooledDataSource("myc3p0");
		System.out.println(cpds.getConnection());
	}

}

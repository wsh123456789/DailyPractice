package ch7.junits;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.ResultSetHandler;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.junit.jupiter.api.Test;

import com.mysql.Query;
import com.sun.corba.se.pept.transport.Connection;

import ch7.b.BookBean;
import ch7.dbutils.DBHelper2;

class DBUtilsTest {

	java.sql.Connection conn = null;
	@Test
	void testQueryOne() throws SQLException {
		conn = DBHelper2.getConn();
		
		String sql = "select * from books where bookID=?";
		QueryRunner runner = new QueryRunner();
		BeanHandler<BookBean> handler = new BeanHandler<BookBean>(BookBean.class);
		BookBean book = runner.query(conn, sql, handler, "119");
		
		System.out.println("testQueryOne:"+book);
 		
	}
	
	@Test
	void testQueryAll() throws SQLException{
		conn = DBHelper2.getConn();
		
		String sql = "select * from books";
		QueryRunner runner = new QueryRunner();
		BeanListHandler<BookBean> handler = new BeanListHandler<BookBean>(BookBean.class);
		List<BookBean> books = runner.query(conn, sql, handler);
		
		System.out.println("testQueryAll:"+books);
	}
	
	@Test
	void testAddBook() throws SQLException{
		conn = DBHelper2.getConn();
		
		String sql = "insert into books values(?,?,?,?,?)";
		QueryRunner runner = new QueryRunner();
		int n = runner.update(conn, sql, "26", "大数据分析", "Mary", "中国邮电出版社", 36); 
		
		System.out.println("testAddBook:"+n);
	}
	
	@Test
	void testDeleteBook() throws SQLException{
		conn = DBHelper2.getConn();
		
		String sql = "delete from books where bookID=?";
		QueryRunner runner = new QueryRunner();
		int n = runner.update(conn, sql, "23"); 
		
		System.out.println("testDeleteBook:"+n);
	}
	
	@Test
	void testUpdateBook() throws SQLException{
		conn = DBHelper2.getConn();
		
		String sql = "update books set bookPrice=? where bookID=?";
		QueryRunner runner = new QueryRunner();
		int n = runner.update(conn, sql, "2.3", "25"); 
		
		System.out.println("testUpdateBook:"+n);
	}

}

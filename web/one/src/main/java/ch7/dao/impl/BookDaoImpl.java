package ch7.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;


import ch7.b.BookBean;
import ch7.dao.BookDao;
import ch7.dbutils.DBHelper;

public class BookDaoImpl implements BookDao {

	Connection conn = null;
	PreparedStatement ps = null;
	ResultSet rs = null;
	Statement stmt = null;
	@Override
	public List<BookBean> selectAllBooks() {
		//连接数据库
		conn = DBHelper.getConn();
		//创建ps
		List<BookBean> books = new ArrayList<BookBean>(); 
		try {
			ps = conn.prepareStatement("select * from books");
			rs = ps.executeQuery();
			while(rs.next()) { //查询到的结果集中的每一条图书记录封装成一个bean对象
				BookBean book = new BookBean();
				book.setBookAuthor(rs.getString(3));
				book.setBookID(rs.getString(1));
				book.setBookName(rs.getString(2));
				book.setBookPrice(rs.getDouble(5));
				book.setPubilsher(rs.getString(4));
				books.add(book);
			}
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		} finally {
			try {
				rs.close();
				ps.close();
			} catch (SQLException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
			
		}
		DBHelper.closeConn();
		
		return books;
	}

	@Override
	public int addBook(BookBean book) {
		conn = DBHelper.getConn();
		// TODO 自动生成的方法存根
		try {
			ps = conn.prepareStatement("insert into books set bookID=?,bookName=?,bookAuthor=?,publisher=?,bookPrice=?");
			ps.setString(1, book.getBookID());
			ps.setString(2, book.getBookName());
			ps.setString(3, book.getBookAuthor());
			ps.setString(4, book.getPubilsher());
			ps.setDouble(5, book.getBookPrice());
			int rs = ps.executeUpdate();
			if(rs==1) {
				selectAllBooks();
				return 1;
			}
			else {
				selectAllBooks();
				return 0;
			}
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
			return 0;
		}
		
	}

	@Override
	public int updateBook(BookBean book) {
		conn = DBHelper.getConn();
		// TODO 自动生成的方法存根
		try {
			ps = conn.prepareStatement("update books set bookPrice=? where bookID=?");
			ps.setString(2, book.getBookID());
			ps.setDouble(1, book.getBookPrice());
			int rs = ps.executeUpdate();
			if(rs==1) {
				return 1;
			}
			else {
				return 0;
			}
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
			return 0;
		}
	}

	@Override
	public int deleteBookByBookID(String bookID) {
		conn = DBHelper.getConn();
		// TODO 自动生成的方法存根
		try {
			
//			stmt = conn.createStatement();//创建一个SQL语句对象
//			String sql = "delete from books where bookID="+bookID;
//			int n = stmt.executeUpdate(sql);
			
			ps = conn.prepareStatement("delete from books where bookID=?");
			ps.setString(1, bookID);
			int rs = ps.executeUpdate();
			if(rs==1) {
				return 1;
			}
			else {
				return 0;
			}
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
			return 0;
		}
	}

}

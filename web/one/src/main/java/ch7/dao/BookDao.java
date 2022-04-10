package ch7.dao;

import java.util.List;

import ch7.b.BookBean;

public interface BookDao {
	public List<BookBean> selectAllBooks();
	public int addBook(BookBean book);
	public int updateBook(BookBean book);
	public int deleteBookByBookID(String bookID);
}

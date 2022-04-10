package ch7.s;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import ch7.b.BookBean;
import ch7.dao.BookDao;
import ch7.dao.impl.BookDaoImpl;

/**
 * Servlet implementation class BookServlet
 */
@WebServlet("/book")
public class BookServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public BookServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		
		String method = request.getParameter("method");
		switch(method) {//C语言中的switch和Java语言中的switch区别？
			case "queryAll":
				//查询操作
				doQueryAll(request,response);break;
			case "add":
				doAdd(request,response);break;
			
			case "delete":
				doDelete(request,response);break;
				
			case "modify":
				doModify(request,response);break;
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}
	
	protected void doQueryAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		BookDao bookDao = new BookDaoImpl();
		List<BookBean> books = bookDao.selectAllBooks();
		//System.out.println(books);
		//去JSP页面显示   去重定向，可以转发
		//封装结果数据，（request  session）
		request.getSession().setAttribute("books", books);
		response.sendRedirect("main.jsp");
	}
	protected void doAdd(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}
	protected void doModify(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		BookDao bookDao = new BookDaoImpl();
		//到底进行添加还是修改
		String bookID = request.getParameter("bookID");
		String bookName = request.getParameter("bookName");
		if(bookName==null) {
			//进行修改操作
			BookBean book = new BookBean();
			book.setBookID(bookID);
			book.setBookPrice(Double.parseDouble(request.getParameter("bookPrice")));
			if(bookDao.updateBook(book)==1) {
				response.sendRedirect("book?method=queryAll");
			}
			else {
				response.sendRedirect("saveBook.jsp?bookID="+bookID+"&bookName="+bookName);
			}
		}else {
			BookBean book = new BookBean();
			book.setBookID(bookID);
			book.setBookName(bookName);
			book.setBookAuthor(request.getParameter("bookAuthor"));
			book.setPubilsher(request.getParameter("publisher"));
			book.setBookPrice(Double.parseDouble(request.getParameter("bookPrice")));
			//进行添加操作
			if(bookDao.addBook(book)==1) {
				response.sendRedirect("book?method=queryAll");
			}
			else {
				response.sendRedirect("saveBook.jsp");
			}
		}
	}
	protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		BookDao bookDao = new BookDaoImpl();
		String bookID = request.getParameter("bookID");
		if(bookDao.deleteBookByBookID(bookID)==1) {
			response.sendRedirect("book?method=queryAll");
		}
		else {
			response.sendRedirect("book?method=queryAll");
		}
	}

}

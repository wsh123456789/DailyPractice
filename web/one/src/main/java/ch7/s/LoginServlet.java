package ch7.s;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import ch7.dao.UserDao;
import ch7.dao.impl.UserDaoImpl;


@WebServlet("/login")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
     
    public LoginServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//1.获取用户请求诗句
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		//2.登录验证
		UserDao userDao = new UserDaoImpl();//多态，向上转型
		Boolean b = userDao.queryUserByAndPwd(username, password);
		if(b) {
			//登录成功
			response.sendRedirect("main.jsp");
		}else {
			//登录失败
			response.sendRedirect("login.jsp?flag=1");
		}
		
		
	}

}

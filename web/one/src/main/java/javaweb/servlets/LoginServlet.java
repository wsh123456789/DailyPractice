package javaweb.servlets;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import b.UserBean;


@WebServlet("/Login")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public LoginServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	@Override
	public void init() throws ServletException {
		// TODO 自动生成的方法存根
		List<UserBean> users=new ArrayList<UserBean>();
		UserBean u1=new UserBean("aa","aa");
		UserBean u2=new UserBean("bb","bb");
		UserBean u3=new UserBean("cc","cc");
		UserBean u4=new UserBean("dd","dd");
		UserBean u5=new UserBean("ee","ee");
		users.add(u1);
		users.add(u2);
		users.add(u3);
		users.add(u4);
		users.add(u5);
		ServletContext servletContext = this.getServletContext();
		servletContext.setAttribute("users",users);
	}


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		
	    String username=request.getParameter("username");
	    String password=request.getParameter("password");
	    UserBean u=new UserBean();
	    u.setUsername(username);
	    u.setPassword(password);
	    int flag=0;
	    List<UserBean> users=(List<UserBean>)request.getServletContext().getAttribute("users");
	    for(UserBean user:users) {
	    	if(user.getUsername().equals(username)&&user.getPassword().equals(password)){
	    		flag=1;
	    	}
	    }
	    if(flag==1) {
	    	response.getWriter().print("登录成功");
	    } else {
	    	response.getWriter().print("登录失败");
		}
	}

}
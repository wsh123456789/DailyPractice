package javaweb.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class SecondServlet
 */
@WebServlet("/Second")
public class SecondServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public SecondServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String s1=request.getParameter("eng");
		s1.split(s1);
		for (String str: s1.split(" ")){
			response.getWriter().print(str);
			response.getWriter().print("<br/>");
        }
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String n1=request.getParameter("num");
		int num=Integer.parseInt(n1);
		int r=0;
		for(int i=1; i<=num; i++) {
			r=r+i;
		}
		response.getWriter().print(r);
	}

}

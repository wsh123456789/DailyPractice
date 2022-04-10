package javaweb.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import b.CaculateBean;

/**
 * Servlet implementation class ComputeServlet
 */
@WebServlet("/compute")
public class ComputeServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ComputeServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request,response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//1.封装请求中的数据
		String s1 = request.getParameter("n1");
		String s2 = request.getParameter("n2");
		String op = request.getParameter("op");
		CaculateBean cb =new CaculateBean();
		int n1 = Integer.parseInt(s1);
		int n2 = Integer.parseInt(s2);
		cb.setN1(n1);
		cb.setN2(n2);
		cb.setOp(op);
		//2.实现计算
		
		int result = 0;
			if("+".equals(op))   
				result = n1 + n2;
			else if("-".equals(op))
				result = n1 - n2;
			else if("*".equals(op))
				result = n1 * n2;
			else if("/".equals(op))
				result = n1 / n2;
			else if("%".equals(op))
				result = n1 % n2;

		//3.封装计算结果
		cb.setResult(result);
		
		//4.
		request.getSession().setAttribute("cb", cb);
		response.sendRedirect("show.jsp");
	}

}

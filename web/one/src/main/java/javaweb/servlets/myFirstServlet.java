package javaweb.servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class myFirstServlet extends HttpServlet {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
	public void destroy() {
		// TODO 鑷姩鐢熸垚鐨勬柟娉曞瓨鏍�
		System.out.println("destroy() 琚攢姣佹椂璋冪敤  鏁翠釜鐢熷懡鍛ㄦ湡鍙皟鐢ㄤ竴娆�");
	}

	@Override
	public void init() throws ServletException {
		// TODO 鑷姩鐢熸垚鐨勬柟娉曞瓨鏍�
		System.out.println("init() 鍒濆鍖栬璋冪敤  鏁翠釜鐢熷懡鍛ㄦ湡鍙皟鐢ㄤ竴娆�");
	}

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		
		resp.getWriter().print(getArea(req,resp)+"         ");
		//resp.getWriter().print("I am a Servlet.hahaha~~~");
		System.out.println("閮絛oGet()鏂规硶琚皟鐢�   鍙娆¤姹�");
		//鏈嶅姟鍣ㄦ�庝箞鐭ラ亾servlet鐨勫瓨鍦� 鍒涘缓鐨勬瘡涓�涓猄ervlet閮藉緱娉ㄥ唽锛堥儴缃诧級
		
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		// TODO 鑷姩鐢熸垚鐨勬柟娉曞瓨鏍�
		doGet(req, resp);
		System.out.println("閮絛oPost()鏂规硶琚皟鐢�   鍙娆¤姹�");
	}
	
	public int getArea(HttpServletRequest req, HttpServletResponse resp) {
		String x = req.getParameter("x");
		String y = req.getParameter("y"); // request 閲岄潰灏佽鐨勬暟鎹紝绫诲瀷閮芥槸 String
		int b = Integer.parseInt(x);
		int a = Integer.parseInt(y);
		int area;
		area = b*a;
		return area;
	}

}

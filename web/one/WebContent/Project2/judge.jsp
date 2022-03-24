<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
	<%
		String str = request.getParameter("guess");
		//从judge中获得用户猜测的数字
		int guess = Integer.parseInt(str);
		//从session中获取系统生成的随机数
		int number = (int) session.getAttribute("number");
		if (number == guess) {
			response.sendRedirect("sucess.jsp");
		} else if (number > guess) {
			response.sendRedirect("small.jsp");
		} else {
			response.sendRedirect("large.jsp");
		}
	%>
</body>
</html>
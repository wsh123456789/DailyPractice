<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=cyan>
	<%
		String s = request.getParameter("r"); // request 里面封装的数据，类型都是 String
		int r = Integer.parseInt(s);
		double area;
		area = 3.14 * r * r;
	%>
	
	半径为<%=s %>的圆的面积是：<%=area %>
</body>
</html>
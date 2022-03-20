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
		String s=request.getParameter("r");
		int r1=Integer.parseInt(s);
		double area;
		area = 3.14*r1*r1;
	%>
	<p><font size=6 color=red>1910212133吴思豪</font></p>
	<p>半径为<%=s %>的圆的面积是:<%=area %></p>
</body>
</html>
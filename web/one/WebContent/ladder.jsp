<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		String x = request.getParameter("a"); // request 里面封装的数据，类型都是 String
		String y = request.getParameter("b");
		String z = request.getParameter("h");
		double a = Integer.parseInt(x);
		double b = Integer.parseInt(y);
		double h = Integer.parseInt(z);
		double area;
		area = (a + b) * h / 2;
	%>
	
	上底为<%=a %>, 下底为<%=b %>, 高为<%=h %>的圆的面积是：<%=area %>

</body>
</html>
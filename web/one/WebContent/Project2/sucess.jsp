<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
	<font size="4" color=green>恭喜您猜对了!!!</font>
	<font size="3"><br> 实际数字为:
	<%
	int number = (int) session.getAttribute("number");
%>
	<%=number%>
	</font>
</body>
</html>
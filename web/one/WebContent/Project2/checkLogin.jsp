<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h1>登录成功！</h1>
	<%
		Cookie c1 = new Cookie("username", "wusihao");
		Cookie c2 = new Cookie("password", "123");
		c1.setMaxAge(604800);
		c2.setMaxAge(604800);
		response.addCookie(c1);
		response.addCookie(c2);
	%>
	<jsp:forward page="home.jsp" />
</body>
</html>
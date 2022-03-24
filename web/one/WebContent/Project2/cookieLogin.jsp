<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>

<body bgcolor=pink>
<center>
	<%
		Cookie cookies[] = request.getCookies();
		String un = null;
		String pwd = null;
		if (cookies != null) {
			for (Cookie c : cookies) {
				if (c.getName().equals("username"))
					un = c.getValue();
				if (c.getName().equals("password"))
					pwd = c.getValue();
			}
		}
		if (un != null && pwd != null) {
	%>
	<jsp:forward page="home.jsp" />
	<%
		}
	%>

	<h1>登录页面</h1>
	<form action="checkLogin.jsp" method="post">
		username:<input type="text" name="un"><br> password:<input
			type="password" name="pwd"><br> <input type="submit"
			value="登录"><br>
	</form>
	</center>
</body>
</html>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>退出</title>
</head>
<body bgcolor=pink>
<center>
	<jsp:include page="insert.jsp"></jsp:include>
	<%
		session.invalidate();
		out.println("账号退出成功");
	%>
	<a href="login.jsp">登录</a>
	</center>
</body>
</html>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h1>登录页面</h1>
	<!-- action 作用： 请求访问哪个页面，在哪个页面响应，响应页面 
	Http 请求，请求方法：POST GET method 属性知名请求方法，默认的请求方法是 GET -->
	<form action="checkLogin.jsp" method="post">
		username:<input type="text" name="un"><br>
		password:<input type="password" name="pwd"><br>
	<input type="submit" value="登录"><br>
	</form>
	
<font color=pink size=6>33吴思豪</font>
</body>
</html>
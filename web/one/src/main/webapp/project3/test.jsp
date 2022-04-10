<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<%-- // 1.创建的java类实现Servlet接口， 2.继承HttpServlrt
Servlet
HttpServlet
--%>
<form action="one" method="post"> <!-- action="one" 不能写/ -->
	<input type="text" name="x"><br>
	<input type="text" name="y"><br>
	<input type="submit" value="提交" >
</form>
</body>
</html>
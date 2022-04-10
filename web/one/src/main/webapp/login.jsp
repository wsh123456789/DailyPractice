<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" 
import="java.util.*" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
var f=<%=request.getParameter("flag") %>
	if (f=='1')
		alert("用户名或密码输入错误！！！");
</script>
</head>
<body>
<h1>登录页面</h1>
<form action="login" method="post">
	username:<input type="text" name="username"><br><br>
	password:<input type="password" name="password"><br><br>
	<input type="submit" value="登录"><br><br>
</form>

</body>
</html>
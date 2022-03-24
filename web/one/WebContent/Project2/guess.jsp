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
		int number = (int) (Math.random() * 100) + 1;
		//系统生成的数放在session对象中
		session.setAttribute("number", number);
	%>
	系统已生成一个1-100之间的随机数
	<form action="judge.jsp" method="post">
		请输入您猜测的数字： <input type="text" name="guess"><br> <input
			type="submit" value="提交" />
	</form>
</body>
</html>
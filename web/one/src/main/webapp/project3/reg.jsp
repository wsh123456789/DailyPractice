<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8" import="b.RegBean"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body bgcolor="pink">
<form action="showReg.jsp" method="post">
用户名：<input type="text" name="username"><br><br>
口令：<input type="text" name="password"><br><br>
性别：<input type="radio" name="sex" value="男">男
	<input type="radio" name="sex" value="女">女<br><br>
爱好：<input type="checkbox" name="hobby" value="篮球">篮球
<input type="checkbox" name="hobby" value="足球">足球
<input type="checkbox" name="hobby" value="排球">排球<br><br>
附言：<textarea rows="5" cols="20" name="speaking">
</textarea><br><br>
<input type="submit" value="提交">
</form>
</body>
</html>

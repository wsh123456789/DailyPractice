<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8" import="b.RegBean"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
<%
request.setCharacterEncoding("utf-8");
%>
<jsp:useBean id="reg" class="b.RegBean" scope="page"/>
<jsp:setProperty property="*" name="reg"/>
您的用户名是：<jsp:getProperty property="username" name="reg" /><br><br>
您的口令是：<jsp:getProperty property="password" name="reg" /><br><br>
您的性别是：<jsp:getProperty property="sex" name="reg" /><br><br>
您的爱好是：
<%
String hobby[]=request.getParameterValues("hobby");
for(int i=0;i<hobby.length;i++)
	out.println(hobby[i]);
%><br><br>
您的附言是：<jsp:getProperty property="speaking" name="reg" /><br><br>
</body>
</html>

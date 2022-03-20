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
	request.setCharacterEncoding("utf-8");
	String answer=request.getParameter("choice");
	String name=request.getParameter("username");
	if(answer.equals("钱钟书")){
	%> <font color="red" size="5"><%=name %>恭喜！！回答正确，加2分！</font>
	<% 
	}
	else{
		%>
	<font size="5" color="red">回答错误！！！不得分</font>
	<%}
	%>
</body>
</html>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="java.io.*,java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	String uname = request.getParameter("un");
	String pword = request.getParameter("pwd");
	if(uname.equals("wusihao") && pword.equals("1910212133")){
		out.println(uname + "用户您好，欢迎登录至本系统~~~您可以选择您心仪的图书啦~~~");
		%>
		<form action="pay.jsp" method="post">
			<br><input type="checkbox" value="58" name="price">JSP使用教程 58.00 <br>
  			<input type="checkbox" value="40" name="price">大数据及可视化 40.00<br>
  			<input type="checkbox" value="36" name="price">数据结构 36.00<br>
  			<input type="checkbox" value="35" name="price">大学英语 35.00<br>
  			<input type="checkbox" value="60" name="price">数据挖掘 60.00<br>
  			<input type="checkbox" value="64" name="price">机器学习 64.00<br>
  			<input type="submit" value="去支付">
		</form>
		<%
	}
	else{
       String site = new String("failure.jsp");
	   response.setStatus(response.SC_MOVED_TEMPORARILY);
	   response.setHeader("Location", site); 
	}
	%>
</body>
</html>
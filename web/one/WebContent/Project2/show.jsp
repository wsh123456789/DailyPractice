<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.util.Enumeration" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
	<a href = "index.jsp">返回留言页面</a><br><br><br>
	<%
	Enumeration<String>e=application.getAttributeNames();
	while(e.hasMoreElements()){
		String key = e.nextElement();
		String regex = "[1-9][0-9]*";//匹配用户的关键字
		if(key.matches(regex)){
			String message = (String)application.getAttribute(key);
			String[] mess= message.split("#");
			out.println(mess[0]);//留言者和序号
			out.println(mess[1]);//标题
			out.println(mess[2]);//留言内容
			out.println(mess[3]);//留言时间
			out.println("<br>---------------------------------------<br>");
		}
	}
	%>
</body>
</html>
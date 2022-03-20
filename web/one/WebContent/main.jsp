<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor = pink>
	<font size=4 color=red>1910212133吴思豪</font>
	<%
	int r = 15;
	int a = 2, b = 3, h = 5;
	
	%>
	<h2>动态插入一个文件：circle.jsp, 实现求圆面积</h2>
	<jsp:include page = "circle.jsp">
		<jsp:param value = "<%=r %>"  name = "r"/>
	</jsp:include>
	<hr>
	<h2>动态插入一个文件：ladder.jsp, 实现求梯形面积</h2>
	<jsp:include page = "ladder.jsp">
		<jsp:param value="<%=a %>" name="a"/>
		<jsp:param value="<%=b %>" name="b"/>
		<jsp:param value="<%=h %>" name="h"/>
	</jsp:include>
</body>
</html>
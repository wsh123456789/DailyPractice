<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page  import="java.jk1.bean.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean id="stu" class="java.jk1.bean.Student" scope="page"/>
	<%=stu.getStuAge() %>
</body>
</html>
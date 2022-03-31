<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean id="cb" class="b.CaculateBean" scope="session"></jsp:useBean>
	<jsp:getProperty property="n1" name="cb"></jsp:getProperty>
	<jsp:getProperty property="op" name="cb"></jsp:getProperty>
	<jsp:getProperty property="n2" name="cb"></jsp:getProperty>&nbsp;=&nbsp;
	<jsp:getProperty property="result" name="cb"></jsp:getProperty>
</body>
</html>
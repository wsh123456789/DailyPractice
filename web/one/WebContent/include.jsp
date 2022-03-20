<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
	<jsp:include page="getArea.jsp">
		<jsp:param value="15" name="r"/>
	</jsp:include>
</body>
</html>
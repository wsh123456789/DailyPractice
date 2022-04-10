<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<!-- 添加、修改的共用页面    新书上架超链接   更新超链接-->
<!-- 修改：单价 -->

<form action="book?method=modify" method="post">
	
	<!-- 根据图书编号是否为空，决定显示添加页面还是修改页面 -->
	<c:if test="${empty param.bookID }">
		编号：<input type="text" name="bookID" value="${param.bookID }"><br><br>
		名称：<input type="text" name="bookName"><br><br>
		作者：<input type="text" name="bookAuthor"><br><br>
		出版社：<input type="text" name="publisher"><br><br>
	</c:if>
	
	<c:if test="${!empty param.bookID }">
		<input type="hidden" name="bookID" value="${param.bookID }"><br><br>
	</c:if>
	
	单价：<input type="text" name="bookPrice" value="${param.bookPrice}" ><br><br>
	
	<input type="submit" value="更新保存">
</form>
</body>
</html>
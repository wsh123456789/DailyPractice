<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<style>
	#textStyle{
		text-align:center;
	}
</style>
<body bgcolor=pink id="textStyle">
	<form action="pane.jsp" method="post">
		留言者:<input type="text" name="peopleName" size=40/>
		<br>主标题:<input type="text" name="title" size=40/>
		<br>留言:
		<textarea name="contents"  rows="10" cols="30" wrap='hard'>
		</textarea>
		<br><input type="submit" value="提交留言" name="submit">
	</form>
	<a href="show.jsp">查看留言</a>
	<a href="delete.jsp">删除留言</a>
</body>
</html>
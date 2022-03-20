<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor = pink>
<p>小说围城的作者是</p>
<form action="answer.jsp" method=post name=form>
	<input type="radio" name="choice" value="钱钟书">钱钟书
	<input type="radio" name="choice" value="海岩">海岩
	<input type="radio" name="choice" value="路遥">路遥
	<input type="radio" name="choice" value="韩涵">韩涵<br>
	<p></p>
	请输入姓名<input type="text" name="username" ><br>
	<input type="submit" name="submit" value="提交" >
</form> 
</body>
</html>

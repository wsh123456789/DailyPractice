<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"
 import="b.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<style>
	span{
		text-align: center;
	}
</style>
<body class="span" bgcolor=pink>
<form action="caculator.jsp" method="post">
	<input type="text" name="n1" size=20>
	<select name="op">
		<option value="+">+</option>
		<option value="-">-</option>
		<option value="*">*</option>
		<option value="/">/</option>
		<option value="%">%</option>
	</select>
	<input type="text" name="n2" size=20>
	<input type="submit" value="=" size=50>
</form>
</body>
</html>
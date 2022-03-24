<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
	<font size="4" color=red>您猜测的数字小于实际数值，再来一次：</font>
	<form action="judge.jsp" method="post">
		<input type="text" name="guess" /> <input type="submit"
			value="提交" />
	</form>

</body>
</html>
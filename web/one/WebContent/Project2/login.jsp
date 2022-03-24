<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>首页</title>
</head>

<body bgcolor=pink>
<center>
	<jsp:include page="insert.jsp"></jsp:include>
	<form action="" method=post>
		username:<input type="text" name="un"> <br>
		<br> paasword:<input type="password" name="ps"><br>
		<br> <input type="submit" value="登录"><br>
		<br>
	</form>
	<%
		String name = request.getParameter("un");
		String ps = request.getParameter("ps");
		if (session.getAttribute("name") != null) {
			out.println("你已登录，不可重复登录");
		} else {
			if (name != null && ps != null) {
				session.setAttribute("name", name);
				if (name.equals("wusihao") && ps.equals("123456")) {
					out.println("登陆成功");
				} else {
					out.println("用户账号或密码错误");
				}
			} else {
				out.println("请登录");
			}
		}
	%>
	</center>
</body>
</html>
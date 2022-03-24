<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="java.util.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>书</title>
</head>
<body bgcolor = pink>
	<center>
	<jsp:include page="insert.jsp"></jsp:include>
	<form method="post" action="">
		<input type="checkbox" name="check" value="Java程序设计 36.5">Java程序设计  ￥36.5<br>
		<br> <input type="checkbox" name="check" value="数据库原理 45">数据库原理  ￥45<br>
		<br> <input type="checkbox" name="check" value="操作系统 65.5">操作系统  ￥65.5<br>
		<br> <input type="checkbox" name="check" value="数据结构 35">数据结构  ￥35<br>
		<br> <input type="checkbox" name="check" value="web开发 40.5">web开发  ￥40.5<br>
		<br> <input type="submit" name="submit1" value="添加到购物车">
	</form>
	<%
		List book = (List) session.getAttribute("book");
		//out.println(book);
		request.setCharacterEncoding("UTF-8");
		String[] s = request.getParameterValues("check");
		if (book == null) {
			book = new ArrayList();
		}
		if (s != null) {
			for (int i = 0; i < s.length; i++)
				book.add(s[i]);
			session.setAttribute("book", book);
		}
	%>
	<form method="post" action="checkOut.jsp">
	<br> <input type="submit" name="submit1" value="结账">
	</form>
	</center>
</body>
</html>

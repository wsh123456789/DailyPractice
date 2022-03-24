<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="java.util.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
<center>
	<jsp:include page="insert.jsp"></jsp:include>
	<font size="5"><%
		if (session.getAttribute("name") == null) {
			out.println("该页面为授权页面，请先登录");
		} else {
			List b = (List) session.getAttribute("book");
			int sum = 0;//存放总金额
			if (b != null) {
				out.println("您购买了：" + "<br>");
				for (int i = 0; i < b.size(); i++) {
					String b1 = (String) b.get(i);
					String[] b2 = b1.split(" ");
					out.println(b2[0] +"   ￥" +  b2[1] + "<br>");
					sum += Double.parseDouble(b2[1]);
				}
				out.println("<br>");
				out.println("总金额为" +"   ￥"+ sum + "<br>");
			}
		}
	%></font>
	</center>
</body>
</html>

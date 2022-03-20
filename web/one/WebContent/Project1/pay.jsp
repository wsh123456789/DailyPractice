<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%

	String p[] = request.getParameterValues("price");
	int x = p.length;
	int t = 0;
	String[]  n = new String[x];
	for(int i = 0; i < x; i++){
		if("58".equals(p[i]))
			n[i] = "JSP实用教程";
		else if("40".equals(p[i]))
			n[i] = "大数据及可视化";
		else if("36".equals(p[i]))
			n[i] = "数据结构";
		else if("35".equals(p[i]))
			n[i] = "大学英语";
		else if("60".equals(p[i]))
			n[i] = "数据挖掘";
		else if("64".equals(p[i]))
			n[i] = "机器学习";
		else
			n[i] = "ssss";
	}
	out.println("您选择的图书如下所示：");
	%>
	<br>
	<%
	for(int i = 0; i < x; i++){
		out.println(n[i]+"  ");
		%>
		<br>
		<%
	}
	for(int i = 0; i < x; i++){
		int n1 = Integer.parseInt(p[i]);
		t+=n1;
	}
%>
<h1>您一共消费：<%=t %></h1>
</body>
</html>
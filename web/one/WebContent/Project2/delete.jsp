<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page  import="java.util.Enumeration"%>
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
	管理员删除留言.
	<form action=""  method=post>
		输入密码:<input type="password" name="password" size=12/><br>
		输入留言序号:<input type=text name="index" size=6>
		<br><input type="submit" name="submit" value="删除"/>
	</form>
	<%
	String password=request.getParameter("password");
	String index = request.getParameter("index");
	if(password==null)password="";
	if(index==null)index="";
	if(password.equals("123456")){
		Enumeration<String>e=application.getAttributeNames();
		while(e.hasMoreElements()){
			String key = e.nextElement();
			if(key.equals(index)){
				application.removeAttribute(key);
				out.println("<br>删除了第"+index+"条留言<br>");
			}
		}
	}
	%>
	<a href = "index.jsp">返回留言板</a>
	<a href = "show.jsp">查看留言板</a>
</body>
</html>
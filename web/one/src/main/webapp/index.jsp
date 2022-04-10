<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="UTF-8"  import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

<%
	Class.forName("com.mysql.jdbc.Driver");
	String url = "jdbc:mysql://localhost:3306/wusihao";
	String user = "root";
	String pwd = "wusihao.@123";
	Connection conn = DriverManager.getConnection(url,user,pwd);
	
	Statement stmt = conn.createStatement();
	String sql = "Select * from user2";
	ResultSet rs = stmt.executeQuery(sql);
	
%>
<table border=2 width=60%>
	<tr>
		<td>id</td><td>username</td><td>sex</td><td>info</td><td>操作</td>
	</tr>
	<%
		while(rs.next()){
			%>
		<tr>
			<td><%=rs.getInt("id") %></td>
			<td><%=rs.getString("username") %>
			<td><%=rs.getInt("sex") %></td>
			<td><%=rs.getString("info") %></td>
			<td><a href="update.jsp?id=<%=rs.getString("id") %>">修改</a>&nbsp;<a href="delete.jsp?id=<%=rs.getString("id") %>">删除</a></td>
		</tr>
	<%
		}
	
	%>
</table>
<%
	rs.close();
	stmt.close();
	conn.close();
%>
<a href="insert.jsp">录入用户信息</a><br>
	<%=conn %>
</body>
</html>
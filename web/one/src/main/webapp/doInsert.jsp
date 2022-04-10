<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
request.setCharacterEncoding("GBK");
%>
<%
int id = Integer.parseInt(request.getParameter("id"));
int sex = Integer.parseInt(request.getParameter("sex"));
String username = request.getParameter("username");
String info = request.getParameter("info");

//1.加载mysql的驱动程序
Class.forName("com.mysql.jdbc.Driver");//驱动程序类；全类名 com.mysql.cj.jdbd.Driver
//2.跟指定的数据库创建连接，前提你的mysql数据库是使用状态
	String url = "jdbc:mysql://localhost:3306/wusihao";
	String user = "root";
	String pwd = "wusihao.@123";
	Connection conn = DriverManager.getConnection(url,user,pwd);
//3.获取一个SQL语句，完成对数据库操作
Statement stmt = conn.createStatement();//创建一个SQL语句对象
String sql = "insert into user2 set id="+id+",username='"+username+"',sex="+sex+",info='"+info+"'";
int n = stmt.executeUpdate(sql);

if(n==1)
	response.sendRedirect("index.jsp");
%>


<%

stmt.close();
conn.close();
%>
</body>
</html>
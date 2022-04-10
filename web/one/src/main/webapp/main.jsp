<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"
 import="java.util.*,ch7.b.*"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<h1>在线图书管理后台主页面</h1>
<h2>图书的新书上架，图书信息的修改，查询，删除</h2>
<h2>MVC三层架构实现 图书管理：CURD  每一个请求对应一个 Servlet </h2>
<h2>评价管理   用户管理   图书类别   订单管理   权限管理</h2>
<h2>多个请求共用一个servlet？？？</h2>
<a href="book?method=queryAll" >查看图书信息  超链接默认GET</a><br><br>
<hr><br><br>

<!-- el表达式 -->
<%-- ${sessionScope.books} --%>

<%
List<BookBean> books = (List<BookBean>)session.getAttribute("books");
if(books!=null){
	
%>
<table>
	<tr>
		<td>id</td>
		<td>名称</td>
		<td>作者</td>
		<td>出版社</td>
		<td>单价</td>
		<td>操作</td>
	</tr>
	<%
	
	for(BookBean book:books) {//next() 返回值是一个布尔值，表示下一行记录是否存在，存在返回true
		%>
		<tr>
			<td><%=book.getBookID() %></td>
			<td><%=book.getBookName() %></td>
			<td><%=book.getBookAuthor() %></td>
			<td><%=book.getPubilsher() %></td>
			<td><%=book.getBookPrice() %></td>
			<!-- 修改和添加共用一个页面 -->
			<td><a href="saveBook.jsp?bookID=<%=book.getBookID()%>&bookPrice=<%= book.getBookPrice() %>">更新</a>&nbsp;&nbsp;
			<a href="book?method=delete&bookID=<%=book.getBookID() %>">删除</a></td>
		</tr>
		<%
	}
	%>
</table>
<%
}
%>

<br><br>
<a href="saveBook.jsp">新书上架</a>

</body>
</html>
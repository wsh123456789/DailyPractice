<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
 <%
 	String s=request.getParameter("guess");
 	int a=(int)(Math.random()*100+1);
 	int b=Integer.parseInt(s);
  	%>
  	<% 
  	if(b>a){ 
  	%>
  		<jsp:forward page="big.jsp"></jsp:forward>
  	<%
  	}
  	if(b<a){
  		%>
  		<jsp:forward page="small.jsp"></jsp:forward>
  	<%}
  	else{
  		out.println("猜对了");
  	}
  	%>
</body>
</html>
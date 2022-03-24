<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor="cyan">
	<h1>登录验证或响应页面</h1>
	
	<%--避免重复登录 ：用户是不是第一次登录--%>
	<%--从session获取用户名，如果获取到了，表示不是第一次登录，如果没有获取到，表示第一次登录，正常登录验证就可以 --%>
<%
String un = (String)session.getAttribute("username");  // 强制类型转换
if(un != null){
	out.println("您已经登录过了，请勿重复登录");
}
else{
	
%>
	
	<%
	String uname = request.getParameter("un");
	String pword = request.getParameter("pwd");
	// Java 强类型的编程语言，发送的登录请求是基于 HTTP 协议的，没类型 都是字符串
	if(uname.equals("aaa") && pword.equals("123")){
		// 用户密码都正确，用户可以登录成功该网站，立刻让session去保存用户登录信息
		session.setAttribute("username", uname);
		
		out.println("登录成功~~~"); // 跳转到系统首页
	}
	else
		out.println("登录失败！！！请先<a>注册</a>"); // 跳转到失败页面
	%>
<%
}
%>
</body>
</html>
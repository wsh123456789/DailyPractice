<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.time.LocalDateTime" %>
<%@ page import="java.util.Stack" %>
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
<body bgcolor=pink >
	<%!
	Stack<Integer>maxAmount = null;  //存放留言序号
	//向application添加对象的synchronized方法
	synchronized void addMess(ServletContext application,StringBuffer mess){
		int index=-1;               //留言序号
		if(!maxAmount.empty()){
			index = maxAmount.pop();
			mess.insert(0,"No."+index+".");
			application.setAttribute("" + index,new String(mess));
		}
	}
	%>
	<%
		if(maxAmount == null){
			maxAmount = new Stack<Integer>();
			for(int i = 999999; i >= 1; i--){ //最多有999999条留言
				maxAmount.push(i);
			}
		}
	boolean isSave = true;
	request.setCharacterEncoding("utf-8");
	String peopleName = request.getParameter("peopleName");
	String title = request.getParameter("title");
	String contents = request.getParameter("contents");
	if(peopleName.length()==0||title.length()==0||contents.length()==0){
		isSave = false;
		out.println("<h2>"+"请输入留言者，标题和内容");
		
	}
	if(isSave){
		LocalDateTime dateTime = LocalDateTime.now();
		StringBuffer message = new StringBuffer();
		message.append("留言者:"+peopleName+"#");
		message.append("<br>留言标题<<"+title+">>#");
		message.append("<br>留言内容:<br>"+contents+"#");
		String timeFormat = String.format("%tY年%<tm月%<td日,%<tH:%<tM:%<tS",dateTime);
		message.append("<br>留言时间<br>"+timeFormat+"#");
		if(maxAmount.empty()){
			out.println("<h2>"+"留言板已满，无法在留言"+"</h2>");
			
		}
		else{
			addMess(application,message); //信息存放到application(留言板角色)
		}
		}
	%>
	<br><a href = "index.jsp">返回留言板</a><br>
	<a href = "show.jsp">查看留言板</a>
</body>
</html>
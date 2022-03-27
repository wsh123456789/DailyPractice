<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"
 import="b.*"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor=pink>
<jsp:useBean id="compute" class="b.CaculateBean" scope="page"></jsp:useBean>
<jsp:setProperty property="*" name="compute"/>
<jsp:getProperty property="n1" name="compute"/>
<jsp:getProperty property="op" name="compute"/>
<jsp:getProperty property="n2" name="compute"/>&nbsp;=&nbsp;
<jsp:getProperty property="result" name="compute"/>
</body>
</html>
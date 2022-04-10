<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"
 import="b.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<style>
	span{
		text-align: center;
	}
</style>
<body id="span" bgcolor=pink>
<center>
<%request.setCharacterEncoding("UTF-8");
response.setCharacterEncoding("UTF-8"); %>
<jsp:useBean id="phone" class="b.PhoneBean" scope="page"></jsp:useBean>
<jsp:setProperty property="*" name="phone"/>
<table>
        <tr>
            <td>手机品牌</td>
            <td>手机颜色</td>
            <td>手机价格</td>
        </tr>
        <tr>
            <td><jsp:getProperty property="phoneBrand" name="phone"/></td>
            <td><jsp:getProperty property="phoneColor" name="phone"/></td>
            <td><jsp:getProperty property="phonePrice" name="phone"/></td>
        </tr>
</table>
</center>
</body>
</html>
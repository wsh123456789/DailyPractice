<%@tag pageEncoding="UTF-8"%>
<%@attribute name="sideA" required="true"%>
<%@attribute name="sideB" required="true"%>
<%
	out.println("<br>长：" + sideA + "宽：" + sideB);
	double a = Double.parseDouble(sideA);
	double b = Double.parseDouble(sideB);
	out.println("<br>矩形面积："+ a * b);
%>
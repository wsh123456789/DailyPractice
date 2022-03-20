<%@tag pageEncoding="UTF-8"%>
<%@attribute name="sideR" required="true"%>
<%
	out.println("<br>半径：" + sideR);
	double r = Double.parseDouble(sideR);
	out.println("<br>圆形面积："+ 3.14 * r*r);
%>
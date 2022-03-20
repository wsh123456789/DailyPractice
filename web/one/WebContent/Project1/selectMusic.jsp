<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%    
    request.setCharacterEncoding("UTF-8");
 %> 
<html>
      <body>
      <form action="" method=post name="form">
      	选择背景音乐：<br/><select  name="music">
      <option value="无问.mp3">无问</option>
      <option value="水星记.mp3">水星记</option>
      </select><br/>
      <%    
          String music = request.getParameter("music");
          if(music!=null){
        if(music.equals("无问.mp3")){
        out.println("<embed src='../music/无问.mp3' hidden='true' ></embed>");
        }else{
                out.println("<embed src='../music/水星记.mp3' hidden='true' ></embed>");
        }
        }
      %>
      <input type="submit" value="提交"/>
      </form>
      </body>
</html>
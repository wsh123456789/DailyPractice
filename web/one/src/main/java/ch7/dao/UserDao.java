package ch7.dao;

public interface UserDao {  //为什么要用接口，不直接创建类。考虑到项目的扩展、移植问题
	public Boolean queryUserByAndPwd(String username, String password);
}

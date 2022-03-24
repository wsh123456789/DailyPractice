package java.jk1.bean;

public class Student { 
	// Tomcat 响应请求时，为能找到 bean 的字节码文件class,要求必须放在指定目录
	// WEB-INF/classes/建立相应的包，存放字节码文件  java.jk1.bean/class
	
	
	// 1. 必须是共有类
	// 3. bean 属性必须私有化
	private String stuNum;  // 变量命名：驼峰命名法
	private String stuName;
	private int stuAge = 18;
	private String stuMajor;
	// 4. 成员变量对应的 get 和 set 方法
	// 方法名称：命名规范：（前缀）get+成员变量名（首字母大写） 一定要注意：定义成员变量的时候，首字母不能大写
	// 通过get方法获取bean的某个成员变量的值
	// 通过set方法可以设置bean的某个成员变量赋值
	// 2. 必须有无参构造方法，一旦自己定义带参的构造方法了，系统就不在提供默认的无参的构造方法了
	public String getStuNum() {
		return stuNum;
	}
	public String getStuName() {
		return stuName;
	}
	public String getStuMajor() {
		return stuMajor;
	}
	public int getStuAge() {
		return stuAge;
	}
	
	public void setStuName(String stuName) {
		this.stuNum=stuName;
	}
	
	public void setStuNum(String stuNum) {
		this.stuNum = stuNum;
	}
	public void setStuAge(int stuAge) {
		this.stuAge = stuAge;
	}
	public void setStuMajor(String stuMajor) {
		this.stuMajor = stuMajor;
	}
	

}

package b;

public class UserBean {
	private String username;
	private String password;
	public UserBean(String username, String password) {
		this.username=username;
		this.password=username;
	}
	public UserBean() {
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
}

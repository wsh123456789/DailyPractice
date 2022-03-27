package b;

public class CaculateBean {
	private int n1;
	private int n2;
	private String op;
	private int result;

	public int getN1() {
		return n1;
	}
	public void setN1(int n1) {
		this.n1 = n1;
	}
	public int getN2() {
		return n2;
	}
	public void setN2(int n2) {
		this.n2 = n2;
	}
	public String getOp() {
		return op;
	}
	public void setOp(String op) {
		this.op = op;
	}
	
	public int getResult() { 
		if("+".equals(op))   
			result = n1 + n2;
		else if("-".equals(op))
			result = n1 - n2;
		else if("*".equals(op))
			result = n1 * n2;
		else if("/".equals(op))
			result = n1 / n2;
		else if("%".equals(op))
			result = n1 % n2;
		return result;
	}
	
	
}

package ch7.b;

public class BookBean {
	private String bookID;
	private String bookName;
	private String bookAuthor;
	private String pubilsher;
	private double bookPrice;
	
	
	
	@Override
	public String toString() {
		return "BookBean [bookID=" + bookID + ", bookName=" + bookName + ", bookAuthor=" + bookAuthor + ", pubilsher="
				+ pubilsher + ", bookPrice=" + bookPrice + "]";
	}

	public String getBookID() {
		return bookID;
	}

	public void setBookID(String bookID) {
		this.bookID = bookID;
	}

	public String getBookName() {
		return bookName;
	}
	public void setBookName(String bookName) {
		this.bookName = bookName;
	}
	public String getBookAuthor() {
		return bookAuthor;
	}
	public void setBookAuthor(String bookAuthor) {
		this.bookAuthor = bookAuthor;
	}
	public String getPubilsher() {
		return pubilsher;
	}
	public void setPubilsher(String pubilsher) {
		this.pubilsher = pubilsher;
	}
	public double getBookPrice() {
		return bookPrice;
	}
	public void setBookPrice(double bookPrice) {
		this.bookPrice = bookPrice;
	}
	
}

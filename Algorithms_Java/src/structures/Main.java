package structures;

public class Main {
	public static void main(String[] args) {
		LinkedList<String> list = new LinkedList<>();

		list.add("1");
		list.add("2");
		list.add("3");
		list.add("4");
		list.add("5");

		list.remove("3");

		System.out.println(list);
	}
}

package structures;

public class Queue<T> {

	private LinkedList<T> data;

	public Queue() {
		data = new LinkedList<>();
	}
	
	public void insert(T value) {
		data.add(value);
	}
	
	public T get() {
		T value = data.get(0);
		
		data.remove(value);
		
		return value;
	}
	
	public int size() {
		return data.size();
	}
}
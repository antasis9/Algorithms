package structures;

import structures.Graph.Vertex;

public class Main {
	public static void main(String[] args) {
//		LinkedList<String> list = new LinkedList<>();
//
//		list.add("1");
//		list.add("2");
//		list.add("3");
//		list.add("4");
//		list.add("5");
//
//		list.remove("3");
//
//		System.out.println(list);
		
		Heap<Integer> heap = new Heap<>(1);
		heap.insert(5);
		System.out.println(heap);
		
		heap.insert(2);
		System.out.println(heap);
		
		heap.insert(1);
		System.out.println(heap);
		
		heap.insert(4);
		System.out.println(heap);
		
		heap.insert(-1);
		System.out.println(heap);
		
		System.out.println("Deleted Value: " + heap.delete());
		System.out.println(heap);
		
		System.out.println("Deleted Value: " + heap.delete());
		System.out.println(heap);
		
		System.out.println("Deleted Value: " + heap.delete());
		System.out.println(heap);
		
		System.out.println("Deleted Value: " + heap.delete());
		System.out.println(heap);
		
		System.out.println("Deleted Value: " + heap.delete());
		System.out.println(heap);
	}
}

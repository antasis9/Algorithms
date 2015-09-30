package structures;

public class LinkedList<T> {
	private Node<T> headNode;
	private Node<T> tailNode;

	public LinkedList() {
		headNode = new Node<>();
		tailNode = new Node<>();

		headNode.prevNode = null;
		headNode.nextNode = tailNode;

		tailNode.prevNode = headNode;
		tailNode.nextNode = null;
	}

	public void add(T value) {
		Node<T> oldPrevNode = tailNode.prevNode;

		Node<T> newNode = new Node<>();

		newNode.prevNode = tailNode.prevNode;
		newNode.nextNode = tailNode;
		newNode.value = value;

		oldPrevNode.nextNode = newNode;
		tailNode.prevNode = newNode;
	}

	public boolean remove(T value) {
		Node<T> prevNode;
		Node<T> nextNode;

		Node<T> currentNode = headNode.nextNode;

		while (currentNode != tailNode) {
			if (currentNode.value.equals(value)) {
				prevNode = currentNode.prevNode;
				nextNode = currentNode.nextNode;

				prevNode.nextNode = nextNode;
				nextNode.prevNode = prevNode;

				return true;
			}

			currentNode = currentNode.nextNode;
		}

		return false;
	}

	@Override
	public String toString() {
		Node<T> currentNode = headNode.nextNode;

		StringBuilder builder = new StringBuilder();
		builder.append("[List] =====\n");

		while (currentNode != tailNode) {
			builder.append("Value: " + currentNode.value + "\n");

			currentNode = currentNode.nextNode;
		}

		builder.append("[List] =====\n");

		return builder.toString();
	}

	private static class Node<T> {
		private Node<T> prevNode;
		private Node<T> nextNode;
		private T value;
	}
}
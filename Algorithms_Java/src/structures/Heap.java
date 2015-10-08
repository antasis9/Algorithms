package structures;

public class Heap<T extends Comparable<T>> {
	private final static int DEFAULT_CAPACITY = 10;

	private int maxCapacity;
	private int usedCapacity;

	private Node nodes[];

	public Heap() {
		this(DEFAULT_CAPACITY);
	}

	public Heap(int defaultCapacity) {
		nodes = new Node[defaultCapacity];

		maxCapacity = defaultCapacity;
		usedCapacity = 0;
	}

	public void insert(T value) {
		if (usedCapacity == maxCapacity) {
			maxCapacity += maxCapacity;

			Node[] newNodes = new Node[maxCapacity];

			System.arraycopy(nodes, 0, newNodes, 0, usedCapacity);

			nodes = newNodes;
		}

		Node newNode = new Node();
		newNode.value = value;

		// 마지막에 데이터 삽입
		nodes[usedCapacity] = newNode;

		// used capacity를 1 증가시킨다.
		usedCapacity++;

		int newNodeIndex = usedCapacity - 1;

		while (true) {
			Node parent = getParentNode(newNodeIndex);

			if (parent == null) {
				System.out.println("The parent is null.");

				break;
			}

			Comparable<T> parentValue = (Comparable<T>) parent.value;
			T currentValue = (T) newNode.value;

			if (parentValue.compareTo(currentValue) <= 0) {
				break;
			} else {
				int parentNodeIndex = (int) (newNodeIndex - 0.5) / 2;

				nodes[parentNodeIndex] = newNode;
				nodes[newNodeIndex] = parent;

				System.out.println("Swap: " + newNode.value + "(Child) <-> " + parent.value + "(Parent)");

				newNodeIndex = parentNodeIndex;
			}
		}
	}

	private Node getParentNode(int index) {
		if (index == 0) {
			return null;
		}

		index = (int) (index - 0.5);

		return nodes[index / 2];
	}

	private Node getLeftChildNode(int index) {
		int leftChildNodeIndex = 2 * index + 1;

		if (leftChildNodeIndex > usedCapacity - 1) {
			return null;
		}

		return nodes[leftChildNodeIndex];
	}

	private Node getRightChildNode(int index) {
		int rightChildNodeIndex = 2 * index + 2;

		if (rightChildNodeIndex > usedCapacity - 1) {
			return null;
		}

		return nodes[rightChildNodeIndex];
	}

	private int compare(int sourceIndex, int targetIndex) {
		Comparable<T> targetChildValue = (Comparable<T>) nodes[targetIndex].value;
		T sourceValue = (T) nodes[sourceIndex].value;

		if (targetChildValue.compareTo(sourceValue) < 0) {
			return 1;
		} else if (targetChildValue.compareTo(sourceValue) == 0) {
			return 0;
		} else {
			return -1;
		}
	}

	private int compare(Node sourceNode, Node targetNode) {
		Comparable<T> targetChildValue = (Comparable<T>) targetNode.value;
		T sourceValue = (T) sourceNode.value;

		if (targetChildValue.compareTo(sourceValue) < 0) {
			return 1;
		} else if (targetChildValue.compareTo(sourceValue) == 0) {
			return 0;
		} else {
			return -1;
		}
	}

	public T delete() {
		if (usedCapacity == 0) {
			System.out.println("There is no node.");

			return null;
		}

		Node rootNode = nodes[0];

		if (usedCapacity == 1) {
			usedCapacity = 0;
			
			return (T) rootNode.value;
		}

		nodes[0] = nodes[usedCapacity - 1];
		usedCapacity -= 1;

		int currentNodeIndex = 0;

		while (true) {
			Node currentNode = nodes[currentNodeIndex];
			Node leftChildNode = getLeftChildNode(currentNodeIndex);
			Node rightChildNode = getRightChildNode(currentNodeIndex);
			int leftChildNodeIndex = 2 * currentNodeIndex + 1;
			int rightChildNodeIndex = 2 * currentNodeIndex + 2;
			Node targetChildNode = leftChildNode;
			int targetChildNodeIndex = leftChildNodeIndex;

			if (leftChildNode == null) {
				break;
			}

			if (rightChildNode != null) {
				int compareResult = compare(leftChildNode, rightChildNode);

				if (compareResult > 0) {
					targetChildNode = rightChildNode;
					targetChildNodeIndex = rightChildNodeIndex;
				}
			}

			if (compare(currentNode, targetChildNode) < 0) {
				break;
			} else {
				nodes[currentNodeIndex] = targetChildNode;
				nodes[targetChildNodeIndex] = currentNode;

				currentNodeIndex = targetChildNodeIndex;
			}
		}

		return (T) rootNode.value;
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();

		for (int i = 0; i < usedCapacity; i++) {
			builder.append("Value: " + nodes[i].value + "\n");
		}

		return builder.toString();
	}

	public static class Node {
		private Object value;
	}
}
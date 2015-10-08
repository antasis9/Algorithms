package structures;

public class Graph<T> {
	private LinkedList<Vertex<T>> vertices;

	public Graph() {
		vertices = new LinkedList<>();
	}

	public Vertex<T> addVertex(T value) {
		Vertex<T> vertex = new Vertex<>(value);

		vertices.add(vertex);

		return vertex;
	}

	public Edge<T> addEdge(int weight, Vertex<T> from, Vertex<T> to) {
		Edge<T> edge = new Edge<>();
		edge.weight = weight;
		edge.from = from;
		edge.to = to;

		from.edges.add(edge);

		return edge;
	}

	public void DFS() {
		DFSInternal(vertices.get(0));
	}

	private void DFSInternal(Vertex<T> vertex) {
		if (vertex.visited) {
			return;
		}

		vertex.visited = true;

		System.out.println("Visited: " + vertex.value);

		for (int i = 0; i < vertex.edges.size(); i++) {
			Edge<T> edge = vertex.edges.get(i);

			DFSInternal(edge.to);
		}
	}

	public void BFS() {
		Vertex<T> originVertex = vertices.get(0);
		originVertex.visited = true;
		
		Queue<Vertex<T>> queue = new Queue<>();

		queue.insert(originVertex);
		
		System.out.println("Visited: " + originVertex.value);

		while (true) {
			if (queue.size() == 0) {
				break;
			}

			Vertex<T> vertex = queue.get();

			for (int i = 0; i < vertex.edges.size(); i++) {
				Vertex<T> toVertex = vertex.edges.get(i).to;

				if (toVertex.visited == false) {
					toVertex.visited = true;

					System.out.println("Visited: " + toVertex.value);

					queue.insert(toVertex);
				}
			}
		}
	}

	public static class Vertex<T> {
		private LinkedList<Edge<T>> edges;
		private T value;
		private boolean visited;

		public Vertex(T value) {
			this.edges = new LinkedList<>();
			this.value = value;
		}
	}

	private static class Edge<T> {
		private int weight;
		private Vertex<T> from;
		private Vertex<T> to;
	}
}

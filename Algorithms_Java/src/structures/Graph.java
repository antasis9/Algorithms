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

	public static class Vertex<T> {
		LinkedList<Edge<T>> edges;
		T value;

		public Vertex(T value) {
			this.edges = new LinkedList<>();
			this.value = value;
		}
	}

	private static class Edge<T> {
		int weight;
		Vertex<T> from;
		Vertex<T> to;
	}
}

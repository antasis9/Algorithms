package structures;

import structures.Graph.Vertex;

public class Main {
	public static void main(String[] args) {
		Graph<String> graph = new Graph<>();
		
		Vertex<String> vertex1 = graph.addVertex("1");
		Vertex<String> vertex2 = graph.addVertex("2");
		Vertex<String> vertex3 = graph.addVertex("3");
		Vertex<String> vertex4 = graph.addVertex("4");
		Vertex<String> vertex5 = graph.addVertex("5");
		Vertex<String> vertex6 = graph.addVertex("6");
		Vertex<String> vertex7 = graph.addVertex("7");
		
		graph.addEdge(0, vertex1, vertex2);
		graph.addEdge(0, vertex1, vertex3);
		
		graph.addEdge(0, vertex2, vertex4);
		graph.addEdge(0, vertex2, vertex5);
		
		graph.addEdge(0, vertex3, vertex4);
		graph.addEdge(0, vertex3, vertex6);
		
		graph.addEdge(0, vertex4, vertex5);
		graph.addEdge(0, vertex4, vertex7);
		
		graph.addEdge(0, vertex5, vertex7);
		
		graph.addEdge(0, vertex6, vertex7);
		
		graph.BFS();
	}
}

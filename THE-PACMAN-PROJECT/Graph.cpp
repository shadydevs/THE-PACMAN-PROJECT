//#include "Graph.h"
//Graph::Graph(const int& p_Vertices) : Vertices(p_Vertices) {
//	AdjList = new vector<int>[Vertices];
//}
//
//void Graph::AddEdge(int u, int v) {
//	AdjList[u].push_back(v);
//}
//
//void Graph::BFS(int src) //src is the index in ghraph where the pacman is standing
//{
//	cout << "Breadth-First Search.\n";
//	queue<int> q;
//	vector<bool> visited(Vertices, false);//vertices is the number in the grid
//	q.push(src);//were do i check to make the 
//	visited[src] = true;
//	vector<int>::iterator i;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		cout << u << " ";
//		for (i = AdjList[u].begin(); i != AdjList[u].end(); i++) {
//			int node = *i;
//			if (visited[node] == false) {
//				visited[node] = true;
//				q.push(node);
//			}
//		}
//	}
//	cout << endl;
//}
//
//Graph::~Graph() {
//	delete[]AdjList;
//}
//int main()
//{
//	public void findNeighbors(int row, int col)
//	{
//		for (int r = -1; r <= 1; r++)
//		{
//			for (int c = -1; c <= 1; c++)
//			{
//				try {
//					if (matrix[row + r][col + c] != '#')
//						nodes[row][col].addEdge(nodes[row + r][col + c]);
//				}
//				catch (ArrayIndexOutOfBoundsException e) {}
//			}
//		}
//	}
//	int main() {
//		nodes = new Node[matrix.length][matrix[0].length]; //instance variable
//
//		for (int row = 0; row < matrix.length; row++)
//		{
//			for (int col = 0; col < matrix[row].length; col++)
//			{
//				char type = matrix[row][col];
//				if (type != '#')
//				{
//					Node n = new Node();
//					nodes[row][col] = n; //constructor to determine type of node
//					if (type == 'S')
//						startNode = n;
//					else if (type == 'E')
//						endNode = n;
//
//					findNeighbors(row, col); //assuming nodes and matrix variables are instance variables
//				}
//				else
//					nodes[row][col] = null;
//			}
//		}
//
//	}
//
//}

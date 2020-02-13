#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/*
	printDFS() & printBFS() - prints out connected graphs.
	DFS() & BFS() - for disconnected graphs.Checks out visited array if all the vertices are visited, if not then call printBFS()/printDFS() for that particular vertex.
*/

//sv - starting vertex
void printDFS(int** edges, int n, int sv, bool* visited){	
	cout << sv << endl;
	visited[sv] = true;
	for(int i = 0; i < n; i++){
		if(i == sv){
			continue;
		}
		if(edges[sv][i] == 1){	
			if(visited[i]){
				continue;		//to avoid endless loop b/w 2vertices of same edge
			}
			printDFS(edges, n, i, visited);
		}
	}
}

void printBFS(int** edges, int n, int sv, bool* visited){
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = true;	
	while(!pendingVertices.empty()){
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		cout << currentVertex << endl;

		for(int i = 0; i < n; i++){
			if(i == currentVertex){
				continue; //checking for 0-0 
			}
			if(edges[currentVertex][i] == 1 && !visited[i]){
 				pendingVertices.push(i);
				visited[i] = true;
			}
		}
	}
}

void DFS(int** edges, int n){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			printDFS(edges, n, i, visited);
		}
	}

	delete [] visited;
}

void BFS(int** edges, int n){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			printBFS(edges, n, i, visited);
		}
	}

	delete [] visited;
}

/*
TODO
	hasPath()	- cleanup
	getPathDFS()
	getPathBFS()
	isConnected()
	allConnectedComponents()

*/

int main(){
	int n;
	int e;
	cin >> n >> e;
	//n nodes, e edges

	int** edges = new int*[n];	//Adjacency Matrix.
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for (int j = 0; j < n; j++){
			edges[i][j] = 0;	// Fill 2d arrays with 0's
		}
	}

	for(int i = 0; i < e; i++){	//fill Adjacency Matrix
		int f, s;		//take input edges
		cin >> f >> s;
		edges[f][s] = 1;	//mark edges 1
		edges[s][f] = 1;
	}

/*
	bool* visited = new bool[n];		//visited array is specific to each DFS or BFS. So we'll create it there.
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
*/
	cout << "DFS:" << endl;
	// printDFS(edges, n, 0, visited);	//not gonna pass visited and startingVertex for disconnected graphs.
	DFS(edges, n);	//passing only graph & no. of vertices.

 	cout << "BFS:" << endl;
 	// printBFS(edges, n, 0);
 	BFS(edges, n);

	for(int i = 0; i < n; i++){
		delete [] edges[i];
	}
	delete [] edges;
	// delete [] visited;
}
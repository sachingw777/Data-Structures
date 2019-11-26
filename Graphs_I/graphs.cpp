#include <iostream>
using namespace std;

//DFS
//sv - starting vertex
void print(int** edges, int n, int sv, bool* visited){	
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
			print(edges, n, i, visited);
		}
	}
}

void printBFS(int** edges, int n, int sv){
	queue<int> pendingVertices;
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

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
	delete [] visited;
}

int main(){
	int n;
	int e;
	cin >> n >> e;
	//n nodes, e edges

	int** edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for (int j = 0; j < n; j++){
			edges[i][j] = 0;	// Fill 2d arrays with 0's
		}
	}

	for(int i = 0; i < e; i++){
		int f, s;		//take input edges
		cin >> f >> s;
		edges[f][s] = 1;	//mark edges 1
		edges[s][f] = 1;
	}

	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	print(edges, n, 0, visited);
}
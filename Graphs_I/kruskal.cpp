#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
public:
	int source;
	int destination;
	int weight;
};

bool compare(Edge first, Edge second){
	return (first.weight < second.weight);	
	//This is how we sort based on a parameter. if true then order is correct of the elements. 
}

int findParent(int v, int* parents){
	if(parents[v] == v){
		return v;
	}
	return findParent(parents[v], parents);
}

Edge* kruskals(Edge* input, int n, int e){
	sort(input, input + n, compare); //sort based on weight.
	Edge* output = new Edge[n - 1];	// n-1 edges in output MST.

	int *parents = new int[n];
	for(int i = 0; i < n; i++){
		parents[i] = i;
	}

	int count = 0;	//count for no. of edges in output array.
	int i = 0;	//
	while(count < n - 1){
		Edge current = input[i];

		int parent_one = findParent(current.source, parents);
		int parent_second = findParent(current.destination, parents);

		if(parent_one != parent_second){
			//1. increase count.
			//2. update parents array.
			output[count] = current;
			count++;
			parents[parent_one] = parent_second; 	
		}
		i++;
	}

	delete [] parents;
	return output;
}

int main(){
	int n, e;
	cin >> n >> e;

	Edge *input = new Edge[e];

	for(int i = 0; i < e; i++){
		int s, d, w;
		cin >> s >> d >> w;

		input[i].source = s;
		input[i].destination = d;
		input[i].weight = w;
	}

	Edge* output = kruskals(input, n, e);

	for(int i = 0; i < n - 1; i++){
		Edge current = output[i];
		if(current.source < current.destination){
			cout << current.source << " " << current.destination << " " << current.weight << endl;
		}else{
			cout << current.destination << " " << current.source << " " << current.weight << endl;
		}
	}

	delete [] input;
	delete [] output;
	return 0;
}
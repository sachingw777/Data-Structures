#include <iostream>
#include <vector>
using namespace std;

vector<int>* getPath(int** edges, int n, int sv, int ev, bool* visited){
    if(sv == ev){
        vector<int>* ans = new vector<int>;
        ans->push_back(ev);
        return ans;
    }

    visited[sv] = true;
    
    for(int i = 0; i < n; i++){
        if(edges[sv][i] == 1 && !visited[i]){
            vector<int>* small = getPath(edges, n, i, ev, visited);
            if(small != NULL){
                small->push_back(sv);
                return small;
            }
        }
    }
    return NULL;
}

vector<int>* getPath(int** edges, int n, int sv, int ev){
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
   
    vector<int>* ans = getPath(edges, n, sv, ev, visited);
    delete [] visited;
    return ans;
}

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

    int tempX, tempY;
    cin >> tempX >> tempY;
    
    vector<int>* ans = getPath(edges, n, tempX, tempY);
    if(ans != NULL){
        for(int i = 0; i < ans->size(); i++){
            cout << ans->at(i) << " ";      
        }   
    }    
    delete ans;
    
    for(int i = 0; i < n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    // delete [] visited;
}
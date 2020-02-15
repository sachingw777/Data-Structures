#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int>* getPathDFS(int** edges, int n, int sv, int ev, bool* visited){
    if(sv == ev){
        vector<int>* ans = new vector<int>;
        ans->push_back(ev);
        return ans;
    }

    visited[sv] = true;
    
    for(int i = 0; i < n; i++){
        if(edges[sv][i] == 1 && !visited[i]){
            vector<int>* small = getPathDFS(edges, n, i, ev, visited);
            if(small != NULL){
                small->push_back(sv);
                return small;
            }
        }
    }
    return NULL;
}

vector<int>* getPathDFS(int** edges, int n, int sv, int ev){
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
   
    vector<int>* ans = getPathDFS(edges, n, sv, ev, visited);
    delete [] visited;
    return ans;
}


vector<int>* getPathBFS(int** edges, int n, int sv, int ev){
    vector<int>* output = new vector<int>;
    unordered_map<int, int> map;
    queue<int> q;
    q.push(sv);
    bool* visited = new bool[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    visited[sv] = true;
    bool flag = false;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i = 0; i < n; i++){
            if(edges[front][i] == 1 && !visited[i]){
                map[i] = front;
                q.push(i);
                visited[i] = true;

                if(i == ev){
                    flag = true;
                    break;
                }
            }
        }
    }
    if(!flag){
        return NULL;
    }else{
        int current = ev;
        output->push_back(ev);
        while(current != sv){
            current = map[current];
            output->push_back(current);
        }
    }

    delete [] visited;
    return output;
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
    
    vector<int>* ansDFS = getPathDFS(edges, n, tempX, tempY);
    vector<int>* ansBFS = getPathBFS(edges, n, tempX, tempY);

    cout << "DFS Path:- " << endl;
    if(ansDFS != NULL){
        for(int i = 0; i < ansDFS->size(); i++){
            cout << ansDFS->at(i) << " ";      
        }   
    }    
    delete ansDFS;

    cout << endl <<  "BFS Path:- " << endl;
    if(ansBFS != NULL){
        for(int i = 0; i < ansBFS->size(); i++){
            cout << ansBFS->at(i) << " ";      
        }   
    }    
    delete ansBFS;

    
    for(int i = 0; i < n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    // delete [] visited;
}
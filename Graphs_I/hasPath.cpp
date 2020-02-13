#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

bool hasPath(unordered_map<int, vector<int>*> &adjacenyList, unordered_map<int, bool> &visited, int v1, int v2){
    vector<int>* v1_list = adjacenyList[v1];    //like a temp pointer to traverse through
    for(int i = 0; i < v1_list -> size(); i++){
        if(v1_list -> at(i) == v2){
            return true;
        }
    }
    visited[v1] = true;
    for(int i = 0; i < v1_list -> size(); i++){
        if(visited.count(v1_list -> at(i)) == 0){
            bool ans = hasPath(adjacenyList, visited, v1_list->at(i), v2);
            if(ans){
                return true;
            }
        }	
    }
    return false;
}

bool hasPath(unordered_map<int, vector<int>*> &adjacenyList, int v1, int v2){
    unordered_map<int, bool> visited;
    return hasPath(adjacenyList, visited, v1, v2);
}

int main(){
    int n;
    int e;
    cin >> n >> e; //n nodes, e edges

    //Adjacency List Method
    unordered_map<int, vector<int>*> adjacenyList;
    for(int i = 0; i < n; i++){
        vector<int>* v = new vector<int>;
        adjacenyList[i] = v;
    }

    int count = 1;
    while(count <= e){
        int f, s;
        cin >> f >> s;
        adjacenyList[f] -> push_back(s);
        adjacenyList[s] -> push_back(f);
        count++;
    }

    int v1, v2; 
    cin >> v1 >> v2;

    bool ans = hasPath(adjacenyList, v1, v2);
    if(ans){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    for(int i = 0; i < n; i++){
        vector<int>* v = adjacenyList[i];
        delete [] v;
    }
}
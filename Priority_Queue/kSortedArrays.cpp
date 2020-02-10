#include <queue>
#include <vector>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v;
    for(int i = 0; i < input.size(); i++){
    	for(int j = 0; j < input[i]->size(); j++){
    		pq.push(input[i]->at(j));
    	}
    }

    while(!pq.empty()){
    	v.push_back(pq.top());
    	pq.pop();
    }
    return v;
}
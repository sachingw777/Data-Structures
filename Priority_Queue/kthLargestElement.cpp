#include <queue>
using namespace std;
int kthLargest(vector<int> arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int i = 0;
    for(i ; i < k; i++){
        pq.push(arr[i]);
    }
    
    int j = 0;
    for(i ; i < n; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
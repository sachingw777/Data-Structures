#include <queue>

void reverseQueue(queue<int> &q) {
    if(q.size() = 1){
        return;
    }
    int helper = q.front();
    q.pop();
    reverseQueue(q);
    q.push(helper);
}

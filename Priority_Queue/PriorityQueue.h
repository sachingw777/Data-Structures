#include <vector>

class PriorityQueue{
	vector<int> pq;

public:
	PriorityQueue(){

	}

	bool isEmpty(){
		return pq.size() == 0;
	}

	int getSize(){
		return pq.size(); 
	}

	int getMin(){
		if(isEmpty()){
			return 0; 		//Priority Queue is Empty
		}
		return pq[0];
	}

};
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	unordered_map<int,bool> visitedElements;
	unordered_map<int,int> indexMap;

	for(int i = 0; i < n; i++){
        indexMap[arr[i]] = i;
		visitedElements[arr[i]] = true;
	}

	vector<int> longestSequence;

	int globalMaxSequenceLength = 1;
	int globalStartIndex = 0;

	for(int i = 0; i < n; i++){		
		int count = 0;
		int currentStartIndex = i;
		int num = arr[i];
		int tempNum = num;

		while(visitedElements[tempNum] != false){	//forward seq. check
			count++;
			visitedElements[tempNum] = false;
			tempNum++;
		}

		tempNum = num - 1;
		while(visitedElements[tempNum] != false){	//backward seq. check
			visitedElements[tempNum] = false;
			count++;
			currentStartIndex = indexMap[tempNum];
			tempNum--;
		}

		if(count > globalMaxSequenceLength){
			globalMaxSequenceLength = count;
			globalStartIndex = currentStartIndex;
		}else if(count == globalMaxSequenceLength){
			if(currentStartIndex < globalStartIndex){
				globalStartIndex = currentStartIndex;
			}
		}
	}

	int globalStartNum = arr[globalStartIndex];
	while(globalMaxSequenceLength != 0){        //Fill vector with seq.
		longestSequence.push_back(globalStartNum);
		globalMaxSequenceLength--;
		globalStartNum++;
	}
	return longestSequence;
}
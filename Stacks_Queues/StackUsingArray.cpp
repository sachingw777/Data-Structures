#include <climits>

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
        StackUsingArray(int totalSize){
            data = new int[totalSize];
            nextIndex = 0;
            capacity = totalSize;
        }

        int size(){
            return nextIndex;
        }
}
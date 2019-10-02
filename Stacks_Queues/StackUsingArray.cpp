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

        bool isEmpty(){
            return nextIndex == 0;
        }

        int top(){
            if(isEmpty()){
                cout << "Stack Empty";
                return INT_MIN;
            }

            return data[nextIndex - 1];
        }

        void push(int element){
            if(nextIndex == capacity){
                // cout << "Stack is Full";
                int *newData = new int[capacity * 2];
                delete [] data;
                data = newData;
            }
            data[nextIndex] = element;
            nextIndex++;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Empty";
                return INT_MIN;
            }
            nextIndex--;
            return data[nextIndex];
        }
};
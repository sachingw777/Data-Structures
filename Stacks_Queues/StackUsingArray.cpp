#include <climits>

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
        StackUsingArray(){      // No need for totalSize because Dynamic Array is in place. make objec and then run straight away.
            data = new int[5];
            nextIndex = 0;
            capacity = 5;
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
                for(int i = 0; i < capacity; i++){
                    newData[i] = data[i];
                }
                capacity *= 2;
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
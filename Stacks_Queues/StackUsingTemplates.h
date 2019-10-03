template <typename T>
class StackUsingTemplates{
    T *data;
    int nextIndex;
    int capacity;

    public:
        StackUsingTemplates(){
            data = new T[5];
            nextIndex = 0;
            capacity = 5;
        }

        int size(){
            return nextIndex;
        }

        bool isEmpty(){
            return nextIndex == 0;
        }

        T top(){
            if(isEmpty()){
                cout << "Stack Empty";
                return 0;   // 0 works great for all data types. Because it is using ASCII Value.
            }

            return data[nextIndex - 1];
        }

        void push(T element){
            if(nextIndex == capacity){
                // cout << "Stack is Full";
                T *newData = new T[capacity * 2];
                for(T i = 0; i < capacity; i++){
                    newData[i] = data[i];
                }
                capacity *= 2;
                delete [] data;
                data = newData;
            }
            data[nextIndex] = element;
            nextIndex++;
        }

        T pop(){
            if(isEmpty()){
                cout << "Stack Empty";
                return 0;
            }
            nextIndex--;
            return data[nextIndex];
        }
};

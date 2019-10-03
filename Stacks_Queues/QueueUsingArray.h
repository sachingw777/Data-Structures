template <typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:

    QueueUsingArray(T s){
        data = new T[s];
        nextIndex = 0, firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return (size == 0);
    }

    T front(){
      if(firstIndex == -1){
        cout << "Queue Empty";
        return 0;
      }
      return data[firstIndex];
    }

    void enqueue(T element){
      if(size == capacity){
        // cout << "Queue Full";
        T *newData = new T[capacity * 2];
        //  Cannot copy in the same order.
        // for(T i = 0; i < capacity;
        //     newData[i] = data[i];
        // }

        int j = 0;
        for(int i = firstIndex; i < capacity; i++){
          newData[j] = data[i];
          j++;
        }
        for(int i = 0; i < firstIndex; i++){
          newData[j] = data[i];
          j++;
        }
        delete [] data;
        data = newData;
        firstIndex = 0;
        nextIndex = capacity;
        capacity *= 2;

      }
      if(firstIndex == -1){
          firstIndex = 0;
      }
        data[nextIndex] = element;
        size++;
        nextIndex = (nextIndex + 1) % capacity;
    }

    T dequeue(){
      if(isEmpty()){
        cout << "Queue Empty";
        return 0;
      }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;   //limits counter to capacity then sets value to 0. BUT check when queue is empty and set fI to -1.
        size--;
        if(size == 0){
          firstIndex = -1;
          nextIndex = 0;
        }
        return ans;
    }
};

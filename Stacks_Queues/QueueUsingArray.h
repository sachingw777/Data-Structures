template <typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:

    QueueUsingArray(T s){
        data = new int[5];
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
    }

    void enqueue(T element){
      if(size == capacity){
        cout << "Queue Full";
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
        int ans = data[firstIndex];
        firstIndex = (firstIndex +1) % capacity;
        size--;
        if(size == 0){
          firstIndex = -1;
          nextIndex = 0;
        }
        return ans;
    }
};

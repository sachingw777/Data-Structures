class QueueUsingArray{
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    
    QueueUsingArray(int s){
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

    void enqueue(int element){
        if(nextIndex == 0){
            firstIndex++;
        }
        data[nextIndex] = element;
        size++;
        nextIndex = (nextIndex + 1) % capacity;
    }

    int dequeue(){
        int ans = data[firstIndex];
        firstIndex++;
        size--;
        return ans;    
    }

};
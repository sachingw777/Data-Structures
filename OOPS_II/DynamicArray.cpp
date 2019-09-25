class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

    DynamicArray(){
        capacity = 5;
        data = new int[capacity];
        nextIndex = 0;
    }

    DynamicArray(DynamicArray const & d){
        // this -> data = d.data;      //shallow copy
        this-> data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void operator=(DynamicArray const & d){
        this-> data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;        
    }

    void add(int num){
        if(nextIndex == capacity){  
        //double the array
            int *newdata = new int[capacity * 2];
            for(int i = 0; i < nextIndex; i++){
                newdata[i] = data[i];
            }
        delete [] data;
        data = newdata;
        capacity *= 2;
        }

        data[nextIndex] = num;
        nextIndex++;
    }

    int get(int i){
        if(i < nextIndex){
            return data[i];
        }
        else if(i <= nextIndex){
            return -1;
        }
    }

    void add(int i, int element){
        if(i < nextIndex){
            data[i] = element;
        }
        else if(i > nextIndex){
            return;
        }
        else
        {
            add(element);
        }
    }

    void print(){
        for(int i = 0; i < nextIndex; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
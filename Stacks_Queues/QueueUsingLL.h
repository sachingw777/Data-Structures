template <typename T>
class Node {
	public :
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}

		~Node() {
			delete next;
		}
};

template <typename T>
class QueueUsingLL {
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLL(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return (size == 0);
    }

    T front(){
        if(isEmpty()){
            return 0;
        }
        return head -> data;
    }

    void enqueue(T element){
        Node<T> *newNode = new Node<T>(element);
        if(isEmpty()){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        size++;
    }

    T dequeue(){
        if(isEmpty()){
            cout << "Queue Empty";
            return 0;
        }

        Node<T> *ans = head;
        T answer = ans -> data;
        head = head -> next;
        delete ans;
        size --;
        return answer;
    }
};

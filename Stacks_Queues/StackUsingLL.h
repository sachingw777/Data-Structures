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
class StackUsingLL {
	Node<T> *head;
	int size;		// number of elements present in stack

	public :

	StackUsingLL() {
        head = NULL;
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return head == NULL;
	}

	void push(T element) {
		// No need for null case. gets handled through the code.
			Node<T> *newNode = new Node<T>(element);	
			newNode -> next = head;
			head = newNode;
			size++;
	}

	T pop() {
		if(head == NULL){
			return 0;
		}
		T ans = head -> data;
		Node<T> *temp = head;
		head = head -> next;
		delete temp;
		size--;
		return ans;
	}

	T top() {
		if(head == NULL){
			return 0;
		}
		return head -> data;
	}
};
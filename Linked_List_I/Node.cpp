class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this-> data = data;
            this -> next = NULL;
        }
        
    Node *takeInput_Better(){
        int data;
        cin >> data;

        Node *head = NULL; 
        Node *tail = NULL; 

        while(data != -1){
            Node * newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            cin >> data;
        }
        return head;
    }

    Node *takeInput(){
        int data;
        cin >> data;

        Node *head = NULL; 
        while(data != -1){
            Node * newNode = new Node(data);
            if(head == NULL){
                head = newNode;
            }else{
                Node *temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cin >> data;
        }
        return head;
    }

    int length(Node *head) {
        Node * temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count ;
    }

    void print(Node *head){
        Node * temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void printIthNode(Node *head, int i) {
        if(i > length(head)){
            return;
        }
        Node * temp = head;
        int count = 0;
        while(temp != NULL){
            if(count == i){
                cout << temp->data;
            }
            temp = temp->next;
            count++;
        }
    }
};
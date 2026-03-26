class MyLinkedList {
public:
    class Node {
    public:
        int val;
        Node* next;

        Node(int data) {
            val = data;
            next = nullptr;
        }
    };

    Node* dummy;
    int size;

    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* temp = dummy->next;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        Node* prev = dummy;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* newNode = new Node(val);  
        newNode->next = prev->next;
        prev->next = newNode;

        size++;  
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* prev = dummy;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* toDelete = prev->next;
        prev->next = toDelete->next;

        delete toDelete; 
        size--;           
    }
};
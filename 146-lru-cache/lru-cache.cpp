class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    Node *head, *tail;
    unordered_map<int, Node*> mp;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head (Most Recently Used)
    void addNode(Node *newNode) {
        Node *temp = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = temp;
        temp->prev = newNode;
    }

    // Remove a node
    void deleteNode(Node *delNode) {
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node *node = mp[key];
        int ans = node->value;

        // Move to front (MRU)
        deleteNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node *existing = mp[key];
            deleteNode(existing);
            mp.erase(key);
        }

        // If capacity full, remove LRU (last node)
        if (mp.size() == limit) {
            Node *lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
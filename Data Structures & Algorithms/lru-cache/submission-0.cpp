class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        Node* prev = tail->prev;

        prev->next = node;
        node->prev = prev;

        node->next = tail;
        tail->prev = node;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            remove(node);

            node->value = value;

            insert(node);

        } else {

            Node* node = new Node(key, value);

            mp[key] = node;

            insert(node);

            if(mp.size() > capacity) {

                Node* lru = head->next;

                remove(lru);

                mp.erase(lru->key);

                delete lru;
            }
        }
    }
};
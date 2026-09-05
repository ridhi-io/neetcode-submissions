
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        // Step 1: Create all copied nodes
        while(curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Connect next and random pointers
        curr = head;

        while(curr != nullptr) {

            mp[curr]->next = mp[curr->next];

            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};
        


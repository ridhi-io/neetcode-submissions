
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*second = slow->next;
        slow->next = nullptr;
        ListNode*prev = nullptr;
        while(second != nullptr){
            ListNode*next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        ListNode*first = head;
        second = prev;
        while(second != nullptr){
            ListNode*next1 = first->next;
            ListNode*next2 = second->next;
            first->next = second;
            second->next = next1;
            first = next1;
            second = next2;
        }
    }
};
    

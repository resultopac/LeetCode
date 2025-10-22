class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* key = head;
        while (head->next != nullptr) {
            if (head->next->val != 0) {
                head->val += head->next->val;
                head->next = head->next->next;
            }else {
                 head = head->next;
            }
        }
        head = key;
        while (head->next != nullptr) {
            if(head->next->val == 0){
                head->next = nullptr;
                break;
            }
            head = head->next;
        }
        
        return key;
    }
};
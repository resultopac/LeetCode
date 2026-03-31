class Solution {
public:



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res  ;
        std::queue<int> q1 ;
        std::queue<int> q2 ;
        while (l1 != nullptr) {
            q1.push(l1->val);
            l1=l1->next;
        }
        while (l2 != nullptr) {
            q2.push(l2->val);
            l2=l2->next;
        }
        bool carrier = false;
        ListNode* travel = new ListNode();
        res = travel;
        while (!q1.empty() || !q2.empty()) {
            int sum = 0;
            if (!q1.empty() && !q2.empty()) {

                if (carrier) {
                    sum = q1.front()+q2.front()+1;
                }else {
                    cout << q1.front() << endl;
                    cout << q2.front() << endl;
                    sum = q1.front()+q2.front();
                }
                q1.pop();
                q2.pop();
                if (sum >= 10) {
                    travel->val = sum%10;
                    carrier = true;
                }else {
                    travel->val = sum;
                    carrier = false;
                }
            }else if (q1.empty()) {
                if (carrier) {
                    sum = q2.front()+1;
                }else {
                    sum = q2.front();
                }
                if (sum >= 10) {
                    travel->val = sum%10;
                    carrier = true;
                }else {
                    travel->val = sum;
                    carrier = false;
                }
                q2.pop();
            }else {
                if (carrier) {
                    sum = q1.front()+1;
                }else {
                    sum = q1.front();
                }
                if (sum >= 10) {
                    travel->val = sum%10;
                    carrier = true;
                }else {
                    travel->val = sum;
                    carrier = false;
                }
                q1.pop();
            }
            if (!(q1.empty() && q2.empty())) {
                ListNode* next = new ListNode();
                travel->next = next;
                travel = next;
            }else if (carrier) {
                ListNode* next = new ListNode();
                travel->next = next;
                travel = next;
                travel->val = 1;
            }
        }
        return res;
    }
};
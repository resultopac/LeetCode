/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int ebob(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* headYedek = head;
    while (head->next != nullptr) {
        int ebobVal = ebob(head->val,head->next->val);
        ListNode* ebobNode = new ListNode(ebobVal,head->next);
        head->next = ebobNode;
        head = ebobNode->next;
    }
    return headYedek;
}
};
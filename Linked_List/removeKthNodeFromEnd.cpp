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
    int size(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            cnt += 1;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = size(head);

        ListNode* temp = head;
        if(temp == NULL) return head;
        if(sz == n) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        for(int i = 1; i < sz - n; i++){
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        return head;
    }
};
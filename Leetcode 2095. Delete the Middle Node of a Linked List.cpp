class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode* it= head;
        while (it->next){
            cnt++; it= it->next;
        } cnt++;
        if (cnt==1)return NULL;
        if (cnt==2){
            head->next= NULL;
            return head;
        }
        if (cnt==3){
            head->next= head->next->next;
            return head;
        }
        cnt= cnt/2;
        ListNode* temp= head;
        ListNode* prev;
        while (cnt--){
            temp= temp->next;
            if (cnt==1)prev=temp;
        }
        prev->next = temp->next;
        return head;
    }
};

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
int get_len(ListNode* head)
{
    int cnt=0;
    ListNode* curr=head;
    while(curr!=NULL)
    {
        cnt++;
        curr=curr->next;

    }
    return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=get_len(head);
        if(len==1 && n==1 )return NULL;
        int node_to_remove=len-n+1;
        int pos=1;
        ListNode*prev=NULL;
        ListNode* curr=head;
        if(node_to_remove==1)
        {
            ListNode* temp=head;

            head=head->next;
            delete temp;

        }
        else
        {
        while(pos<node_to_remove)
        {

            prev=curr;
            curr=curr->next;
            pos++;
        }
        //ListNode* temp=curr;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

        }
       
        return head;
    }
};

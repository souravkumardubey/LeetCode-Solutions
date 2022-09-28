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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head, *temp2 = head;
            
        int len = 0;
        
        while ( temp != NULL ) {
            
            len += 1;
            temp = temp -> next;
            
        }
        
        int dest = len - n;
        len = 0;
        
        if ( dest == 0 ) {
            
            return temp2 -> next;
            
        }
        
        while ( head != NULL ) {
            
            len += 1;
            
            if ( len == dest ) {
                
                head -> next = head -> next -> next;
                break;
                
            }
            
            head = head -> next;
            
        }
        
        return temp2;
        
    }
};
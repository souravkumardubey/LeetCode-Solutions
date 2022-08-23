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
    bool isPalindrome(ListNode* head) {
        
        ListNode* prev = NULL, *curr = head, *next = NULL;
        
        ListNode* slow = head , *fast = head;
        
        while ( fast -> next != NULL and fast -> next -> next != NULL ) {
            
            slow = slow -> next;
            fast = fast -> next -> next;
            
        }
        

        curr = slow -> next;

        while ( curr != NULL ) {
            
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            
        }
        
        slow -> next = prev;
        slow = slow -> next;

//         while ( prev != NULL ) {
            
//             cout << prev -> val << " ";
//             prev = prev -> next;
            
//         }
        
//         cout << "\n";
        
//         while ( temp != NULL ) {
            
//             cout << temp -> val << " ";
//             temp = temp -> next;
            
//         }
        
//         cout << "\n";
        
        while ( slow != NULL ) {
            
            // cout << prev -> val << " ";
            if ( head -> val != slow -> val ) return false;
            head = head -> next;
            slow = slow -> next;
            
        }
//         cout << "\n";
        return true;
        
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node *ptr = head, *temp;
        Node* temp2;
        
        while ( ptr ) {
            
            if ( ptr -> child ) {
                
                temp = ptr -> next;
                
                ptr -> next = ptr -> child;
                
                ptr -> next -> prev = ptr;
                
                ptr -> child = NULL;
                
                temp2 = ptr -> next;
                
                while ( temp2 -> next != NULL ) {
                    
                    temp2 = temp2 -> next;
                    
                }
                
                temp2 -> next = temp;
                
                if ( temp2 -> next != NULL ) {
                    
                    temp2 -> next -> prev = temp2;
                    
                }
                
            }
            
            ptr = ptr -> next;
            
        }
        
        return head;
        
    }
    
};
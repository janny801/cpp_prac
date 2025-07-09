
#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        //base case 
        if (head ==nullptr)
        {
            return nullptr; 
        }

        stack <int> st; 
        ListNode* curr= head; 

        //put all values into stack 
        while(curr !=nullptr)
        {
            st.push(curr->val); 
            curr = curr-> next; 
        }

        curr = head; //head is the first value in the original LL 
        cout<<"curr value: " <<curr-> val; 


        while(!st.empty())
        {
            curr -> val= st.top(); //this replaces the first value in the original LL 
            st.pop(); 
            curr = curr-> next;
        }

        return head; //pointing to the same memory address as where curr started 
                    //we just used curr as an iterator to get thru the stack

        
    }
};
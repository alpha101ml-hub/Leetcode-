#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode middleNode(ListNode* head){
    int count = 0;
    ListNode* curr = head;
    while(curr != nullptr){
        count++;
        curr = curr->next;
    }

    int mid = count / 2;
    curr = head;
    for(int i=0; i<mid; i++){
        curr = curr->next;
    }
    return curr;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2, int depth = 0) {
    // --- THE "CAMERA" SECTION ---
    // 1. Indentation logic
    for(int i = 0; i < depth; i++) cout << "  "; 
    
    // 2. The Null-Safe Print (Ternary Operator)
    cout << "merge(" << (l1 ? to_string(l1->val) : "null") 
         << "," << (l2 ? to_string(l2->val) : "null") << ")\n";
    
    // --- THE "PLUMBING" SECTION ---
    // Base Cases: If one list runs out, return the other
    if (!l1) return l2;
    if (!l2) return l1;
    
    // Recursive Step
    if (l1->val < l2->val) {
        // l1 wins: find its next neighbor recursively
        l1->next = mergeTwoLists(l1->next, l2, depth + 1);
        return l1;
    } else {
        // l2 wins: find its next neighbor recursively
        l2->next = mergeTwoLists(l1, l2->next, depth + 1);
        return l2;
    }
}

// Helper function to print the final list
void printList(ListNode* node) {
    while (node) {
        cout << node->val << (node->next ? " -> " : "");
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Creating List 1: 1 -> 3 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    // Creating List 2: 2 -> 4
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);

    cout << "Starting Trace:\n";
    ListNode* result = mergeTwoLists(l1, l2);

    cout << "\nFinal Merged List:\n";
    printList(result);

    return 0;
}
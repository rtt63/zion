// https://leetcode.com/problems/linked-list-cycle/

class Solution {
public:
    // edge cases suck
    bool hasCycle(ListNode *head) {
        ListNode* pointer = head;
        ListNode* slow = pointer;
        ListNode* fast = pointer->next->next;

        while (slow && fast) {
          if (slow == fast) {
            return true;
          } else {
            slow = slow->next;
            fast = fast->next->next;
          }
        }

        return false;
    }
};

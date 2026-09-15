class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        // Base case
        if (head == NULL)
            return NULL;

        // If only one node is present
        if (head->next == NULL)
            return new TreeNode(head->val);

        // Find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list into two halves
        prev->next = NULL;

        // Create root using middle element
        TreeNode* root = new TreeNode(slow->val);

        // Recursively build left and right subtrees
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
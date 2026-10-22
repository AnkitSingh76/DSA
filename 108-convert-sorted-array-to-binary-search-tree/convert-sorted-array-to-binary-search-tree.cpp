/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
  public:

    TreeNode* arraytobst(vector<int>& arr, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = arraytobst(arr, start, mid - 1);
        root->right = arraytobst(arr, mid + 1, end);

        return root;
    }

   TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arraytobst(nums, 0, nums.size() - 1);
    }
};

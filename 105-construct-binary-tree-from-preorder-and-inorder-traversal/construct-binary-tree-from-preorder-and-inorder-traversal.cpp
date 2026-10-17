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


/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */


    int find(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* tree(vector<int>& inorder, vector<int>& preorder,
               int inStart, int inEnd, int& index) {

        if (inStart > inEnd)
            return nullptr;

        // First element in preorder is the root
        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        // Find root position in inorder
        int pos = find(inorder, root->val, inStart, inEnd);

        // Construct left and right subtrees
        root->left = tree(inorder, preorder, inStart, pos - 1, index);
        root->right = tree(inorder, preorder, pos + 1, inEnd, index);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          int index = 0;

        return tree(inorder, preorder, 0,
                    (int)inorder.size() - 1, index);
    }
};
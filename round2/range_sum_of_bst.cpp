// // https://leetcode.com/problems/range-sum-of-bst/submissions/
// #include <iostream>;
//
// using namespace std;
//
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     int rangeSumBST(TreeNode* root, int L, int R) {
//         int sum = 0;
//         if (root == nullptr) {
//           return sum;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         while (q.size() > 0) {
//           // BFS
//           TreeNode* curr = q.front();
//           q.pop();
//           if (curr != nullptr) {
//             if (curr->val >= L && curr->val <= R) {
//               sum += curr->val;
//             }
//             if (curr->val > L) {
//               q.push(curr->left);
//             }
//             if (curr->val < R) {
//               q.push(curr->right);
//             }
//           }
//
//         }
//         return sum;
//     }
// };

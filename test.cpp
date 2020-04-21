/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *build(vector<int> &A, vector<int> &B, int instrt, int inend, int &pind, map<int, int> &mp) {
   if (instrt > inend) return NULL;
   TreeNode *node = new TreeNode(A[pind]);
   if (instrt == inend) return node;
   int lower = mp[B[pind]];
   pind++;
   node->left = build(A, B, instrt, lower - 1, pind, mp);
   node->right = build(A, B, lower + 1, inend, pind, mp);
   return node;
}
TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B) {
   int n = A.size();
   int pind = 0;
   map<int, int> mp;
   for (int i = 0; i < n; i++) {
      mp[B[i]] = i;
   }
   TreeNode *root = build(A, B, 0, n - 1, pind, mp);
   return root;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *building(vector<int> &preorder, vector<int> &inorder, int start, int end, int &p) {
   if (start > end)
      return NULL;

   TreeNode *node = new TreeNode(preorder[p++]);

   if (start == end)
      return node;

   int index;
   for (int i = start; i <= end; i++)
      if (node->val == inorder[i]) {
         index = i;
         break;
      }

   node->left = building(preorder, inorder, start, index - 1, p);
   node->right = building(preorder, inorder, index + 1, end, p);

   return node;
}
TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B) {
   if (A.size() == 0 || B.size() == 0)
      return NULL;
   int p = 0;
   return building(A, B, 0, B.size() - 1, p);
}
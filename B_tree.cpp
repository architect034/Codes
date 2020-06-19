#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
void IOEFILE() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
}
struct Node {
   int data;
   struct Node* left;
   struct Node* right;
};
struct Node* newnode(int x) {
   struct Node* node = new Node();
   node->data = x;
   node->left = NULL;
   node->right = NULL;
   return node;
}
void buildTree(struct Node** root) {
   *root = newnode(10);
   (*root)->left = newnode(5);
   (*root)->right = newnode(20);
   (*root)->left->left = newnode(3);
   (*root)->left->right = newnode(9);
   (*root)->left->right->left = newnode(7);
   (*root)->left->right->left->right = newnode(8);
   (*root)->right->left = newnode(15);
   (*root)->right->right = newnode(23);
   (*root)->right->left->left = newnode(12);
}
void preOrderUtil(struct Node* root) {
   if (root == NULL) return;
   cout << root->data << " ";
   preOrderUtil(root->left);
   preOrderUtil(root->right);
}
void postOrderUtil(struct Node* root) {
   if (root == NULL) return;
   postOrderUtil(root->left);
   postOrderUtil(root->right);
   cout << root->data << " ";
}
void inOrderUtil(struct Node* root) {
   if (root == NULL) return;
   inOrderUtil(root->left);
   cout << root->data << " ";
   inOrderUtil(root->right);
}
void levelOrderUtil(struct Node* root) {
   queue<struct Node*> q;
   q.push(root);
   dbg(root->data);
   while (!q.empty()) {
      struct Node* temp = q.front();
      cout << temp->data << " ";
      q.pop();
      if (temp->left) q.push(temp->left);
      if (temp->right) q.push(temp->right);
   }
}
void preOrder(struct Node* root) {
   cout << "Pre order : ";
   preOrderUtil(root);
   cout << endl;
}
void postOrder(struct Node* root) {
   cout << "Post order : ";
   postOrderUtil(root);
   cout << endl;
}
void inOrder(struct Node* root) {
   cout << "In Order : ";
   inOrderUtil(root);
   cout << endl;
}
void levelOrder(struct Node* root) {
   cout << "Level Order : ";
   levelOrderUtil(root);
   cout << endl;
}
int heightTreeUtil(struct Node* root, int level, int& height) {
   if (root == NULL) return height = max(height, level);
   return max(heightTreeUtil(root->left, level + 1, height), heightTreeUtil(root->right, level + 1, height));
}
int diameterTreeUtil(struct Node* root, int& ans) {
   if (root == NULL) return 0;
   int lh = diameterTreeUtil(root->left, ans);
   int rh = diameterTreeUtil(root->right, ans);
   ans = max(ans, lh + rh + 1);
   return 1 + max(lh, rh);
}
void heightTree(struct Node* root) {
   int height = 1;
   cout << "Height of Tree : " << heightTreeUtil(root, 0, height) << endl;
}
void diameterTree(struct Node* root) {
   int diameter = 1;
   diameterTreeUtil(root, diameter);
   cout << "Diameter of Tree : " << diameter << endl;
}
int maximumSumPathUtil(struct Node* root, int& ans) {
   if (root == NULL) return 0;
   int lsum = maximumSumPathUtil(root->left, ans);
   int rsum = maximumSumPathUtil(root->right, ans);
   ans = max({ans, lsum + root->data, rsum + root->data, lsum + root->data + rsum, root->data});
   return max({lsum + root->data, rsum + root->data, root->data});
}
void maximumSumPath(struct Node* root) {
   int ans = 0;
   maximumSumPathUtil(root, ans);
   cout << "Max Sum Path : " << ans << endl;
}
bool hasPathSumUtil(struct Node* root, int sum) {
   if (root == NULL) {
      if (sum == 0) return true;
      return false;
   }
   return hasPathSumUtil(root->left, sum - root->data) || hasPathSumUtil(root->right, sum - root->data);
}
void hasPathSum(struct Node* root, int sum) {
   bool say = hasPathSumUtil(root, sum);
   if (say)
      cout << "Path with sum " << sum << " exist.\n";
   else
      cout << "Path with sum " << sum << " doesnot exist.\n";
}
void verticalSumUtil(struct Node* root, int horizontalDist, map<int, int>& m) {
   if (root == NULL) {
      return;
   }
   m[horizontalDist] += root->data;
   verticalSumUtil(root->left, horizontalDist - 1, m);
   verticalSumUtil(root->right, horizontalDist + 1, m);
}
void verticalSum(struct Node* root) {
   map<int, int> m;
   verticalSumUtil(root, 0, m);
   cout << "Vertical lines sum : ";
   for (auto x : m) {
      cout << x.second << " ";
   }
   cout << endl;
}
struct Node* LCAUtil(int x, int y, struct Node* root) {
   if (root == NULL) return NULL;
   if (root->data == x || root->data == y) return root;
   struct Node* lft = LCAUtil(x, y, root->left);
   struct Node* rght = LCAUtil(x, y, root->right);
   if (lft && rght) return root;
   if (lft) return lft;
   return rght;
}
void LCA(int x, int y, struct Node* root) {
   int lca = LCAUtil(x, y, root)->data;
   cout << "LCA of " << x << " and " << y << " is " << lca << endl;
}
void topViewUtil(struct Node* root, map<int, int>& m, int hd) {
   if (root == NULL) return;
   if (m.find(hd) == m.end()) {
      m[hd] = root->data;
   }
   topViewUtil(root->left, m, hd - 1);
   topViewUtil(root->right, m, hd + 1);
}
void topView(struct Node* root) {
   cout << "Top View : ";
   map<int, int> m;
   topViewUtil(root, m, 0);
   for (auto x : m) {
      cout << x.second << " ";
   }
   cout << endl;
}
void bottomViewUtil(struct Node* root, map<int, int>& m, int hd) {
   if (root == NULL) return;
   queue<pair<Node*, int>> q;
   q.push({root, hd});
   while (!q.empty()) {
      Node* temp = q.front().first;
      hd = q.front().second;
      q.pop();
      m[hd] = temp->data;
      if (temp->left != NULL) {
         q.push({temp->left, hd - 1});
      }
      if (temp->right != NULL) {
         q.push({temp->right, hd + 1});
      }
   }
}
void bottomView(struct Node* root) {
   cout << "Bottom View : ";
   map<int, int> m;
   bottomViewUtil(root, m, 0);
   for (auto x : m) {
      cout << x.second << " ";
   }
   cout << endl;
}
signed main() {
   IOEFILE();
   struct Node* root;
   buildTree(&root);
   preOrder(root);
   postOrder(root);
   inOrder(root);
   levelOrder(root);
   heightTree(root);
   diameterTree(root);
   maximumSumPath(root);
   hasPathSum(root, 27);
   verticalSum(root);
   LCA(15, 5, root);
   topView(root);
   bottomView(root);
}
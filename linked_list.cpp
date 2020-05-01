#include <bits/stdc++.h>
using namespace std;
void input() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
struct node {
   int data;
   struct node* next;
};
struct node* newnode(int x) {
   struct node* the_node = new node();
   the_node->data = x;
   the_node->next = NULL;
   return the_node;
}
void insert_into_list(struct node** head, int x) {
   struct node* new_node = newnode(x);
   new_node->next = *head;
   *head = new_node;
}
void print_list(struct node** head) {
   struct node* new_head = *head;
   while (new_head) {
      cout << new_head->data << " ";
      new_head = new_head->next;
   }
   cout << endl;
}
void deleteNode(struct node** head, int key) {
   struct node *temp = *head, *prev;
   if (temp != NULL && temp->data == key) {
      *head = temp->next;
      free(temp);
      return;
   }
   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL) return;
   prev->next = temp->next;
   free(temp);
}
int main() {
   input();
   struct node* head = NULL;
   for (int i = 1; i <= 10; i++) {
      insert_into_list(&head, i);
   }
   print_list(&head);
   deleteNode(&head, 10);
   print_list(&head);
}
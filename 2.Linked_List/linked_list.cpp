#include<iostream>
using namespace std;
class node
{
public:
  int data;
  node* link;
};
void push_node(node** head, int new_data)
{
  node* new_node = new node();
  new_node->data = new_data;
  new_node->link = (*head);
  (*head) = new_node;
}
void add_node(node** head, int new_data)
{
  node* new_node = new node();
  node *last = *head;
  new_node->data = new_data;
  new_node->link = NULL;
  if(*head==NULL)
  {
    (*head) = new_node;
  }
  while(last->link!=NULL)
  {
    last = last->link;
  }
  last->link = new_node;
}
void insert_node_after(node *prev_link, int position, int new_data)
{
  if(prev_link==NULL)
  {
    cout<<"Previous link cannot be NULL";
  }
  for(int i=0;i<position-1;i++)
  {
    prev_link = prev_link->link;
  }
  node* new_node = new node();
  new_node->data = new_data;
  new_node->link = prev_link->link;
  prev_link->link = new_node;
}
void delete_node(node *prev_link, int position)
{
  for(int i=0;i<position-2;i++)
  {
    prev_link = prev_link->link;
  }
  node *temp = prev_link;
  temp = temp->link;
  free(temp);
  node *next_link = prev_link;
  for(int i=0;i<2;i++)
  {
    next_link = next_link->link;
  }
  prev_link->link = next_link;
  //prev_link = prev_link->link;
  //free(prev_link);
}
void printlist(node *head)
{
  while(head!=NULL)
  {
    cout<<head->data<<"--";
    head = head->link;
  }
  cout<<endl;
}
int main()
{
  node* head = NULL;
  push_node(&head,7);
  push_node(&head,2);
  push_node(&head,9);
  add_node(&head,3);
  insert_node_after(head,1,5);
  insert_node_after(head,5,5);
  delete_node(head,2);
  printlist(head);
  return 0;
}

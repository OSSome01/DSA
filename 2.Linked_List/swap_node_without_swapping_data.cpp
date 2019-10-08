#include<iostream>
using namespace std;
class node
{
public:
  int data;
  node* link;
};
int main()
{
  cout<<"Enter no of nodes\n";
  int n;
  cin>>n;
  node* head = NULL;
  node* temp = head;
  for(int i=0;i<n;i++)
  {
    cout<<"Enter elements\n";
    cin>>temp->data;
    temp = temp->link;
  }
  for(int i=0;i<n;i++)
  {
    cout<<temp->data;
  }
}

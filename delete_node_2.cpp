#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print_normal(Node* head)
{
    Node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
void print_reverse(Node* tail)
{
    Node* tmp=tail;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->prev;
    }

}

void delete_at_position(Node* head,int pos)
{
    Node* tmp=head;
    for (int i = 1; i <=pos-1; i++)
    {
        tmp=tmp->next;
    }
    Node* deleteNode=tmp->next;
    tmp->next=tmp->next->next;
    tmp->next->prev=tmp;
    delete deleteNode;
}
void delete_at_tail(Node *&head,Node* &tail)
{
    Node* deleteNode=tail;
    tail=tail->prev;
    delete deleteNode;
    if(tail==NULL)
    {
        head=NULL;
        return;
    }
    tail->next=NULL;
}
void delete_at_head(Node* &head,Node *&tail)
{
    Node* deleteNode=head;
    head=head->next;
    delete deleteNode;
    if(head==NULL)
    {
        tail=NULL;
        return;
    }
    head->prev=NULL;
}
int size(Node* head)
{
    Node* tmp=head;
    int cnt=0;
    while (tmp!=NULL)
    {
       cnt++;
       tmp=tmp->next;
    }
    return cnt;
}

int main()
{
    // Node* head=NULL;
    // Node* tail=NULL;
    Node* head=new Node(10);   
    Node* tail=head;  

    int pos;
    cin>>pos;

//   delete_at_position(head,pos);
// delete_at_tail(tail);
// delete_at_head(head);
   
    if(pos>=size(head))
    {
        cout<<"invalid"<<endl;
    }
    else if(pos==0)
    {
        delete_at_head(head,tail);
    }
    else if(pos==size(head)-1)
    {
        delete_at_tail(head,tail);
    }
    else
    {
        delete_at_position(head,pos);
    }
    print_normal(head);
    print_reverse(tail);
  
    return 0;
}
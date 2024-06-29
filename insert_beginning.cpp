#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }

};

int printList(Node*& head){
    int count;
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        count++;
    }
    cout<<endl<<endl;
    return count;
    
}

void insertBeginning(int val,Node*& head){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void deleteTail(Node*& head){
    Node* temp = head;
    if(head==NULL){
        cout<<"No linked list"<<endl;
        return;
    }
    else if(temp->next==NULL){
        delete head;
        head = NULL;

    }
    else{
        while (temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

int searchElement(int val,Node* head){
    Node* temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        if(temp->data == val){
            cout<<"Element Found"<<endl; 
            // cout<<"Index: "<<count<<endl;
            return count;
        }

        count++;
        temp = temp->next;
    }
    cout<<"Element Not Found"<<endl;
    return -1;



}

void reverseList(Node* &head){
    Node* temp;
    Node* prev;
    Node* front;
    Node* new_head;

    prev = NULL;
    temp = head;
    front=temp->next;
 

while (front!=NULL)
{
    temp->next = prev;
    prev=temp;
    temp=front;
    front=front->next;
    new_head = prev;
}
temp->next=prev;
prev=temp;
new_head=prev;

printList(new_head);
cout<<new_head<<endl;


}

void middleNode(Node* head){
    Node* fast;
    Node* slow;
    Node* ref;

    fast = head;
    slow=head;

    while (fast!=NULL)
    {
        if(fast->next==NULL){
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;

}

bool hasCycle(Node* head){
    Node* fast;
    Node* slow;

    fast = head;
    slow=head;

    while (fast!=NULL)
    {
        if(fast->next==NULL){
            break;
        }
        else{
            slow=slow->next;
            fast=fast->next->next;
            if(fast->next==slow){
                return true;
            }
        }

    }
    return false;

}

bool intersectionPresent(Node* head1,Node* head2){
    Node* temp1;
    Node* temp2;
    temp1=head1;
    temp2=head2;

    while (temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    if(temp1==temp2){
        return true;
    }
    else{
        return false;
    }
    
    
}



int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    for (size_t i = 10; i > 0; i--)
    {
        insertBeginning(i,head1);
    }

    // Use for making a looped LL

    // Node* new_node_pointer = new Node(9);
    // Node* temp1;
    // Node* temp2;
    // temp1=head;
    // temp2=head;

    // while (temp2->next->next->next!=NULL)
    // {
    //     temp2=temp2->next;
    // }
    
    // while (temp1->next!=NULL)
    // {
    //     temp1=temp1->next;
    // }
    // new_node_pointer->next = temp2;
    // temp1->next = new_node_pointer;

    // Used for making an intersected LL

    for (size_t i = 5; i>0; i--)
    {
        insertBeginning(i,head2);

    }

    Node* temp2;
    temp2=head2;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    
    temp2->next = head1->next->next->next->next;

    
    



    
    
    // printList(head2);
    // middleNode(head);
    // cout<<hasCycle(head);
    cout<<intersectionPresent(head1,head2);

 
}
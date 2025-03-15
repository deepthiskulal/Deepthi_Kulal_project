#include <iostream>
using namespace std;
class LinkedList
{
protected:
    struct node{
        int info;
        struct node *link;
    };
    typedef struct node Node;
    Node *start;
public:
    void create();
    void display();
    void insert_beg();
    void insert_end();
    void insert_sp();
    void delete_beg();
    void delete_end();
    void delete_sp();
    LinkedList(){
        start=NULL;
    }
};
void LinkedList::create()
{
    int item;
    Node *ptr;
    if(start==NULL){
        ptr=new Node;
        cout<<"Enter a item:";
        cin>>item;
        ptr->info=item;
        ptr->link=NULL;
        start=ptr;
    }else{
        cout<<"List already exists";
    }
}
void LinkedList::display()
{
    if(start==NULL){
        cout<<"List is empty\n";
    }else{
        Node *ptr;
        ptr=start;
        while(ptr!=NULL){
            cout<<ptr->info<<endl;
            ptr=ptr->link;
        }
    }
}
void LinkedList::insert_beg()
{
    int item;
    Node *ptr=new Node;
    cout<<"Enter a item:";
    cin>>item;
    if(start==NULL){
        ptr->info=item;
        ptr->link=NULL;
        start=ptr;
    }else{
        ptr->info=item;
        ptr->link=start;
        start=ptr;
    }
}
void LinkedList::insert_end()
{
    int item;
    Node *ptr=new Node;
    cout<<"Enter a item:";
    cin>>item;
    ptr->info=item;
    ptr->link=NULL;
    if(start==NULL){
        start=NULL;
    }else{
        Node *temp=new Node;
        temp=start;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        ptr->link=temp->link;
        temp->link=ptr;
    }
}
void LinkedList::insert_sp()
{
    int item,y;
    Node *ptr=new Node;
    Node *temp=new Node;
    cout<<"Enter the item after you want to insert:\t";
    cin>>item;
    cout<<"Enter the item you want to insert:\t";
    cin>>y;
    ptr->info=y;
    ptr->link=NULL;
    temp=start;
    while(temp->link!=NULL && temp->info!=item){
        temp=temp->link;
    }
    if(temp->info==item){
        ptr->link=temp->link;
        temp->link=ptr;
    }else{
        cout<<"Element not found"<<endl;
    }
}
void LinkedList::delete_beg()
{
    Node *ptr;
    if(start==NULL){
        cout<<"Linked list is empty";
    }else{
        ptr=start;
        int item=ptr->info;
        start=ptr->link;
        delete ptr;
        cout<<item<<"Deleted\n";
    }
}
void LinkedList::delete_end()
{
    Node *ptr;
    Node *temp;
    if(start==NULL){
        cout<<"Linked list is empty";
    }else{
        ptr=start;
        while(ptr->link!=NULL){
            temp=ptr;
            ptr=ptr->link;
        }
        int item=ptr->info;
        if(start->info==ptr->info){
            start=NULL;
        }else{
            temp->link=NULL;
            delete ptr;
        }
        cout<<item<<"Deleted successfully\n";
    }
}
void LinkedList::delete_sp()
{
    Node *ptr,*prev;
    int item,y;
    if(start==NULL){
        cout<<"Linked list is empty";
    }else{
        cout<<"Enter the item to be delete:";
        cin>>y;
        ptr=start;
        while(ptr->info!=y && ptr->link!=NULL){
            prev=ptr;
            ptr=ptr->link;
        }
        if(ptr->info==y){
            item=ptr->info;
            prev->link=ptr->link;
            delete ptr;
            cout<<item<<"deleted\n";
        }else{
            cout<<"Element not found\n";
        }
    }
}
int main()
{
    LinkedList l;
    int ch;
    while(1){
        cout<<"1.Create \n2.Display \n3.Insert at beginning \n4.Insert at End \n5.Insert at Specified Position \n6.Delete at Beginning \n7.Delete at end \n8.Delete at specified position \n9.Exit \nEnter your choice:";
        cin>>ch;
        switch(ch){
        case 1:
            l.create();
            break;
        case 2:
            l.display();
            break;
        case 3:
            l.insert_beg();
            break;
        case 4:
            l.insert_end();
            break;
        case 5:
            l.insert_sp();
            break;
        case 6:
            l.delete_beg();
            break;
        case 7:
            l.delete_end();
            break;
        case 8:
            l.delete_sp();
            break;
        case 9:
            return 0;
            exit(0);
        default:
            cout<<"Invalid Choice";
            break;
        }
    }
}

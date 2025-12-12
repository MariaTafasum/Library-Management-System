
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct Book{
    int id;
    string title;
    string author;
    bool available;
    queue<string> reservationQueue;
};
struct Node{
    Book data;
    Node* prev;
    Node* next;
};
Node*head = nullptr;
unordered_map<int,Node*>bookmap;

void insertBook(Book a)
{
    Node* n =new Node;
    n->data=a;
    n->prev=nullptr;
    n->next=nullptr;
    
    if(head==nullptr)
    {
        head=n;
        return;
    }
    else{
        Node*temp = head;
        while(temp->next != nullptr)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
    
    bookmap[a.id]=n;
}

void displayBook()
{
    Node* temp=head;
    if(head==nullptr)
    {
        cout<<"No books has been added in the library yet,\n";
        return;
    }
    else{
        while(temp != nullptr)
        {
            cout<<"Book ID = "<<temp->data.id<<endl;
            cout<<"Book Title = "<<temp->data.title<<endl;
            cout<<"Book Author = "<<temp->data.author<<endl;
            cout<<"Book availability= "<<(temp->data.available ? "Yes" : "No")<<endl;
            cout<<endl;
            
            temp=temp->next;
        }
    }
}

void borrowBook(int id)
{
    Node* temp=head;
    
    while(temp!=nullptr)
    {
        if(temp->data.id==id)
        {
            cout<<"Book found!"<<endl;
            
        {
           if(temp->data.available)
           {
               temp->data.available=false;
               cout<<"You have now borrowed the book!"<<endl;
               
           }
           else
           {
               cout<<"Book is already borrowed :( "<<endl;
               string user;
               cout<<"Enter name for book reservation: "<<endl;
               cin>>user;
               temp->data.reservationQueue.push(user);
               cout<<"You have been added to the queue"<<endl;
           }
           return;
        }
        
        }
       temp=temp->next;
        
    }
    
    cout<<"Book not found.."<<endl;
}

void returnBook(int id)
{
    Node* temp=head;
    
    while(temp!=nullptr)
    {
        if(temp->data.id==id)
        {
            cout<<"Book found!"<<endl;
            
        {
           if(!temp->data.reservationQueue.empty())
           {
               string nextUser=temp->data.reservationQueue.front();
               temp->data.reservationQueue.pop();
               cout<<"Book is now given to"<<nextUser<<endl;
               
               cout<<"You have now returned the book!"<<endl;
               
           }
           else
           {
               temp->data.available=true;
               cout<<"You have returned your book."<<endl;
           }
           return;
        }
        
        }
       temp=temp->next;
        
    }
    
    cout<<"Book not found.."<<endl;
}

void searchBook(int id)
{
    
    
    if(bookmap.find(id)!=bookmap.end())
    {
        Node* temp=bookmap[id];
         cout<<"Book ID = "<<temp->data.id<<endl;
         cout<<"Book Title = "<<temp->data.title<<endl;
         cout<<"Book author = "<<temp->data.author<<endl;
         cout<<"Book availability= "<<(temp->data.available ? "Yes" : "No")<<endl;
    }
    else
    {
        cout<<"Book not found.."<<endl;
    }
}

int main()
{
    int select;
    do
    {
        cout<<"-------Library Menu-----\n";
        cout<<"1.Add a book\n";
        cout<<"2.Borrow a book\n";
        cout<<"3.Return a book\n";
        cout<<"4.Display all book\n";
        cout<<"5.Search a book\n";
        cout<<"6.Exit\n";
        cout<<"Enter key :\n";
        cin>>select;
        cin.ignore();
        
        switch(select)
        {
            case 1:{
            Book b;
                cout<<"Enter Book ID: ";
                cin>>b.id;
                cin.ignore(); 
                cout<<"Enter Title: ";
                getline(cin,b.title);
                cout<<"Enter Author: ";
                getline(cin, b.author);
                b.available=true;
                insertBook(b);
                cout<<"Book added!\n";
            break;
            }
            case 2:{
            int id;
            cout<<"Enter book id you want to borrow :"<<endl;
            cin>>id;
            borrowBook(id);
             break;
            }
            case 3:{
            int id;
            cout<<"Enter book id you want to return :"<<endl;
            cin>>id;
            returnBook(id);
            break;
            }
            case 4:{
            displayBook();
            break;
            }
            case 5:{
            int id;
            cout<<"Enter book id you are looking for :"<<endl;
            cin>>id;
            searchBook(id);
            break;
            }
            case 6:{
            cout<<"Exited"<<endl;
            break;
            }
            default:
            cout<<"Invalid key;choose between(1~6)"<<endl;
            
             if(select != 6) 
             {
             cout << "\nPress Enter to continue.";
             cin.get(); 
             }
        }
        
    } while(select!=6);
        
        return 0;

    
}
#pragma once
#include "Data.h"

class List 
{
private:
    struct Node
    {
        Data* data;
        Node* next;
    };
    Node* head;
    Node* tail;

public:
    enum Position{Begin,End};


    List() : head(nullptr){}
    
    void print() const
    {   
        Node* tmp=head;
        std::cout<<"[";
        while(tmp!=nullptr)
        {
            std::cout<<"\"";
            tmp->data->print();
            std::cout<<"\", ";
            tmp=tmp->next;
        }
        std::cout<<"]\n";
    }
    List& insert(const Data& data,Position pos=End)
    {
        Node* NodeToInsert=new Node{data.clone(),nullptr};
        switch (pos)
        {
        case Begin:
            NodeToInsert->next=head;
            head=NodeToInsert;
            break;
        case End:
            if (head==nullptr)
            {
                head=NodeToInsert;
            }
            else
            {
                Node* current=head;
                while (current->next!=nullptr)
                {
                    current=current->next;
                }
                current->next=NodeToInsert;
            }
            break;
        default:
            std::cout<<"\n Error! \n";
            break;
        }
        return *this;
    }

    List(const List& other) : head(nullptr)
    {
        Node* tmp=other.head;
        while (tmp!=nullptr)
        {
            this->insert(*(tmp->data));
            tmp=tmp->next;
        }
    }
    ~List()
    {
        Node* current = head;
        while (current!=nullptr)
        {   
            Node *next = current->next;
            delete current->data;
            delete current;
            current=next;
        }
    }
};

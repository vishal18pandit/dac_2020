//============================================================================
// Name        : cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
	/*
	this is commented by vishal*/
    private:
        int age;
        string name;
        Node *next;

    public:
        Node()
        {
            age=0;
            name="Nothing";
            next=NULL;
        }

        Node(string na,int a)
        {
            age=a;
            name=na;
            next=NULL;
        }

        void setnext(Node *n)
        {
            next=n;
        }

        Node *getnext()
        {
            return next;
        }

        int getage()
        {
            return age;
        }

        string getname()
        {
            return name;
        }

};

class linklist
{
    private:
        Node *head;

    public:
        linklist()
        {
            head=NULL;
        }

        void insert(Node *n)
        {

            if(head==NULL)
            {
                head=n;
            }

            else if(n->getage() < head->getage())
            {
                n->setnext(head);
                head=n;
            }

            else
            {
                Node *temp=head;
                Node *prev=head;

                    while(n->getage() >= temp->getage() )
                    {
                        if(temp->getnext()==NULL)
                        {
                            prev=temp;
                            temp=NULL;
                            break;
                        }
                        prev=temp;
                        temp=temp->getnext();
                    }

                    n->setnext(temp);
                    prev->setnext(n);

            }


        }

            void Remove(int c)
            {
                Node *temp=head;
                Node *temp1=head;
                Node *temp2=head;

                for(int i=1;i<c;i++)
                {
                    temp1=temp;
                    temp=temp->getnext();
                    temp2=temp->getnext();
                }

                if(temp!=head)
                {
                  temp1->setnext(temp2);
                  delete temp;
                }
                else if( temp==head )
                {
                    temp2=temp->getnext();
                    head=temp2;
                }
                else if(temp2==NULL)
                {
                    delete temp;
                }
            }

             void print(int c)
            {
                Node *temp=head;
                for(int i=1;i<c;i++)
                {
                    temp=temp->getnext();
                }

                if(temp!=NULL)
                cout<<temp->getname()<<" "<<temp->getage()<<endl;

            }
};

int main()
{
	/*this is my main fuction*/
    int x;
    int age;
    string name;
    linklist l;
    string cmd;

    while(1)
    {
        cin>>cmd;
        if(cmd == "insert")
        {
            cin>>name;
            cin>>age;
            if(age<0)
            {
                break;
            }
            Node *n=new Node(name,age);
            l.insert(n);
        }

        if(cmd == "print")
        {
            cin>>x;
            l.print(x);
        }

        if(cmd == "remove")
        {
            cin>>x;
            l.Remove(x);
        }

        if(cmd == "stop")
        {
            exit(0);
        }

    }

return 0;
}


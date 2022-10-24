#include <bits/stdc++.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int dem=0;
int a[1001];
typedef struct node node;
struct node{
    int data;
    node *next;
};
node* makeNode(int x)
{
//    node *newNode = (node*)malloc(sizeof(node));
	node *newNode = new node();
    newNode -> data =x;
    newNode -> next = NULL;
    return newNode;
}
void printResult(node *head,int b[],int m)
{
    int cnt=0;
    while (head!=NULL)
    {
        cnt=0;
        for (int i=0;i<m;i++)
        {
            if (b[i]!=head->data) cnt++;
        }
        if (cnt==m)
        {
            printf("%d ",head->data);
        }
        head = head -> next;
    }
}
void duyet(node *head)
{
	int cnt=0;
    while(head!=NULL)
    {
    	printf("%d ",head->data);
        head = head -> next;
    	cnt++;
	}
}
void pushFront(node **head,int x)
{
    node *newNode = makeNode(x);
    newNode-> next = *head;
    *head=newNode;
}
void pushBack(node *&head,int x)
{
	node *temp = head;
	node *newNode = makeNode(x);
	if (head==NULL)
	{
		head=newNode;
		return;
	}
	while (temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newNode;
}
void sapxep(node **head)
{
	for (node *i=*head;i!=NULL;i=i->next)
	{
		node *minNode=i;
		for (node *j=i->next;j!=NULL;j=j->next)
		{
			if (minNode->data>j->data)
			{
				minNode=j;
			}
		}
		swap(minNode->data,i->data);
	}
}
int main()
{
    node *head = NULL;
    int x;
    int z=0;
    while (cin>>x)
    {
    	pushBack(head,x);
	}
	sapxep(&head);
	duyet(head);
    return 0;
}


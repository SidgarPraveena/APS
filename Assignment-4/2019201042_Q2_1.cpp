#include<iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T1,typename T2>
struct node
{
	T1 key;
	T2 value;
	struct node * link;
	struct node * tail;
};

unsigned int cal_hash(string str)
{
    unsigned int ha = 5381;

    for(char c:str)
        ha = ((ha << 5) + ha) + c; /* hash * 33 + c */

    return ha;
}

void insert(string k, string v,int n, struct node<string, string>unmap[])
{
	stringstream ss;
	ss<<k;
	string str = ss.str();
	
	unsigned int res=cal_hash(str);
	int pos;
	pos=res%20;
	cout<<pos<<"pos"<<endl;
	if(unmap[pos].link == NULL)
	{
		struct node<string,string> *new_node = (struct node<string,string> *)malloc(sizeof(struct node<string,string>));
		new_node->key = k;
		new_node->value = v;
		new_node->link = NULL;
		new_node->tail= NULL;
		
		unmap[pos].link = new_node;
		unmap[pos].tail = new_node;
		//cout<<"hello";
		
	}
	else
	{
		struct node<string, string> *temp;
		struct node<string, string> *new_node = (struct node<string,string> *)malloc(sizeof(struct node<string,string>));
		new_node->key = k;
		new_node->value = v;
		new_node->link = NULL;
		new_node->tail= NULL;
		
		temp = unmap[pos].tail;
		temp->link = new_node;
		
		unmap[pos].tail = new_node;
		
	}
}
void traverse(struct node<string, string> unmap[],int n)
{
	for(int i=0;i<20;i++)
	{
		struct node <string, string> *temp;
		temp = unmap[i].link;
		while(temp!=NULL)
		{
			cout<<"Key: "<<temp->key<<" value: "<<temp->value<<endl;
			temp=temp->link;
		}
		//cout<<endl;
	}
}
void search(string k, int n, struct node<string , string> unmap[])
{
	stringstream ss;
	ss<<k;
	string str = ss.str();
	
	unsigned int res=cal_hash(str);
	int pos;
	pos=res%20;
	
	struct node <string, string> *temp;
	temp=unmap[pos].link;
	//int temp=0;
	while(temp!=NULL)
	{
		if(temp->key == k)
		{
			cout<<temp->value<<endl;
			return;
		}
		temp=temp->link;
	}
	cout<<"Not present"<<endl;
	return;
}
void delete_value(string k, int n, struct node <string, string> unmap[])
{
	stringstream ss;
	ss<<k;
	string str = ss.str();
	
	unsigned int res=cal_hash(str);
	int pos;
	pos=res%20;
	
	struct node <string, string> *prev=NULL;
	struct node <string, string> *curr=NULL;
	
	curr=unmap[pos].link;
	while(curr!=NULL)
	{
		if(curr->key == k)
		{
			if(prev == NULL)
			{
				unmap[pos].link = curr->link;
				if(curr->link == NULL)
				{
					unmap[pos].tail = NULL;
				}
			}
			else
			{
				prev->link = curr->link;
				if(curr->link == NULL)
				{
					unmap[pos].tail = prev;
				}
			}
			break;
			
		}
		prev=curr;
		curr=curr->link;
	}
}
int main()
{
	int n;
	string key;
	string value;
	cout<<"Enter no of ele in unordered map: ";
	cin>>n;
	struct node<string,string> unmap[20];
	for(int i=0;i<20;i++)
	{
		//unmap[i].key=0;
		unmap[i].link=NULL;
		unmap[i].tail=NULL;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Enter key: ";
		cin>>key;
		
		cout<<"Enter value: ";
		cin>>value;
		
		insert(key,value,n,unmap);
		traverse(unmap,n);
	}
	cout<<"Enter ele to search: ";
	cin>>key;
	search(key,n,unmap);
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter ele to be deleted: ";
		cin>>key;
		delete_value(key, n, unmap);
		traverse(unmap,n);
	}
	
	return 0;
}

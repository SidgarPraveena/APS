#include<iostream>
#include<map>
#include<iterator>
#include"aps_1_t2_dynArr.h"

using namespace std;
struct node
{
	int data;
	struct node * prev;
	struct node * next;
};
void insertDll(struct node **first, int ele)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->prev=NULL;
	temp->next=NULL;
	if((*first)==NULL)
	{
		(*first)=temp;
	}
	else
	{
		(*first)->prev=temp;
		temp->next=(*first);
		(*first)=temp;
	}
	
	
}
int deleteDll(struct node **first)
{
	struct node * temp,*p=NULL;
	temp=(*first);
	while(temp->next!=NULL)
	{
		p=temp;
		temp=temp->next;
	}
	if(p==NULL)
	{
		(*first)=NULL;
	}
	else
	{
		p->next=temp->next;
	}
	return temp->data;
}
void deleteKeyDll(struct node ** first, int key)
{
	struct node * temp=(*first);
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			if(temp->prev==NULL)
			{
				(*first)=temp->next;
			}
			else if(temp->next==NULL)
			{
				temp->prev->next=NULL;
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			}
			break;
		}
		temp=temp->next;
	}
}
int main()
{
	int n,cLen,count=0;
	struct node * first=NULL;
	map< int, int > mp; 
	map<int, int>::iterator it ;
	cout<<"Enter cache length: "<<endl;
	cin>>cLen;
	count=0;
	do
	{
		cout<<"1) set"<<endl;
		cout<<"2) get"<<endl;
		cout<<"3) display cache"<<endl;
		cout<<"4) display map"<<endl;
		cout<<"0) exit"<<endl;
		cin>>n;
		if(n==1)
		{
			int key,value;
			cout<<"Enter key: ";
			cin>>key;
			cout<<"Enter value: ";
			cin>>value;
			
			it=mp.find(key);
			if(it==mp.end())
			{
				//cout<<count<<"  "<<cLen;
				mp.insert(pair<int, int>(key, value)); 
				if(count<cLen)
				{
					insertDll(&first,key);
					count++;
				}
				else
				{
					int res=deleteDll(&first);
					insertDll(&first,key);
					it=mp.find(res);
					mp.erase(it);
					
				}
			}
			else
			{
				it->second=value;
				deleteKeyDll(&first,key);
				insertDll(&first,key);
			}
		}
		else if(n==2)
		{
			int key;
			cout<<"Enter key: ";
			cin>>key;
			it=mp.find(key);
			if(it==mp.end())
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<it->second<<endl;
			}
		}
		else if(n==3)
		{
			struct node *temp=first;
			while(temp!=NULL)
			{
				cout<<temp->data<<"  ";
				temp=temp->next;
			}
			cout<<endl;
		}
		else if(n==4)
		{
			for (it = mp.begin(); it != mp.end(); ++it) 
			{ 
        			cout << '\t' << it->first << '\t' << it->second << '\n'; 
    			} 
		}
		
	}while(n);
    	
	return 0;
}

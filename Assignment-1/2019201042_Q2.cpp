#include<iostream>
#include <cstddef>
#include"2019201042_Q2.h"
using namespace std;


int main()
{

	int n,size=5,no=0;
	Deque<string> * ptr=new Deque<string>();
	do
	{
		cout<<"1) Initialise blank queue"<<endl;
		//cout<<"2) Initialise DEQUE of length n with all values of x"<<endl;
		cout<<"2) Push at the end"<<endl;
		cout<<"3) Pop at the end"<<endl;
		cout<<"4) Push at the front"<<endl;
		cout<<"5) Pop at the front"<<endl;
		cout<<"6) Print first"<<endl;
		cout<<"7) Print Last"<<endl;
		cout<<"8) Is empty??"<<endl;
		cout<<"9) size"<<endl;
		cout<<"10) Resize"<<endl;
		cout<<"11) Clear deque"<<endl;
		cout<<"12) Nth element"<<endl;
		cout<<"13) Traverse"<<endl;
		cout<<"0) EXIT()"<<endl;
		cout<< "Enter an option: ";
		cin>>n;
		if(n==1)
		{
			
			ptr->create_deque(size);
		}
		else if(n==2)
		{
			int res;
			string ele;
			no++;
			cin>>ele;
			res=ptr->insert_end_deque(ele,size);
			if(res==1)
			{
				ptr->resize(size*2,ptr->size_deque(size),size);
				size=size*2;
				res=ptr->insert_end_deque(ele,size);
			}
		}
		else if(n==3)
		{
			string res;
			no--;
			res=ptr->delete_end_deque(size);
			if(res!=-1)
			{
				cout<<"Element deleted is "<<res<<endl;
			}
			else
			{
				cout<<"No elements in deque"<<endl;
			}
		}
		else if(n==4)
		{
			int res;
			string ele;
			cin>>ele;
			no++;
			res=ptr->insert_beg_deque(ele,size);
			if(res==1)
			{
				ptr->resize(size*2,ptr->size_deque(size),size);
				size=size*2;
				res=ptr->insert_beg_deque(ele,size);
			}
		}
		else if(n==5)
		{	
			string res;
			no--;
			res=ptr->delete_beg_deque(size);
			if(res!=-1)
			{
				cout<<"Element deleted is "<<res<<endl;
			}
			else
			{
				cout<<"No element in deque"<<endl;
			}
		}
		else if(n==6)
		{
			ptr->prnt_first();	
		}
		else if(n==7)
		{
			ptr->prnt_rear();
		}
		else if(n==8)
		{
			int res;
			res=ptr->is_empty();
			if(res==1)
			{
				cout<<"Queue is empty"<<endl;
			}
			else
			{
				cout<<"Queue is not empty"<<endl;
			}
		}
		else if(n==9)
		{
			//int res;
			//res=ptr->size_deque(size);
			cout<<"Size is "<<size<<endl;
		}
		else if(n==10)
		{
			int inc;
			cout<<"Enter size: "<<endl;
			cin>>inc;
			ptr->resize(inc,ptr->size_deque(size),size);
			size=inc;
		}
		else if(n==11)
		{
			no=0;
			ptr->clear_deque();
		}
		else if(n==12)
		{
			int pos;
			cout<<"No of ele: "<<no<<endl;
			cout<<"Select ele to be displayed"<<endl;
			cin>>pos;
			ptr->pos_deque(pos,size);
		}
		else if(n==13)
		{
			ptr->traverse_deque(size);
			//cout<<front<<" "<<rear;
		}
	}while(n);
}

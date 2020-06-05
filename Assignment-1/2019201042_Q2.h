#include<iostream>
#include <cstddef>

using namespace std;
template<typename T>
class Deque
{
	public: 
	int front, rear;
	T *p;
	void create_deque(int size)
	{

		p=new T[size];
		front=-1;
		rear=-1;
	}
	int insert_end_deque(T ele,int size)
	{
		
		if(front==-1 && rear==-1)
		{
			
			front=rear=0;
			p[rear]=ele;
		}
		else
		{
			rear=(rear+1)%size;
			if(rear==front)
			{
				//cout<<"Deque full"<<endl;
				rear=rear-1;
				return 1;
			}
			else
			{
				p[rear]=ele;
			}
			
		}
		return 0;
	}
	void traverse_deque(int size)
	{
		int i,val;
		if(front==-1 || rear ==-1)
		{
			cout<<"Queue empty"<<endl;
			return ;
		}
		i=front;
		do
		{
			cout<<p[i]<<" ";
			i=(i+1)%size;
			val=(rear+1)%size;
		}while(i!=(val));
		cout<<endl;
		//cout<<front<<" "<<rear;
	}
	int size_deque(int size)
	{
		int i,count=0,val;
		if(front ==-1 || rear==-1)
			return 0;
		i=front;
		do
		{
			count++;
			i=(i+1)%size;	
			val=(rear+1)%size;
		}while(i!=val);
		return count;
	}
	T delete_end_deque(int size)
	{
		if(front==-1 && rear==-1)
		{
			return -1;
		}
		else 
		{
			T ele;
			ele=p[rear];
			p[rear]=0;
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				if(rear==0)
				{
					rear=size-1;
				}
				else
				{
					rear=rear-1;
				}
			}
			
			return ele;
		}
		
	}
	T delete_beg_deque(int size)
	{
		
		if(front==-1 && rear==-1)
		{

			return -1;
		}	
		else
		{
			T ele;
			ele=p[front];
			p[front]=0;
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				if(front==size-1)
				{
					front=0;
				}
				else
				{
					front=front+1;
				}
			}
			return ele;
		}
		
	}
	void prnt_first()
	{
		if(front!=-1)
		{
			cout<<"First ele is "<<p[front]<<endl;
		}
		
	}
	void resize(int inc,int s,int size)
	{
		int i,f1=0,r1=-1,val;
		if(inc<s)
		{
		
		}
		else
		{
			T *q=new T[size];
			if(front!=-1 || rear!=-1)
			{
				
				i=front;
				do
				{
					q[i]=p[i];
					i=(i+1)%size;
					val=(rear+1)%size;
				}while(i!=val);
			}
			p=new T[inc];
			i=front;
			do
			{
				r1++;
				p[r1]=q[i];
				i=(i+1)%size;
				val=(rear+1)%size;
			}while(i!=val);
			front=f1;
			rear=r1;
		}
	}
	void prnt_rear()
	{
		if(rear!=-1)
		{
			cout<<"Rear ele is "<<p[rear]<<endl;
		}
	}
	int is_empty()
	{
		if(front == -1)
			return 1;
		return 0;
	}
	void clear_deque()
	{
		front=-1;
		rear=-1;
	}
	void pos_deque(int pos,int size)
	{
		int i,count=0,val;
		if(front!=-1 || rear!= -1)
		{
			i=front;
			do
			{
				count++;
				
				if(count==pos)
				{
					cout<<"Ele is: "<<p[i]<<endl;
				}
				i=(i+1)%size;
				val=(rear+1)%size;
			}while(i!=val);
		}
	}
	int insert_beg_deque(T ele,int size)
	{

		if(front==-1 && rear==-1)
		{
			front=rear=0;
			p[front]=ele;
		}
		else 
		{
			if(front==0)
			{
				front=size-1;
			}
			else
			{
				front=front-1;
			}
			if(front==rear)
			{
				//cout<<"Deque is full"<<endl;
				front=(front+1)%size;
				return 1;			
			}
			else
			{
				p[front]=ele;
			}
		}
		return 0;
	}

};



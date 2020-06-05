#include<iostream>
int range;
using namespace std;
struct avlNode
{
	int height;
	int data;
	int sub;
	struct avlNode * left;
	struct avlNode * right;
};
struct avlNode * rotateLeft(struct avlNode * root)
{
	struct avlNode * temp=(struct avlNode *)malloc(sizeof(struct avlNode));
	temp=root->right;
	root->right=temp->left;
	temp->left=root;
	if(root->left == NULL && root->right == NULL)
	{
		root->height=1;
	}
	else if(root->left == NULL)
	{
		root->height=1+root->right->height;
	}
	else if(root->right == NULL)
	{
		root->height=1+root->left->height;
	}
	else
	{
		root->height=1+max(root->left->height,root->right->height);
	}
	if(temp->left == NULL && temp->right == NULL)
	{
		temp->height=1;
	}
	else if(temp->left == NULL)
	{
		temp->height=1+temp->right->height;
	}
	else if(temp->right == NULL)
	{
		temp->height=1+temp->left->height;
	}
	else
	{
		temp->height=1+max(temp->left->height,temp->right->height);
	}
	return temp;
}
struct avlNode * rotateRight(struct avlNode * root)
{
	struct avlNode * temp=(struct avlNode *)malloc(sizeof(struct avlNode));
	temp=root->left;
	root->left=temp->right;
	temp->right=root;
	if(root->left == NULL && root->right == NULL)
	{
		root->height=1;
	}
	else if(root->left == NULL)
	{
		root->height=1+root->right->height;
	}
	else if(root->right == NULL)
	{
		root->height=1+root->left->height;
	}
	else
	{
		root->height=1+max(root->left->height,root->right->height);
	}
	if(temp->left == NULL && temp->right == NULL)
	{
		temp->height=1;
	}
	else if(temp->left == NULL)
	{
		temp->height=1+temp->right->height;
	}
	else if(temp->right == NULL)
	{
		temp->height=1+temp->left->height;
	}
	else
	{
		temp->height=1+max(temp->left->height,temp->right->height);
	}
	return temp;
}
int getBal(struct avlNode * root)
{
	int balance;
	if(root == NULL)
		return 0;
	
	if(root->left == NULL && root->right == NULL)
		balance=0;
	else if(root->left == NULL)
	{
		balance=0-root->right->height;
	}
	else if(root->right == NULL)
	{
		balance=root->left->height;
	}
	else 
	{
		balance=root->left->height - root->right->height;
	}
	return balance;
}
void traverse(struct avlNode * root)
{
	if(root == NULL)
		return ;
	cout<<root->data<<" "<<root->height<<endl;
	traverse(root->left);
	traverse(root->right);
}
struct avlNode * insertNode(struct avlNode * root, int ele)
{
	if(root==NULL)
	{
		struct avlNode * temp=(struct avlNode *)malloc(sizeof(struct avlNode));
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		temp->data=ele;
		return temp;
	}
	if(ele<= root->data)
	{
		root->left=insertNode(root->left,ele);
	}
	else
	{
		root->right=insertNode(root->right,ele);
	}
	int balance=getBal(root);
	if(balance < -1)
	{
		if(root->right->left == NULL)
		{
			return rotateLeft(root);
		}
		else if(root->right->right==NULL)
		{
			root->right=rotateRight(root->right);
			return rotateLeft(root);
		}
		else if(root->right->right->height >= root->right->left->height)
		{
			return rotateLeft(root);
		}
		else
		{
			root->right=rotateRight(root->right);
			return rotateLeft(root);
		}
	}
	if(balance > 1)
	{
		if(root->left->right == NULL)
		{
			return rotateRight(root);
		}
		else if(root->left->left == NULL)
		{
			root->left=rotateLeft(root->left);
			return rotateRight(root);
		}
		else if(root->left->left->height >= root->left->right->height)
		{
			return rotateRight(root);
		}
		else
		{
			root->left=rotateLeft(root->left);
			return rotateRight(root);
		}
	}
	if(root->left == NULL)
	{
		root->height=1+root->right->height;
	}
	else if(root->right == NULL)
	{
		root->height=1+root->left->height;
	}
	else
	{
		root->height=1+max(root->left->height,root->right->height);
	}
	return root;
}
struct avlNode * minNode(struct avlNode * n)
{
	struct avlNode * cur=n;
	while(cur->left!=NULL)
		cur=cur->left;
	return cur;
}

struct avlNode * deleteNode(struct avlNode * root, int del)
{
	if(root==NULL)
	{
		return root;
	}
	if(del<root->data)
		root->left=deleteNode(root->left, del);
	else if(del>root->data)
		root->right=deleteNode(root->right, del);
	else
	{
		if((root->left == NULL) || (root->right == NULL))
		{
			struct avlNode *temp=root->left ? root->left: root->right;
			if(temp == NULL)
			{
				temp=root;
				root=NULL;
			}
			else 
				*root = *temp;
		}
		else
		{
			struct avlNode *temp=minNode(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
		}
	}
	if(root==NULL)
		return root;
	if(root->left == NULL && root->right == NULL)
	{
		root->height=1;
	}
	else if(root->left==NULL)
	{
		root->height=1+root->right->height;
	}
	else if(root->right==NULL)
	{
		root->height=1+root->left->height;
	}
	else
	{
		root->height=1+max(root->left->height, root->right->height);
	}
	int bal=getBal(root);
	if(bal > 1 && getBal(root->left)>=0)
		return rotateRight(root);
	if(bal>1 && getBal(root->left)<0)
	{
		root->left=rotateLeft(root->left);
		return rotateRight(root);
	}
	if(bal<-1 && getBal(root->right)<=0)
		return rotateLeft(root);
	if(bal<-1 && getBal(root->right)>0)
	{
		root->right=rotateRight(root->right);
		return rotateLeft(root);
	}
	return root;
}
int isThere(struct avlNode * root,int search)
{
	if(root==NULL)
		return 0;
	if(root->data ==  search)
	{
		cout<<"YES found"<<endl;
		return 1;
	}
	else if(root->data < search)
	{
		return isThere(root->right, search);
	}
	else if(root->data>search)
	{
		return isThere(root->left, search);
	}
	return 0;
}
int getClose(struct avlNode * root, struct avlNode *parent,int close)
{
	if(root==NULL)
		return 0;
	if(root->data==close)
	{
		if(parent==NULL)
		{
			if(root->left==NULL && root->right == NULL)
			{
				return root->data;
			}
			else if(root->left==NULL)
			{
				return root->right->data;
			}
			else if(root->right==NULL)
			{
				return root->left->data;
			}
			else
			{
				int l=root->left->data;
				int r=root->right->data;
				int p=root->data;
				if((p-l)<=(r-p))
					return l;
				else
					return r;
			}
		}
		else if(root->left == NULL && root->right == NULL)
		{
			return parent->data;
		}
		else if(root->left == NULL)
		{
			int par=parent->data;
			int r=root->right->data;
			int p=root->data;
			if(abs(p-par)<abs(r-p))
			{
				return par;
			}
			else if(abs(p-par)>abs(r-p))
			{
				return r;
			}
			else
			{
				if(par>r)
					return r;
				else
					return par;
			}
		}
		else if(root->right == NULL)
		{
			int par=parent->data;
			int l=root->left->data;
			int p=root->data;
			if(abs(p-par)<abs(p-l))
			{
				return par;
			}
			else if(abs(p-par)>abs(p-l))
			{
				return l;
			}
			else
			{
				if(par>l)
					return l;
				else
					return par;
			}
		}
		else
		{
			int par=parent->data;
			int l=root->left->data;
			int r=root->right->data;
			int p=root->data;
			if((p-l)<=(r-p))
			{
				if((par-p)<(p-l))
				{
					return par;
				}
				else
				{
					return l;
				}
			}
			else
			{
				//return r;
				if((par-p)<=(r-p))
				{
					return par;
				}
				else
					return r;
			}
			
		}
	}
	else if(root->data < close)
	{
		return getClose(root->right,root,close);
	}
	else if(root->data > close)
	{
		return getClose(root->left,root,close);
	}
}
int checkK(struct avlNode * root, int k)
{
	int val;
	if(k==1 && root->height==1)
	{
		//cout<<root->data<<endl;
		return root->data;
	}
	//cout<<"k value : "<<k<<" "<<root->data<<" "<<root->left->sub<<endl;
	if(root->left != NULL && root->right != NULL)
	{
		//cout<<"k value : "<<k<<" "<<root->data<<" "<<root->left->sub<<endl;	
		//val=root->left->sub+1;
		if(k== root->left->sub+1)
		{
			//cout<<root->data<<endl;
			return root->data;
		}
		else if(k <=root->left->sub)
		{
			if(root->left->left == NULL && (root->height)==2)
			{
				//cout<<root->left->data<<endl;
				return root->left->data;
			}
			return checkK(root->left, k);
		}
		else 
		{
			//cout<<"Hello"<<endl;
			if(root->right->right == NULL && (root->height)==2 )
			{
				//cout<<root->right->data<<endl;
				return root->right->data;
			}
			return checkK(root->right, k-root->left->sub-1);
		}
	}
	if(root->right ==  NULL)
	{
		if(k==1)
		{
			//cout<<root->left->data<<endl;
			return root->left->data;
		}
		else if(k==2)
		{
			//cout<<root->data<<endl;
			return root->data;
		}
		
	}
	if(root->left == NULL)
	{
		if(k==1)
		{
			//cout<<root->data<<endl;
			return root->data;
		}
		else if(k==2)
		{
			//cout<<root->right->data<<endl;
			return root->right->data;
		}
	}
	return 0;
}
int trav(struct avlNode * root)
{
	if(root->left == NULL && root->right == NULL)
	{
		root->sub=1;
		return 1;
	}
	else if(root->left == NULL)
	{
		root->sub=1+trav(root->right);
	}
	else if(root->right == NULL)
	{
		root->sub=1+trav(root->left);
	}
	else
	{
		root->sub=1+trav(root->left)+trav(root->right);
	}
	return root->sub;
}
void getRight(struct avlNode * root, int b)
{
	if(root == NULL)
		return;
	if(root->data == b)
	{
		if(root->right != NULL)
		{
			range = range - root->right->sub;
		}
		return;
	}
	else if(root->data >b)
	{
		if(root->right!=NULL)
		{
			range = range - root->right->sub-1;
		}
		else
			range = range -1;
		getRight(root->left,b);
	}
	else
	{
		getRight(root->right,b);
	}
}
void getLeft(struct avlNode * root,int a)
{
	if(root == NULL)
		return;
	if(root->data == a)
	{
		if(root->left != NULL)
		{
			range = range - root->left->sub;
		}
		return;
	}
	else if(root->data > a)
	{
		getLeft(root->left,a);
	}
	else
	{
		if(root->left != NULL)
		{
			range = range - root->left->sub-1;
		}
		else
			range = range-1;
		getLeft(root->right,a);
	}
}
int main()
{
	int ele,n,del,num,search,res,close;
	struct avlNode * root=NULL;
	cout<<"Enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter ele: ";
		cin>>ele;
		root=insertNode(root,ele);
	}	
	traverse(root);
	cout<<"Enter no.of ele to be deleted : ";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter num to be deleted: ";
		cin>>del;
		root=deleteNode(root,del); 
		if(root==NULL)
		{
			cout<<"No ele"<<endl;
			break;
		}
		traverse(root);
	}
	cout<<"Enter no. of values to check: ";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter num to search: ";
		cin>>search;
		res=isThere(root,search);
		if(res==0)
			cout<<"NOT found"<<endl;
	}
	cout<<"Enter no. of ele to find closest value: ";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter ele whose closest has to be found: ";
		cin>>close;
		res=getClose(root,NULL,close);
		cout<<res<<endl;
	}
	cout<<"Enter no. of ele whose kth smallest is known ";
	cin>>num;
	int k;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter k: ";
		cin>>k;
		int val=trav(root);
		int res1=checkK(root,k);
		cout<<res1<<endl;
	}
	cout<<"Enter no. of ranges to be known ";
	cin>>num;
	int a,b;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter a,b: ";
		cin>>a>>b;
		if(a<=b)
		{
			range=n;
			getLeft(root,a);
			int lef=n-range;
			range=n;
			getRight(root,b);
			int rig=n-range;
			int res=n-(lef+rig);
			cout<<res;
		}
		else
		{
			cout<<"Enter correct range"<<endl;
		}
	}
	
}

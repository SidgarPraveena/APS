#include<iostream>
#include <iomanip>


using namespace std;
struct avlNode
{
	int height;
	int data;
	int l;
	int r;
	int sub;
	struct avlNode * left;
	struct avlNode * right;
};
struct avlNode * rotateLeft(struct avlNode * root)
{
	struct avlNode * temp=(struct avlNode *)malloc(sizeof(struct avlNode));
	temp=root->right;
	root->r=temp->l;
	temp->l=root->l+root->r+1;
	root->sub=root->l+root->r+1;
	temp->sub=temp->l+temp->r+1;
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
	root->l=temp->r;
	temp->r=root->l+root->r+1;
	temp->sub=temp->l+temp->r+1;
	root->sub=root->l+root->r+1;
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
struct avlNode * insertNode(struct avlNode * root, int ele)
{
	if(root==NULL)
	{
		struct avlNode * temp=(struct avlNode *)malloc(sizeof(struct avlNode));
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		temp->data=ele;
		temp->l=0;
		temp->r=0;
		temp->sub=1;

		return temp;
	}
	if(ele<= root->data)
	{
		root->l++;
		root->sub=root->l+root->r+1;
		root->left=insertNode(root->left,ele);
	}
	else
	{
		root->r++;
		root->sub=root->l+root->r+1;
		root->right=insertNode(root->right,ele);
	}
	int balance;
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
void printTree(struct avlNode * root)
{
	if(root == NULL)
	{	
		return;
	}
	printTree(root->left);
	cout<<root->data<<" "<<root->l<<" "<<root->r<<" "<<root->sub<<" ";
	printTree(root->right);
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
int main()
{
	int ele,n,k,res1,one,pos,d;
	float res;
	struct avlNode * root=NULL,*temp;
	cout<<"Enter n value: "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		cout<<"Enter ele: ";
		cin>>ele;
		root=insertNode(root,ele);
		if((i+1)%2 == 0)
		{
			int res1=checkK(root,((i+1)/2));
			int res2=checkK(root,((i+1)/2)+1);
			//cout<<res1<<" "<<res2<<" "<<endl;
			cout<<fixed<<setprecision(1)<<(float)(((res1+res2)*(1.0))/(2.0))<<endl;
		}
		else
		{
			int res1=checkK(root,((i+1)/2)+1);
			cout<<fixed<<setprecision(1)<<(float)res1<<endl;
		}
		//cout<<endl;
		//printTree(root);
	}
	
}

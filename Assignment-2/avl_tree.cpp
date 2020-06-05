#include<iostream>

using namespace std;
struct avlNode
{
	int height;
	int data;
	struct avlNode * left;
	struct avlNode * right;
};
struct avlNode * rotateLeft(struct avlNode * root)
{
	struct avlNode * temp=(struct avlNode *)malloc(sizeof(struct avlNode));
	temp=root->right;
	root->right=temp->left;
	temp->left=root;
	//root->height=1+max(root->left->height, root->right->height);
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
	//temp->height=1+max(temp->left->height, temp->right->height);
	return temp;
}
struct avlNode * rotateRight(struct avlNode * root)
{
	struct avlNode * temp=(struct avlNode *)malloc(sizeof(struct avlNode));
	temp=root->left;
	root->left=temp->right;
	temp->right=root;
	//root->height=1+max(root->left, root->right);
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
	//temp->height=1+max(temp->left->height, temp->right->height);
	return temp;
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
	int balance;//=root->left->height-root->right->height;
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
	//cout<<"balance"<<balance<<endl;
	if(balance < -1)
	{
		if(root->right->left == NULL)
		{
			//cout<<"HEllo"<<endl;
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
int main()
{
	int ele,n;
	struct avlNode * root=NULL;
	while(n)
	{
		cout<<"Enter n: ";
		cin>>n;
		cout<<"Enter ele: ";
		cin>>ele;
		root=insertNode(root,ele);
		traverse(root);
	}	
}

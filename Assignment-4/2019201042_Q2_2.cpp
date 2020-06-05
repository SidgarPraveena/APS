#include<iostream>

using namespace std;
template <typename T1,typename T2>
struct avlNode
{
	int height;
	T1 key;
	T2 value;
	struct avlNode * left;
	struct avlNode * right;
};
struct avlNode <string,string>* rotateLeft(struct avlNode<string,string> * root)
{
	struct avlNode<string,string> * temp=(struct avlNode<string,string> *)malloc(sizeof(struct avlNode<string,string>));
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
struct avlNode <string,string>* rotateRight(struct avlNode <string,string>* root)
{
	struct avlNode <string,string>* temp=(struct avlNode<string,string> *)malloc(sizeof(struct avlNode<string,string>));
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
void traverse(struct avlNode<string,string> * root)
{
	if(root == NULL)
		return ;
	
	traverse(root->left);
	cout<<"Key: "<<root->key<<" value: "<<root->value<<" height: "<<root->height<<endl;
	traverse(root->right);
}
int searchNode(struct avlNode<string, string> * root,string key, int &temp)
{
	if(root == NULL)
		return temp;
	if(root->key == key)
	{
		temp=1;
		cout<<root->value<<endl;
		return temp;
	}
	searchNode(root->left,key, temp);
	searchNode(root->right,key, temp);
	return temp;
}
struct avlNode<string,string>* insertNode(struct avlNode<string,string> * root, string k,string v)
{
	if(root==NULL)
	{
		
		struct avlNode<string,string>* temp=(struct avlNode <string,string>*)malloc(sizeof(struct avlNode <string,string>));
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		temp->key=k;
		temp->value=v;
		return temp;
	}
	if(k<= root->key)
	{
		root->left=insertNode(root->left,k,v);
	}
	else
	{
		root->right=insertNode(root->right,k,v);
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
int getBal(struct avlNode<string, string> * root)
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
struct avlNode<string, string> * minNode(struct avlNode <string, string>* n)
{
	struct avlNode <string, string>* cur=n;
	while(cur->left!=NULL)
		cur=cur->left;
	return cur;
}
struct avlNode<string,string> * deleteNode(struct avlNode <string,string>* root, string del)
{
	if(root==NULL)
	{
		return root;
	}
	if(del<root->key)
		root->left=deleteNode(root->left, del);
	else if(del>root->key)
		root->right=deleteNode(root->right, del);
	else
	{
		if((root->left == NULL) || (root->right == NULL))
		{
			struct avlNode<string,string> *temp=root->left ? root->left: root->right;
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
			struct avlNode<string, string> *temp=minNode(root->right);
			root->key=temp->key;
			root->right=deleteNode(root->right,temp->key);
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
int main()
{
	int n;
	string key;
	string value;
	struct avlNode <string,string>* root=NULL;
	/*while(n)
	{
		cout<<"Enter n: ";
		cin>>n;
		cout<<"Enter ele: ";
		cin>>ele;
		root=insertNode(root,ele);
		traverse(root);
	}*/
	cout<<"Enter no of ele: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter key: ";
		cin>>key;
		cout<<"Enter value: ";
		cin>>value;
		root=insertNode(root,key,value);
		traverse(root);
	}	
	//for(int i=0;i<n;i++)
	//{
		cout<<"Enter key to be deleted: ";
		cin>>key;
		root=deleteNode(root,key);
		traverse(root);
	//}
	
	cout<<"Enter key to search: ";
	cin>>key;
	int res=0;
	res=searchNode(root,key,res);
	//cout<<res<<endl;
	if(res==0)
	{
		cout<<"Element not found"<<endl;
	}
}

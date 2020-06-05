#include<iostream>
#include <bits/stdc++.h>
//#define unsigned long long ull
using namespace std;
struct trie
{
    int value;
    struct trie * left;
    struct trie * right;
};
void traverse(struct trie * root)
{
    struct trie *temp;
    temp=root;
    if(temp->left == NULL && temp->right == NULL)
    {
        cout<<temp->value<<" ";
        return;
    }
    else if(temp->left == NULL)
    {
        traverse(temp->right);
    }
    else if(temp->right == NULL)
    {
        traverse(temp->left);
    }
    else
    {
        traverse(temp->left);
        traverse(temp->right);
    }
}
void insert(struct trie * root, int ele)
{
    struct trie * temp;
    temp=root;
    int i,b,c;
    for(i=31;i>=0;i--)
    {
        b=ele&(1<<i);
        if(b==0)
        {
            if(temp->left == NULL)
            {
                temp->left=(struct trie *)malloc(sizeof(struct trie));
                temp->left->left=NULL;
                temp->left->right=NULL;
            }
            temp=temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right=(struct trie *)malloc(sizeof(struct trie));
                temp->right->left=NULL;
                temp->right->right=NULL;
            }
            temp=temp->right;
        }
    }
    temp->value=ele;
}
int xor_calc(struct trie *root, int ele)
{
    struct trie *temp=root;
    int b,i;
    for(i=31;i>=0;i--)
    {
        b=ele&(1<<i);
        if(b==0)
        {
            if(temp->right!=NULL)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        else
        {
            if(temp->left!=NULL)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
    }
    return temp->value;
}
int main()
{
    int n,i,ele; 
    int max=INT_MIN,res;
    struct trie *root=NULL;
    cin>>n;
    root=(struct trie *)malloc(sizeof(struct trie));
    root->left=NULL;
    root->right=NULL;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        insert(root,ele);
        //traverse(root);
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        res=xor_calc(root,ele);
        cout<<res^ele;
    }
    return 0;
}


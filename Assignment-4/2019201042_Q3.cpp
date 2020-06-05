#include<iostream>

using namespace std;

struct strng
{
	char *arr;
	struct strng *link;
	struct strng *tail;
};
/*class StringBuilder
{
	public:
		struct strng * stringInitialise(char a[100]);
		
};
struct strng * StringBuilder:: stringInitialise(char a[100])
{
	struct strng *new_node = (struct strng *)malloc(sizeof(struct strng));
	int i=0;
	while(a[i]!='\0')
	{
		new_node->arr[i]=a[i];
		i++;
	}
	new_node->link=NULL;
	return new_node;
}*/
struct strng * init(char name[100])
{
	int i=0;
	struct strng *one= (struct strng *)malloc(sizeof(struct strng));
	one->link=NULL;
	one->tail=NULL;
	/*while(name[i]!='\0')
	{
		one->arr[i]=name[i];
		i++;
	}*/
	one->arr=name;
	return one;
}
void append(struct strng *one, struct strng *two)
{	
	if(one->tail == NULL)
	{
		one->link=two;
		one->tail=two;
	}	
	else
	{	
		one->tail->link=two;
		one->tail=two;
	}
}
void zAlgo(char text[100], char pattern[100],int n,int m)
{
	int z[100];
	z[0]=0;
	int count,k;
	for(int i=1;i<n;i++)
	{
		count=0;
		k=i;
		for(int j=0;j<i;j++)
		{
			if(text[j]==text[k])
			{
				count++;
				k++;
			}
			else
			{
				break;
			}
		}
		z[i]=count;
		int right=count+i;
		for(int j=1;j<count;j++)
		{
			i++;
			if(z[j]+i < right)
			{
				z[i]=z[j];
			}
			else
			{
				i--;
				break;
			}
		}
	}
	int temp=0;
	for(int i=0;i<n;i++)
	{	
		if(z[i] == m)
		{
			temp=1;
			cout<<i-m-1<<" ";
			return ;
		}
	}
	if(temp!=1)
		cout<<"-1";

}
void findSubString(struct strng * root, char pattern[100])
{
	char text[100];
	struct strng *temp;
	temp=root;
	int i=0;
	int j=0;
	while(pattern[j]!='\0')
	{
		text[i]=pattern[j];
		j++;
		i++;
	}
	int p=j;
	text[i]='$';
	i++;
	while(temp!=NULL)
	{
		j=0;
		while(temp->arr[j] != '\0')
		{
			text[i]=temp->arr[j];
			j++;
			i++;
		}
		temp=temp->link;
	}
	text[i]='\0';
	/*int k=0;
	while(text[k]!='\0')
	{
		cout<<text[k]<<" ";
		k++;
	}
	cout<<endl; */
	zAlgo(text,pattern,i,p);
}
void prntAppend(struct strng *root)
{
	struct strng *temp;
	temp=root;
	while(temp!= NULL)
	{
		/*int i=0;
		while(temp->arr[i]!='\0')
		{
			cout<<temp->arr[i]<<" ";
			i++;
		}*/
		cout<<temp->arr;
		temp=temp->link;
	}
	cout<<endl;
}
int main()
{
	char name[100],name1[100];
	cout<<"Enter string1: ";
	cin>>name;
	struct strng *one; 
	one=init(name);
	cout<<one->arr<<endl;
	
	cout<<"Enter string2: ";
	cin>>name1;
	struct strng *two=init(name1);
	cout<<two->arr<<endl;
	
	
	cout<<one->arr<<endl;
	cout<<two->arr<<endl;
	
	append(one,two);
	prntAppend(one);
	//prntAppend(two);
	
	cout<<"Enter string3: ";
	cin>>name;
	struct strng *three=init(name);
	cout<<three->arr<<endl;
	
	/*append(one,three);
	prntAppend(one);*/
	
	
	
	cout<<"Enter string to check pattern: ";
	cin>>name;
	struct strng *six=init(name);
	cout<<six->arr<<endl;
	char pattern[100];
	cout<<"Enter pattern: ";
	cin>>pattern;
	findSubString(six,pattern);
	
	return 0;
}

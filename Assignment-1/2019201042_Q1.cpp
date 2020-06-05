#include<iostream>
#include<bits/stdc++.h> 

#define MAX 500
using namespace std;

int multiply(int x, int res[], int res_size)
{
	int carry=0,i,prod;
	for(i=0;i<res_size;i++)
	{
		prod=res[i]*x + carry;
		res[i]=prod%10;
		carry=prod/10;
	}	
	while(carry)
	{
		res[res_size]=carry%10;
		carry=carry/10;
		res_size++;
	}
	return res_size;
}

void factorial(int n)
{
	int res[MAX],i;
	res[0]=1;
	int res_size=1;
	for(i=2;i<=n;i++)
	{
		res_size=multiply(i,res,res_size);
	}
	//printf("Factorial of %d is: ",n);
	cout<<"Factorial of "<<n<<"is :";
	for(i=res_size-1;i>=0;i--)
	{
		//printf("%d",res[i]);
		cout<<res[i];
	}
	//printf("\n");
	cout<<endl;
}

int main()
{
	int num,n,num1,num2;
	string str1,str2;
	do
	{
		cout<<"1) Factorial "<<endl;
		cout<<"2) GCD "<<endl;
		cout<<"3) power "<<endl;
		cout<<"0) Exit"<<endl;
		cin>>n;
		
		if(n==1)
		{
			cout<<"Enter num "<<endl;
			cin>>num;
			factorial(num);
		}
		
	}while(n);
}

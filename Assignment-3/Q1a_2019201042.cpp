#include<iostream>
#include<cstring>
#include <bits/stdc++.h> 

using namespace std;

struct suffix
{
	int n=0;
	char *arr;
	//char arr1[100];
};

int cmp(struct suffix s1, struct suffix s2)
{
	return strcmp(s1.arr,s2.arr)>0 ? 0:1;
}
int main()
{
	char str[100];
	
	cin>>str;
	struct suffix suffixes[strlen(str)];
	for(int i=0;i<strlen(str);i++)
	{
		char temp[100];
		suffixes[i].arr=str+i;
		
		//strcpy(suffixes[i].arr1,str+i);
		//strncat(suffixes[i].arr1,str,(strlen(str)-strlen(suffixes[i].arr1)));
	}
	sort(suffixes,suffixes+strlen(str),cmp);
	if(strlen(suffixes[0].arr)==1)
	{
		
	}
	else
	{
		cout<<suffixes[0].arr;
		for(int i=0;i<strlen(str)-strlen(suffixes[0].arr);i++)
		{
			cout<<str[i];
		}
	}
	return 0;
}

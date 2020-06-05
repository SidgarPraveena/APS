#include<iostream>
#include<bits/stdc++.h> 
#include<vector>

using namespace std;

void dfs(vector<int> mat[],int v,vector<int> &visited,int src,int dist[][2],int &time,int parent[],int prev)
{
	if(visited[src]==0)
	{
		time++;
		dist[src][0]=dist[src][1]=time;
		visited[src]=1;
		parent[src]=prev;
		prev=src;
		//cout<<src<<endl;
	}
	
	for(int i=0;i<mat[src].size();i++)
	{
		if(visited[mat[src][i]]==0)
		{
			dfs(mat,v,visited,mat[src][i],dist,time,parent,prev);	
		}
		
		if(i==mat[src].size()-1)
		{
			//cout<<"Checkpoint "<<src<<" "<<parent[src]<<" "<<mat[src].size()<<endl;
			//cout<<"Checkpoint "<<src<<endl;
			int min=INT_MAX;
			int temp=0;
			int res;
			for(int j=0;j<mat[src].size();j++)
			{
				//cout<<mat[src][j]<<" ";
				if(mat[src][j]!=parent[src] && dist[mat[src][j]][1]<min)
				{
					min=dist[mat[src][j]][1];
					//cout<<mat[src][j]<<" ";
				}
				if(mat[src][j]!=parent[src] && dist[mat[src][j]][1] >= dist[src][0] && dist[src][0]!=0)
				{
					//cout<<src<<" src"<<endl;
					res=src;
					temp=1;
					//break;
				}
			}
			if(temp==1)
			{
				temp=0;
				cout<<src<<" src"<<endl;
			}
			//cout<<min<<" min"<<endl;
			if(dist[src][1]>min)
			{
				//cout<<src<<" src"<<endl;
				dist[src][1]=min;
			}
			/*else
			{
				dist[src][1]=min;
			}*/
		}
	}
}
int main()
{
	int v,e,l,r,time=-1;
	cout<<"Enter no of vertices: ";
	cin>>v;
	cout<<"Enter no of edges:  ";
	cin>>e;
	vector<int> mat[v],visited;
	for(int i=0;i<v;i++)
	{
		visited.push_back(0);
	}
	for(int i=0;i<e;i++)
	{
		cout<<"Enter edge: ";
		cin>>l>>r;
		mat[l].push_back(r);
		mat[r].push_back(l);
	}
	/*for(int i=0;i<v;i++)
	{
		cout<<i<<endl;
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int dist[v][2];
	int parent[v];
	int s=1;
	dfs(mat,v,visited,s,dist,time,parent,-1);
	int par=s;
	int count=0;
	if(mat[s].size()>=2)
	{
		for(int i=0;i<mat[s].size();i++)
		{
			if(parent[mat[s][i]] == par)
			{
				count++;
				//cout<<"Not possible"<<mat[s][i];
				//return 0;
			}
			if(count>1)
				break;
		}
		if(count>1)
			cout<<s<<endl;
	}
	
	/*for(int i=0;i<v;i++)
	{
		cout<<parent[i]<<" "<<dist[i][0]<<" "<<dist[i][1]<<endl;
	}*/
	return 0;
}

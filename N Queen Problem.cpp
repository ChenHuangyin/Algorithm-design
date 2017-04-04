#include<bits/stdc++.h>
using namespace std;

bool check(int t,int x[])
{
	for(int i=1; i<t; i++)
	{
		if(abs(t-i) == abs(x[t]-x[i]) || x[i]==x[t]) 
		return false;
	}
	return true;
}

void solve(int n,int t,int x[],int &sum)
{
	if(t>n)
	{
		sum++;
		return;
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			x[t]=i; 
			if(check(t,x))  
			solve(n,t+1,x,sum);
		}
	}
}

int main()
{
	int n;
	while(cin >> n)
	{
		int x[10]; 
		int sum=0;
		memset(x,0,sizeof(x));
		
		solve(n,1,x,sum); 
		cout << sum << endl; 
	}
	return 0;
}

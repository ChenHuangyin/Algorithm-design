#include <bits/stdc++.h>
using namespace std;

void solve(int *p1,int *p2,int begin,int end,int n,int *ans)
{
	map<int,int> flag;
	for(int i=begin;i<=end;i++)
	{
		ans[i]=p1[i];
		flag[p1[i]]=1;
	}
	for(int i=0,j=0;i<n;i++)
	{
		if(j>=n)
		break;
		if(j==begin)
		j=end+1;
		
		if(flag.find(p2[i])==flag.end())
		{
			ans[j]=p2[i];
			j++;
		}
	}
}

int main()
{
	int n;
	while(cin >> n)
	{
		int *parents1=new int [n];
		int *parents2=new int [n];
		for(int i=0;i<n;i++)
		{
			cin >> parents1[i];
		}
		for(int i=0;i<n;i++)
		{
			cin >> parents2[i];
		}
		
		int begin,end;
		cin >> begin >> end;
		
		int *ans1=new int [n];
		int *ans2=new int [n];
		
		solve(parents1,parents2,begin,end,n,ans1);
		solve(parents2,parents1,begin,end,n,ans2);
		
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			cout << " ";
			cout << ans1[i];
		}
		cout << endl;
		
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			cout << " ";
			cout << ans2[i];
		}
		cout << endl;
	}
	return 0;
}

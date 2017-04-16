#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];

int main()
{
	int N;
	while(cin >> N)
	{
		memset(dp,0,sizeof(dp));
		int *data=new int[2*N+1];
		for(int i=1;i<=N;i++)
		{
			cin >> data[i];
			data[N+i]=data[i];
		}
		
		for(int i=2*N;i>=1;i--)
		for(int j=i;j<=i+N;j++)
		{
			if(i==j)continue;
			for(int k=i;k<j;k++)
			{
				dp[i][j]=max(dp[i][j], dp[i][k]+dp[k+1][j]+data[i]*data[j+1]*data[k+1]);
			}
		}
		int ans=0;
		for(int i=1;i<=N;i++)
		{
			ans=max(ans,dp[i][i+N-1]);
		}
		cout << ans << endl;
		delete [] data;
	}
	return 0;
}

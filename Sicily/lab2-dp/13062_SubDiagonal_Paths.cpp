#include<iostream>
#include<cstring>
using namespace std;

long long dp[31][31];

int main()
{
	int n;
	while(cin >> n && n!=0)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i==j && j!=0)
				dp[i][j]=dp[i][j-1];
				else if(i>j && j!=0)
				dp[i][j]=dp[i][j-1]+dp[i-1][j];
				else if(i>j && j==0)
				dp[i][j]=1;
			}
		}
		cout << dp[n][n] << endl;
	}
	return 0;
}

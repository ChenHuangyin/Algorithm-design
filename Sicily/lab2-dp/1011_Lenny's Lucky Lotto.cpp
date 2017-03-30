#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

long long dp[11][2001];
int main()
{
	int C,n,m;
	cin >> C;
	for(int _case=1; _case<=C; _case++)
	{
		memset(dp,0,sizeof(dp));
		cin >> n >> m;
		for(int i=0;i<=2000;i++)
		{
			dp[0][i]=i; 
		}
		for(int i=1;i<n;i++)
		{
			for(int j=pow(2,i);j<=m;j++)
			{
				dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
			}
		}
		cout << "Case " << _case << ": n = " << n << ", m = " << m << ", # lists = " << dp[n-1][m] << endl;
	}
	return 0;
}

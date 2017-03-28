#include<bits/stdc++.h>
using namespace std;

double dp[7][10005];
double value[7]={0.0,0.01,0.05,0.10,0.25,0.50,1.00};
int num[7];
int weight[7]={0,3,5,2,6,11,8};

int main()
{
	int G;
	while(cin >> G)
	{
		for(int i=1;i<=6;i++)
		cin >> num[i];
		for(int i=0;i<=6;i++)
		{
			dp[i][0]=0;
			dp[0][i]=0;
		}
		
		for(int i=1;i<=6;i++)
		{
			for(int j=0;j<=G;j++)
			{
				dp[i][j]=-1;
				int maxC=min(num[i],j/weight[i]);
				for(int k=0;k<=maxC;k++)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-k*weight[i]]+(double)k*value[i]);
				}
			}
		}
		cout << "$" << fixed << setprecision(2) << dp[6][G] << endl;
	}
	return 0;
}

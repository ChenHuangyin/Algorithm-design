#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T,N,M,C,P,S;
	cin >> T;
	while(T--)
	{
		cin >> N >> M >> C >> P >> S;
		int ans=M;
		for(int i=1;i<=S;i++)
		{
			if((S-i+1)*C>P)
			{
				while(ans-P>=0)
				{
					ans-=P;
					N++;
				}
			}
			ans+=(N*C);
		}
		cout << ans << endl;
	}
}

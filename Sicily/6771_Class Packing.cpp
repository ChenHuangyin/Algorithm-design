#include<bits/stdc++.h>
using namespace std;

int main()
{
	int grade[7];
	while(1)
	{
		memset(grade,0,sizeof(grade));
		bool flag=1;
		int ans=0;
		for(int i=0;i<7;i++)
		{
			cin >> grade[i];
			if(grade[i]!=0)
			flag=0;
		}
		if(flag) break;
		for(int i=0;i<7;i++)
		{
			if(i>=0 && i<=2)
			{
				while(grade[i]>=20)
				{
					grade[i]-=20;
					ans++;
				}
				if(grade[i]!=0)
				{
					ans++;
					int left=20-grade[i];
					if(grade[i+1]>left)
					{
						grade[i+1]-=left;
					}
					else
					grade[i+1]=0;
				}
			}
			if(i>=3 && i<=4)
			{
				while(grade[i]>=25)
				{
					grade[i]-=25;
					ans++;
				}
				if(grade[i]!=0)
				{
					ans++;
					int left=25-grade[i];
					if(grade[i+1]>left)
					{
						grade[i+1]-=left;
					}
					else
					grade[i+1]=0;
				}
			}
			if(i>=5 && i<=6)
			{
				while(grade[i]>=30)
				{
					grade[i]-=30;
					ans++;
				}
				if(grade[i]!=0)
				{
					ans++;
					int left=30-grade[i];
					if(grade[i+1]>left)
					{
						grade[i+1]-=left;
					}
					else
					grade[i+1]=0;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	string data;
	int *lens;
	int cnt=0;
	while(cin >> n >> k)
	{
		if(n==0 && k==0) break;
		
		if(cnt!=0)
		cout << endl;
		cnt++;
		lens=new int [n];
		for(int i=0;i<n;i++)
		{
			cin >> data;
			lens[i]=data.length();
		}
		sort(lens,lens+n);
		bool flag=1;
		for(int i=0;i<n/k;i++)
		{
			double sum=0;
			for(int j=0;j<k;j++)
			{
				sum+=lens[j+i*k];
			}
			
			double average=sum/(double)k;
			for(int j=0;j<k;j++)
			{
				if(average-lens[j+i*k]-2.0>0.000001)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
		cout << "Case " << cnt << ": yes" << endl;
		else
		cout << "Case " << cnt << ": no" << endl;
	}
	return 0;
}

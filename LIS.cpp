#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *data=new int [n];
	int *ans=new int [n+1];
	for(int i=0;i<n;i++) 
	{
		cin >> data[i];
		ans[i]=0;
	}
	ans[n]=0;
	ans[1]=data[0];
	int len=1;
	for(int i=1;i<n;i++)  //O(nlogn)
	{
		if(data[i]>ans[len])
		ans[++len]=data[i];
		else
		{
			ans[lower_bound(ans,ans+len,data[i])-ans]=data[i];
		}
	}
	cout << len << " " << ans[len] << endl;
	return 0;
}  

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		double dis[101][101];
		double *low=new double[n];
		double *MST=new double[n-1];
		double *x=new double[n];
		double *y=new double[n];
		bool *visited=new bool[n];
		int cnt=0;
		
		for(int i=0;i<n;i++)    //初始化 
		{
			visited[i]=0;
			low[i]=0;
			MST[i==n-1? n-2:i]=0;
		}
		memset(dis,0,sizeof(dis));
		
		for(int i=0;i<n;i++)
		{
			cin >> x[i] >> y[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
			}
		}
		
		visited[0]=1;
		for(int i=0;i<n;i++)
		low[i]=dis[0][i];
		
		double min=INT_MAX;
		int pos=0;
		
		for(int i=0;i<n-1;i++) //prim 已经更新了下标为0的点 故这里减一 
		{
			min=INT_MAX;
			for(int j=0;j<n;j++)
			{
				if(visited[j]==0 && low[j]<min)
				{
					min=low[j];
					pos=j;
				}
			}
			visited[pos]=1;
			MST[cnt++]=min;
			
			for(int j=0;j<n;j++)  //更新low 
			{
				if(visited[j]==0 && low[j]> dis[pos][j] && dis[pos][j]!=0)
				{
					low[j]=dis[pos][j];
				}
			}
		} 
		sort(MST,MST+cnt,greater<double>()); //升序排列 MST的各边长度 
		cout << fixed << setprecision(2) << MST[k-2] << endl; //第k-1大的边 
	}
	return 0; 
}

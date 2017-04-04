#include <bits/stdc++.h>  
using namespace std;  

struct point{    
    int x,y;  
};
  
double dis(point a,point b)
{      
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );  
}  

double _dis[21][21],dp[21][100000];  

int main()  
{  
    int T,n;
    cin >> T;
    point p[25];  
    while(T--)  
    {
	memset(_dis,0,sizeof(_dis));
	memset(dp,0,sizeof(dp));
	cin >> n;   
        int cnt=1;  
        for(int i=2;i<n;i++) 
		cnt<<=1;       
          
        for(int i=0;i<n;i++)                
        cin >> p[i].x >> p[i].y;
          
        for(int i=0;i<n;i++)              
            for(int j=0;j<n;j++)  
                _dis[i][j]=dis(p[i],p[j]);  
                  
        for(int i=0;i<n;i++)              
            for(int j=0;j<cnt;j++)  
                dp[i][j]=numeric_limits<double>::max();  
          
        for(int i=0;i<n;i++)                
        dp[i][0]=_dis[0][i];
		                 
        for(int i=1;i<cnt;i++)                 
            for(int j=1;j<n-1;j++)  
            {  
                for(int k=1;k<n-1;k++)  
                {  
                    if((1<<k-1)&i)          //binary number i is equal to 1 in the kth point
                    dp[j][i]=min(dp[j][i],_dis[j][k]+dp[k][i-(1<<k-1)]);   //dp[i]{V}=min( dp[i]{V},dist[i][j]+dp[j]{V-{j}} )　
                }  
            }  
        double ans=numeric_limits<double>::max();  
        for(int i=1;i<n;i++)  
        ans=min(ans,dp[i][cnt-1]+_dis[i][n-1]);  
          
        printf("%.2lf\n",ans);  
    }  
    return 0;  
}  

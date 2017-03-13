#include <bits/stdc++.h>
using namespace std;


int main()
{
	string a,b;
	while(cin >> a >> b)
	{
		int al=a.length(),bl=b.length();
		
		int **data=new int*[max(al,bl)+1];
		for(int i=0;i<max(al,bl)+1;i++)
		data[i]=new int[max(al,bl)+1]; 
		
		for(int i=0;i<=al;i++)
		{
			for(int j=0;j<=bl;j++)
			{
				if(i==0 || j==0) data[i][j]=0;
				else if(a[i-1]==b[j-1]) data[i][j]=data[i-1][j-1]+1;
				else data[i][j]=max(data[i-1][j],data[i][j-1]);
			}
			
		}
		cout << data[al][bl] << endl;
			
		
		
	}
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int L,P,V;
	int n=0;
	while(cin >> L >> P >> V)
	{
		if(L==0 && P==0 && V==0)
		break;
		
		n++;
		cout << "Case "<< n << ": ";
		if(P!=0)
		{
			int times=V/P;
			int res=V%P;
			cout << times*L+min(res,L) << endl;
		}
		else
		cout << 0 << endl;
	}
	return 0;
}

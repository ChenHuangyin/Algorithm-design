#include<bits/stdc++.h>
using namespace std;

int main()
{
	int countA,countB,maxA,maxB;
	cin >> countA >> countB >> maxA >> maxB;
	int ans1,ans2;
	int A=0,B=0;
	
	if(maxA!=0)
	{
		A=countA/maxA;
		if(countA%maxA!=0)
		A++;
	}
	else
	{
		ans1=maxB<countB?maxB:countB;
		cout << ans1 << endl;
		goto end;
	}
	if(countB<(A-1))
	{
		
		ans1=maxA*(countB+1)+countB;
		
	}
	else if(countB>=(A-1) && countB<=(maxB)*(A+1))
	{
		ans1=countA+countB;		
	}
	else
	{
		ans1=countA+maxB*(A+1);
	}
	//
	//
	//
	//
	if(maxB!=0)
	{
		B=countB/maxB;
		if(countB%maxB!=0)
		B++;
	}
	else
	{
		ans2=maxA<countA?maxA:countA;
		cout << ans2 << endl;
		goto end;
	}
	if(countA<(B-1))
	{
		ans2=maxB*(countA+1)+countA;
	}
	else if(countA>=(B-1) && countA<=(maxA)*(B+1))
	{
		ans2=countA+countB;		
	}
	else
	{
		ans2=countB+maxA*(B+1);
	}
	cout << max(ans1,ans2) << endl;
	
	end:
	return 0;
}

#include <iostream>
using namespace std;

int fibon[101];

void init()
{
	fibon[0]=0;
	fibon[1]=1;
	for(int i=2;i<41;i++)
	{
		fibon[i]=fibon[i-1]+fibon[i-2];
	}
}

int fib_Re(int n)
{
	if(n==0) return 0;
	else if(n==1) return 1;
	else return fib_Re(n-1)+fib_Re(n-2);
}

int fib(int n)
{
	return fibon[n];
}



int main()
{
	init();
	int n;
	while(cin >> n)
	cout << fib(n) << endl;
	return 0;
}

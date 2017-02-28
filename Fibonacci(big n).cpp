//CodeVs 1732 FibonacciÊıÁĞ 2

#include <iostream>
using namespace std;
#define N 1000000007 //mod

class Matrix{
	private:
		long long a,b,c,d;
	public:
		Matrix(long long a,long long b,long long c,long long d):a(a),b(b),c(c),d(d){}
		Matrix operator *(Matrix A) const
		{
			long long a1=(a*A.a+b*A.c)%N;
			long long b1=(a*A.b+b*A.d)%N;
			long long c1=(c*A.a+d*A.c)%N;
			long long d1=(c*A.b+d*A.d)%N;
			return Matrix(a1,b1,c1,d1);
		}
		long long ans(){
			return a;
		}
}; 

long long fib(long long n)
{
	if(n==0)
	return 0;

	Matrix base(1,1,1,0);
	Matrix data(1,0,0,1);
	n--;
	while(n)
	{
		if(n%2==1)
		{
			data=data*base;
		}
		base=base*base;
		n/=2;
	}
	return data.ans();
}

int main()
{
	long long n;
	while(cin >> n)
	cout << fib(n) << endl;
}

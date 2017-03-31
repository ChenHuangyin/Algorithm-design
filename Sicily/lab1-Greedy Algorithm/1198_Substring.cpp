#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a,string b)
{
	return a+b < b+a;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string *a=new string [n];
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		sort(a,a+n,cmp);
		string ans="";
		for(int i=0;i<n;i++)
		{
			cout << a[i] ;
		}
		cout << endl;
		delete []a;
	}
}

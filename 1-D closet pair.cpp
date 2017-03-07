#include <bits/stdc++.h>
using namespace std;

void quicksort(double *data,int left,int right)
{
	int i=left;
	int j=right;
	if(left>right)
	return;
	double temp=data[left];
	while(i<j)
	{
		while(data[j]>=temp && i<j)
		j--;
		while(data[i]<=temp && i<j)
		i++;
		
		if(i<j)
		swap(data[i],data[j]);
	}
	swap(data[left],data[i]);
	quicksort(data,left,i-1);
	quicksort(data,i+1,right);
}

double solve(double *data,int n)
{
	double min=numeric_limits<double>::max();
	for(int i=1;i<n;i++)
	{
		if(data[i]-data[i-1]-min < 0.000001)
		min=data[i]-data[i-1];
	}
	return min;
}

int main()
{
	int n;
	while(cin >> n)
	{
		double *data=new double [n];
		for(int i=0;i<n;i++)
		cin >> data[i];
		
		quicksort(data,0,n-1);
		cout << fixed << setprecision(6) << solve(data,n) << endl;
	}
}

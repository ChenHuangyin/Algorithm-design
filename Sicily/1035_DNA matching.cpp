#include <bits/stdc++.h>
using namespace std;

string get_pair(string s)
{
	string re="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		re+='T';
		else if(s[i]=='T')
		re+='A';
		else if(s[i]=='C')
		re+='G';
		else if(s[i]=='G')
		re+='C';
	}
	return re;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		map<string,int> data;
		cin >> n;
		int ans=0;
		string str;
		for(int i=0;i<n;i++)
		{
			cin >> str;
			if(data.find(str)==data.end())
			{
				data[str]=1;
			}
			else if(data.find(str)!=data.end())
			{
				data[str]=data[str]+1;
			}
			
			if(data.find(get_pair(str))!=data.end() && data[get_pair(str)]>=1)
			{
				ans++;
				data[str]=data[str]-1;
				data[get_pair(str)]=data[get_pair(str)]-1;
			}
		}
		cout << ans << endl;
		data.clear();
	}
	return 0;
}

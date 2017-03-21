#include<bits/stdc++.h>
using namespace std;

bool cmp(char a,char b)
{
	return a>b;
}

int main()
{
	int L;
	cin >> L;
	char s[101];
	while(L--)
	{
		memset(s,0,sizeof(s));
		cin >> s;
		int len=strlen(s);
			
		for(int i=0;i<len;i++)
		{
			int start=i;
			while(i<len && s[i]!='0')
			i++;
			int end=i;
			sort(s+start,s+end,cmp);
		}
		cout << s << endl;
	}
}

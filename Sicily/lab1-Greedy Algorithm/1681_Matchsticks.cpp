#include<iostream>
#include<string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int min[] = {0, 0, 1, 7, 4, 2, 6};
		int i;
    	if (n<7) 
		{
			cout << min[n];
        } 
		else 
		{
        	if (n%7==0)
        	{
        		for (i = 0; i<n/7; i++)
            	cout << "8";
        	}
            if (n%7==1) 
			{
            	cout << "10";
            	for (i = 0;i<n/7-1;i++)
                cout << "8";
        	}
        	if (n%7==2) 
			{
            	cout << "1";
            	for (i=0;i<n/7;i++)
                cout << "8";
        	}
        	if (n%7==3) 
			{
            	if (n==10)
                cout << "22";
            	else 
				{
                	cout << "200";
                	for (i=0;i<n/7-2;i++)
                    cout << "8";
            	}
        	}
        	if (n%7==4) 
			{
            	cout << "20";
            	for (i=0;i<n/7-1;i++)
                cout << "8";
        	}
        	if (n%7 ==5) 
			{
            	cout << "2";
            	for (i=0;i<n/7;i++)
                cout << "8";
        	}
        	if (n%7==6) 
			{
            	cout << "6";
            	for (i=0;i<n/7;i++)
                cout << "8";
        	}
		}
		string ans2="";
		int temp=n;
		while(1)
		{
			if(temp==0)
			break;
			if(temp==3)
			{
				ans2="7"+ans2;
				break;
			}
			temp-=2;
			ans2+="1";
		}
		cout << " " << ans2 << endl;
	}
	return 0;
}

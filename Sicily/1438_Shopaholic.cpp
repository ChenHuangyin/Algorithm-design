#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int *data=new int[n];
        for(int i=0;i<n;i++)
        {
            cin >> data[i];
        }
        sort(data,data+n,greater<int>());
        int ans=0;
        for(int i=2;i<n;i+=3)
        {
            if(i%3==2)
            ans+=data[i];
        }
        cout << ans << endl;
    }
}                                 

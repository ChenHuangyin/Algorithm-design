// Problem#: 1093
// Submission#: 5059138
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<bits/stdc++.h>
using namespace std;

struct low_bound{
    int least_w;
    int total_price;
};

int main()
{
    int w1,w2,w3,r1,r2,r3,r4;
    int cnt=1;
    while(cin >> w1 >> r1 >> w2 >> r2 >> w3 >> r3 >> r4)
    {
        cout << "Set number " << cnt++ << ":" << endl;
        
        low_bound data[3]={{w1+1,r2*(w1+1)},{w2+1,r3*(w2+1)},{w3+1,r4*(w3+1)}};
        int test;
        while(cin >> test)
        {
            if(test==0)
            break;
            
            int price=numeric_limits<int>::max();
            int weight=0;
            
            if(test<=w1)
            {
                weight=test;
                price=weight*r1;
            }
            else if(test>w1 && test<=w2)
            {
                weight=test;
                price=weight*r2;
            }
            else if(test>w2 && test<=w3)
            {
                weight=test;
                price=weight*r3;
            }
            else if(test>w3 && test<=1000)
            {
                weight=test;
                price=weight*r4;
            }
            
            for(int i=0;i<3;i++)
            {
                if(data[i].total_price<price && weight<data[i].least_w)
                {
                    price=data[i].total_price;
                    weight=data[i].least_w;
                }
            }
            cout << "Weight (" << test << ") has best price $"<< price << " (add "<< weight-test <<  " pounds)" << endl;
            
        }
        cout << endl;
    }
    return 0;
}                                 

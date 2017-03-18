#include <bits/stdc++.h>
using namespace std;

struct jew{
	long long w,p;
	jew():w(0),p(0){}
	jew(long long w1,long long p1):w(w1),p(p1){}
};

class cmp{
public:
    bool operator ()(const jew a,const jew b)const {
    		return a.p<b.p; //降序 
    }
};

bool cmp1(jew a,jew b){
	return a.w<b.w; 
}


int main()
{
	priority_queue<jew,vector<jew>,cmp> data;
	jew *je;
	long long *bag;

	long long N,K,M,V,C,w,p;
	int tindex=0;
	long long ans=0;
	cin >> N >> K;
	je=new jew[N];
	bag=new long long[K];
	
	for(long long i=0;i<N;i++)
	{
		cin >> M >> V;
		je[i]=jew(M,V);
	}
	sort(je,je+N,cmp1);
	
	for(long long i=0;i<K;i++)
	{
		cin >> bag[i];
	}
	sort(bag,bag+K);
	
	for(long long i=0;i<K;i++)
	{
		while(je[tindex].w<=bag[i] && tindex<N)  //判小于N很关键。。。 
		{
			data.push(je[tindex]);
			tindex++;
		}
		if(!data.empty())
		{
			ans+=data.top().p;
			data.pop();
		}
	}
	cout << ans << endl;
	return 0;
}

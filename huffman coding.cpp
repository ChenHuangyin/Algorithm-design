#include<bits/stdc++.h>
using namespace std;

struct node{
	int fc;
	char c;
	int depth;
	node():fc(0),c('*'),depth(0){}
	node(const node &a):fc(a.fc),c(a.c),depth(a.depth){}
	node(int f,char ch,int d):fc(f),c(ch),depth(d){}
};

struct huffman_tree{
	huffman_tree *left,*right;
	node data;
	huffman_tree():left(NULL),right(NULL),data(node()){}
};

struct cmp{
	bool operator()(huffman_tree *a,huffman_tree *b)
	{
		return a->data.fc>b->data.fc;
	}
};

void get_depth(huffman_tree *t,int n)
{
	if(t->left==NULL && t->right==NULL)
	{
		t->data.depth=n;
	}
	else
	{
		get_depth(t->left,n+1);
		get_depth(t->right,n+1);
	}
}

int solve(huffman_tree *t)
{
	int ans=0;
	stack<huffman_tree*> s;
	if(!t)
	return 0;
	
	while(!s.empty() || t)
	{
		
		while(t)
		{
			s.push(t);
			if(t->data.c!='*')
			ans+=(t->data.depth*t->data.fc);
			t=t->left;
			
		}
		t=s.top();
		s.pop();
		t=t->right;
	}
	return ans;
}

int main()
{
	priority_queue<huffman_tree*,vector<huffman_tree*>,cmp> q;
	int n,f;
	cin >> n;
	char c;
	while(n--)
	{
		cin >> c >> f;
		node a(f,c,0);
		huffman_tree* temp=new huffman_tree;
		temp->data=a;
		q.push(temp);
	}
	
	while(q.size()>1)
	{
		huffman_tree *temp1=q.top();
		q.pop();
		huffman_tree *temp2=q.top();
		q.pop();
		
		huffman_tree *res=new huffman_tree;
		res->data.c='*';
		res->data.fc=temp1->data.fc+temp2->data.fc;
		res->left=temp1;
		res->right=temp2;
		q.push(res);
	}
	huffman_tree *ans=q.top();
	get_depth(ans,0);
	
	int ans_=solve(ans);
	cout << ans_ << endl;
	
}

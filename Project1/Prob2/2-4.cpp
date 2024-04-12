#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include <utility>
using namespace std;
string st,ed;
typedef pair<int,string> PIS;
bool check(string str)
{
	int cnt=0;
	for(int i=0;i<8;i++)
		for(int j=i;j<8;j++)
			if(str[i]>str[j]) cnt++;
	if(cnt&1) return false;
	return true;	
} 

int f(string str)
{
	int sum=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='x') continue;
		int j=str[i]-'1';
		int x=i/3,y=i%3;
		int a=j/3,b=j%3;
		sum+=abs(x-a)+abs(y-b);
	}
	return sum;
}
string bfs(string st)
{
	priority_queue<PIS,vector<PIS>,greater<PIS> > heap;
	map<string,int> dist;
	dist[st]=0;
	map<string,pair<char,string> >pre;
	heap.push(make_pair(f(st), st));
	int dx[]={-1,0,1,0};
	int dy[]={0,1,0,-1};
	string d="urdl";
	while(heap.size())
	{

		PIS t=heap.top();heap.pop();

		string s=t.second;
		if(s==ed) break;
		int x,y;
		for(int i=0;i<9;i++)
			if(s[i]=='x')
			{
				
				x=i/3,y=i%3;
				break;
			}
		string source=s;
		for(int i=0;i<4;i++)
		{
			int a=x+dx[i],b=y+dy[i];
			if(a<0||a>=3||b<0||b>=3) continue;
			s=source;
			swap(s[3*x+y],s[3*a+b]);
			if(!dist.count(s)||dist[s]>dist[source]+1)
			{
				dist[s]=dist[source]+1;
				pre[s]=make_pair(d[i],source);
				heap.push(make_pair(dist[s] + f(s), s));
			}
		}
	}
	string res="";
	while(ed!=st)
	{
		res+=pre[ed].first;
		ed=pre[ed].second;
	}
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
	char c;
	string sq;
	for(int i = 0; i < 9; i++)
	{

        cin>>c;
		st+=c;
		if(c!='x') sq+=c;
	}

	ed="12345678x";
	if(!check(sq))
		cout<<"unsolvable"<<endl;
	else 
		cout<<bfs(st)<<endl;
}
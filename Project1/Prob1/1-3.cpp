#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
 
struct edge{
	int to;
	int cost;
};
typedef pair<int, int> P;  //first is shortest distance, second is the number of vertex
int n, m;
const int MAX_V = 1.5e5 + 10;
const int INF = 0x3f3f3f3f;
vector<edge> G[MAX_V];
int d[MAX_V];	// shortest distance
 
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > que;  // greater<P> is from small to large, less<P> is reverse;
	fill(d, d + MAX_V, INF);
	d[s] = 0;
	que.push(P(0, s));
	
	while(!que.empty())
	{
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first)	continue;
		for(int i = 0; i < G[v].size(); i ++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	if(d[n] >= INF)	cout<< -1<<endl;
	else	cout<<d[n]<<endl;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
 
	cin >> n >> m;
		
	for(int i = 1;i <= n;i ++){
		G[i].clear();
	}
	
	
	for(int i = 1; i <= m; i ++){
		int x, y, z;
		cin >> x >> y >> z;
		edge temp;
		temp.to = y;
		temp.cost = z;
 
		G[x].push_back(temp);
		
	}
	
	dijkstra(1);
	return 0;
}
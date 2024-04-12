#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
 
using namespace std;
bool check(string str)
{
	int cnt=0;
	for(int i=0;i<8;i++)
		for(int j=i;j<8;j++)
			if(str[i]>str[j]) cnt++;
	if(cnt&1) return false;
	return true;	
} 

int bfs(string start)
{

    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;
    
    q.push(start);
    d[start] = 0;

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        int distance = d[t];
        if(t == end) return distance;

        int k = t.find('x');
        int x = k / 3, y = k % 3;
    
        for(int i = 0; i < 4; i++)
        {
       
            int a = x + dx[i], b = y + dy[i];
     
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
          
                swap(t[k], t[a * 3 + b]);
            
                if(!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
         
                swap(t[k], t[a * 3 + b]);
            }
        }
    }

    return -1;
}
int main()
{
    string st;
    char c;
	string sq;
   	for(int i = 0; i < 9; i++)
	{

        cin>>c;
		st+=c;
		if(c!='x') sq+=c;
	}
    
    if(!check(sq))
		cout<<"unsolvable"<<endl;
	else 
		cout<<bfs(st)<<endl;
    
    return 0;
}
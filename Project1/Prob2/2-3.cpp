#include <bits/stdc++.h>
#include <list>
#include <utility>

using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

map<string, int> dis;

void check(string s)
{
    if (s.length() != 9)
    {
        printf("-1\n");
        exit(0);
    }
    bool yes[9] = {0};
    for (auto x: s)
    {
        if (x < '9' && x >= '0')yes[x - '0'] = 1;
        if (x == 'x')yes[0] = 1;
    }
    for (int i = 0; i <= 8; i++)
    {
        if (!yes[i])
        {
            printf("-1\n");
            exit(0);
        }
    }
    int nxs = 0;
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 9; j++)
        {
            char a = s[i], b = s[j];
            if (a == 'x' || b == 'x')continue;
            if (a > b)nxs++;
        }
    if (nxs % 2 == 1)
    {
        printf("-1\n");
        exit(0);
    }
}

void solve()
{
    string s = "";

    for (int i = 1; i <= 9; i++)
    {
        string tmp;
        cin >> tmp;
        s = s + tmp;
    }

    check(s);

    pii op[5] = {make_pair(0, 0),
                 make_pair(0, 1),
                 make_pair(1, 0),
                 make_pair(0, -1),
                 make_pair(-1, 0)};

    priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > q;

    q.push(make_pair(0, s));
    while (!q.empty())
    {
        auto now = q.top();
        q.pop();
        if (now.second == "12345678x")
        {
            cout<<now.first<<endl;
            exit(0);
        }

        if(dis.count(now.second))
            if(dis[now.second]<now.first)continue;
   

        dis[now.second]=now.first;

        for (int i = 0; i < 9; i++)
        {
            if (now.second[i] == 'x')
            {
                string tmp;
                int x, y;
                for (int j = 1; j <= 4; j++)
                {
                    x = i / 3 + op[j].first;
                    y = i % 3 + op[j].second;
                    if (x <= 2 && x >= 0 && y <= 2 && y >= 0)
                    {
                        tmp = now.second;
                        swap(tmp[i], tmp[x * 3 + y]);
                        if (!dis.count(tmp)||dis[tmp]>now.first+1)
                        {
                            q.push(make_pair(1 + now.first, tmp));
            
                        }
                    }
                }
            }
        }
    }
    cout<<"-1"<<endl;
    
}

signed main()
{

    solve();

    return 0;
}
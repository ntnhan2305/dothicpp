#include <bits/stdc++.h>
using namespace std;
const long int MAX = 10000;
int e, v, t = 0;
vector<long int> g[MAX];
stack<long int> st;
vector<long int> ct[MAX];
bool check[MAX];
void in()
{
    long int a, b;
    ifstream f("INPUT.INP");
    f >> v >> e;
    for(int i = 1; i <= e; i++)
    {
        f >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    f.close();
}
void BFS(int i)
{
    st.push(i);
    while(!st.empty())
    {
        int tam = st.top();
        st.pop();
        for(int j = 0; j < g[tam].size(); j++)
        {
            if(!check[g[tam].at(j)])
            {
                ct[t].push_back(g[tam].at(j));
                check[g[tam].at(j)] = true;
                st.push(g[tam].at(j));
            }
        }
    }
}
int main()
{
    in();
    for(int i = 1; i <= v; i++)
    {
        if(!check[i])
        {
            t++;
            check[i] = true;
            ct[t].push_back(i);
            BFS(i);
        }
    }
    cout << t << endl;
    for(int i = 1; i <= t; i++)
    {
        for(int j : ct[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const long int MAX = 1000;
int v, e, n = 0;
bool check[MAX];
vector<long int> st, st2[MAX];
vector<long int> g[MAX];
void in()
{
    int a, b;
    ifstream f("INPUT.INP");
    f >> v >> e;
    for(int i = 1 ; i <= e; i++)
    {
        f >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    f.close();
}
void inct()
{
    vector<long int> tam;
    tam = st;
    reverse(tam.begin(), tam.end());
    for(int i = 1; i <= n; i++)
    {
        if(st2[i] == tam)
            return;
    }
    n++;
    st2[n] = st;
}
void DFS(int i, int start)
{
    check[i] = true;
    st.push_back(i);
    for(int j : g[i])
    {
        if(!check[j])
        {
            DFS(j, start);
        }
        else if(st.size() > 2 && j == start)
        {
            st.push_back(j);
            inct();
            st.pop_back();
        }
    }
    check[i] = false;
    st.pop_back();
}
int main()
{
    in();
    for(int i = 1; i <= v; i++)
    {
        if(!check[i])
        {
            DFS(i, i);
            check[i] = true;
        }
    }
    cout << "Có " << n << " chu trình con" << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(int j : st2[i])
        {
            cout << j << "->";
        }
        cout << endl;
    }
}
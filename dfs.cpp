#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int v, e, k = 0;
vector<int> g[MAX], ct[MAX];
bool check[MAX];
void in()
{
	int a, b;
	ifstream f("INPUT.INP");
	f >> v >> e;
	for(int i = 1; i <= e; i++)
	{
		f  >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	f.close();
}
void DFS(int u)
{
	check[u] = true;
	ct[k].push_back(u);
	for(int i = 0; i < g[u].size(); i++)
	{
		if(!check[g[u].at(i)])
		{
			DFS(g[u].at(i));
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
			k++;
			DFS(i);
		}
	}
	cout << k << endl;
	for(int i = 1; i <= k; i++)
	{
		cout << i << ": ";
		for(int j : ct[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
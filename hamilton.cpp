#include <bits/stdc++.h>
using namespace std;
const long int MAX = 10000;
int v, e;
bool check[MAX];
vector<long int> g[MAX];
long int a[MAX];
void in()
{
	int a, b;
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
bool find(int x, int d)
{
	for(int t = 0; t < g[x].size(); t++)
	{
		if(g[x].at(t) == d)
		{
			return true;
		} 
		else if(g[x].at(t) > d)
		{
			return false;
		}
	}
	return false;
}
void inch()
{
	for(int u = 1; u <= v+1; u++)
	{
		cout << a[u] << "->";
	}
	cout << endl;
}
void Hamilton(int i)
{
	for(int j = 1; j <= v; j++)
	{
		if(!check[j] && find(a[i-1], j))
		{
			a[i] = j;
			check[j] = true;
			if(i == v)
			{
				if(find(a[i], a[v+1]))
					inch();
			}
			else
				Hamilton(i+1);
			a[i] = 0;
			check[j] = false;
		}
	}
}
int main()
{
	in();
	check[1] = true;
	a[1] = 1;
	a[v+1] = 1;
	Hamilton(2);
}
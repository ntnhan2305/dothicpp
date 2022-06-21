#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
long int inf = 999999999;
vector<pair<int,int> > g[MAX];
int e, v, d[MAX], Trace[MAX], dcd;
bool check[MAX];
void in()
{
	int a, b, ts;
	ifstream f("INPUT.INP");
	f >> v >> e;
	dcd = v;
	for(int i = 1; i <= e; i++)
	{
		f >> a >> b >> ts;
		g[a].push_back({b, ts});
		g[b].push_back({a, ts});
	}
	f.close();
}
void init()
{
	for(int i = 1; i <= v; i++)
	{
		d[i] = inf;
		Trace[i] = -1;
		check[i] = false;
	}
}
int MINU()
{
	long int MIN = inf, u = -1;
	for(int i = 1; i <= v; i++)
	{
		if(!check[i] && d[i] < MIN)
		{
			MIN = d[i];
			u = i;
		}
	}
	return u;
}
void dijkstra(int u)
{
	d[u] = 0;
	while(dcd > 0)
	{
		int s = MINU();
		if(s == -1)
			break;
		dcd--;
		check[s] = true;
		for(int j = 0; j < g[s].size(); j++)
		{
			if(d[g[s].at(j).first] > d[s] + g[s].at(j).second)
			{
				d[g[s].at(j).first] = d[s] + g[s].at(j).second;
				Trace[g[s].at(j).first] = s;
			}
		}
	}
}
int main()
{
	in();
	init();
	dijkstra(1);
	cout << "MIN(1 -> 7): " << d[v] << endl;
	vector<int> tam;
	int i = v;
	while(Trace[i] != -1)
	{
		tam.push_back(i);
		i = Trace[i];
	}
	tam.push_back(1);
	for(int i = tam.size() - 1; i >= 0; i--)
	{
		cout << tam[i] << "->";
	}
}
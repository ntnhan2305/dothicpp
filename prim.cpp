#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
long int inf = 999999999;
vector<pair<int,int> > g[MAX];
int e, v, sc = 0, S;
bool check[MAX];
struct EG
{
	int a, b, ts;
};
EG tam;
EG dt[MAX];
void in()
{
	int a, b, ts;
	ifstream f("INPUT.INP");
	f >> v >> e;
	for(int i = 1; i <= e; i++)
	{
		f >> a >> b >> ts;
		g[a].push_back({b, ts});
		g[b].push_back({a, ts});
	}
	f.close();
}
void prim(int u)
{
	check[u] = true;
	while(sc < v - 1)
	{
		long int MIN = inf;
		for(int i = 1; i <= v; i++)
		{
			if(check[i])
			{
				for(int j = 0; j < g[i].size(); j++)
				{
					if(!check[g[i].at(j).first] && g[i].at(j).second < MIN)
					{
						MIN = g[i].at(j).second;
						tam.a = i;
						tam.b = g[i].at(j).first;
						tam.ts = g[i].at(j).second;
					}
				}
			}
		}
		dt[sc+1] = tam;
		sc++;
		S += tam.ts;
		check[tam.b] = true;
	}
}
int main()
{
	in();
	prim(1);
	cout << S << endl;
	for(int i = 1; i <= sc; i++)
	{
		cout << dt[i].a << "-" << dt[i].b << ": " << dt[i].ts << endl;
	}
}
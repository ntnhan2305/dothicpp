#include <bits/stdc++.h>
using namespace std;
const long int MAX = 10000;
int e, v;
vector<int> g[MAX], EL;
stack<int> st;
bool check[MAX][MAX];
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
int Empty(int x)
{
	for(int j = 0; j < g[x].size(); j++)
	{
		if(!check[x][g[x].at(j)])
			return g[x].at(j);
	}
	return -1;
}
void euler(int u)
{
	st.push(u);
	while(!st.empty())
	{
		int tam = st.top();
		int beg = Empty(tam);
		if(beg != -1)
		{
			st.push(beg);
			check[tam][beg] = true;
			check[beg][tam] = true;
		}
		else
		{
			EL.push_back(st.top());
			st.pop();
		}
	}
}
int main()
{
	in();
	euler(1);
	for(int i = EL.size() - 1; i >= 0; i--)
	{
		
		cout << EL.at(i) << " ";
	}
}
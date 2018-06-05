//Tarjan

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

std::vector<int > gra[maxn];
bool vis[maxn];

struct Tarjan{

	int dfno[maxn];
	int lowest[maxn];
	int parent[maxn];
	
	Tarjan(){
		//cut-points.clear();
	}

};

void dfs_tarjan(int root, int &no){
	dfno[root] = no++;
	lowest[root] = dfno[root];

	for(int i=0; i<gra[root].size(); i++){

		int son = gra[root][i];
		if(vis[son] && son != parent[son]){
			lowest[root] = min(lowest[root], lowest[son]);
		}
		else{
			parent[son] = root;
			dfs_tarjan(son);
		}
	}

}

void Init(){
	gra.clear();
	memset(vis, false, sizeof(vis));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Init();

	//scan the graph 

	dfs_tarjan(0, 0);

	return 0;
}

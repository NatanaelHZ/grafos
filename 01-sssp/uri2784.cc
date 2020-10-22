#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXN 1001
#define INF 1001

typedef pair<int, int> ii;
 
int dist[MAXN], n, m;
vector<ii> adjList[MAXN];
 
int dijkstra(int s, int t, int n, int dist[]) {
	for(int i = 1; i <= n; i++) dist[i] = INF;
	set<ii> pq;
	dist[s] = 0;
	pq.insert(ii(0, s));
	while(!pq.empty()) {
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		for(int i=0; i<(int)adjList[u].size(); i++) {
			int v = adjList[u][i].second;
			int w = adjList[u][i].first;
			if (dist[v] > dist[u] + w) {
				pq.erase(ii(dist[v], v));
				dist[v] = dist[u] + w;
				pq.insert(ii(dist[v], v));
			}
		}
	}
	return dist[t];
}
 
int main() {
	int u, v, w, s;
	int small, big, result, aux; 
  	big = -1;
  	small = INF;

	cin >> n >> m;

	for(int i=1; i<=n; i++) adjList[i].clear();

	for (int i=0; i<m; i++) {
		cin >> u >> v >> w;

		adjList[u].push_back(ii(w, v));
		adjList[v].push_back(ii(w, u));
	}
	
	cin >> s;

	for (int i = 1; i <= n; i++) {
		if (i != s) {
			aux = dijkstra(s, i, n, dist);
			
			if (aux >= big) big = aux;
			if (aux <= small) small = aux;
		}
		
	}
  
  	cout << (big - small);

	return 0;
}
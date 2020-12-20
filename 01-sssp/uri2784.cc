#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INFTO 100000

typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
vector<vii> adjList;
vector<int> dist;

void dijkstra(int s) {
    dist.assign(n, INFTO);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i < (int)adjList[u].size(); i++){
            int v = adjList[u][i].first, w = adjList[u][i].second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int i, u, v, w, s;
    int small, big;

    whil e(scanf("%d %d", &n, &m) != EOF) {
        adjList.assign(n, vii());
        for(i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        scanf("%d", &s);
        dijkstra(--s);

        big = 0;
        small = INFTO;
        for (u = 0; u < n; u++) {
            if(dist[u] != INFTO)
                big = max(dist[u], big);

            if(dist[u] != 0)
                small = min(dist[u], small);
        }

        printf("%d\n", big - small);
    }

    return 0;
}
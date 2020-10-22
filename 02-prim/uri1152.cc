#include <iostream>
#include <vector>
#include <set>
using namespace std;

using link = pair<int,int>;

int N, M;

int64_t prim(vector<vector<link>> adj) {
  vector<bool> visited(N+1, false);
  set<link> q;

  int64_t soma = 0;

  q.insert({0, 1});

  while(!q.empty()) {
    auto [w, u] = *q.begin();
    q.erase(q.begin());

    if(!visited[u]) {
      visited[u] = true;
      soma += w;

      for (auto [v, wv] : adj[u]) {
        q.insert({wv, v});
      }
    }
  }
  return soma;

}

int main() {
  while ((cin >> N >> M) && (N != 0 && M != 0)) {
    int soma = 0;
    vector<vector<link>> adj;
    adj.resize(N+1);

    for(int i = 0; i < M; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});

      soma += w;
    }

    cout << (soma - prim(adj)) << '\n';
  }

  return 0;
}
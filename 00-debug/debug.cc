#include <iostream>
#include <vector>

using namespace std;

struct AdjList {

  vector<vector<pair<int,int>>> adjs;


  AdjList(int n):adjs(n) { }

  void add_edge(int u, int v, int w) {
    adjs[u].push_back({v, w});
  }

  void debug() {
    int total = adjs.size();

    cout << "Adj list: \n";
    cout << "[";
    for(int i = 1; i < total; ++i) {
      int comma = 1;
      int commas = adjs[i].size();

      cout << "["; 
      for(const auto& p : adjs[i]) {
        if (p.first)
          cout << p.first;

        if (comma < commas)
          cout << ", ";

        comma += 1;
      }

      cout << "]";

      if (i < (total - 1))
        cout << ", ";
    }
    cout << "]" << "\n\n";
  }

};

struct EdgeList {

  vector<pair<int, pair<int,int>>> edges;

  void add_edge(int u, int v, int w) {
    edges.push_back({w, {u, v}});
  }


  void debug() {
    int total = edges.size();

    cout << "Edje list: \n";
    cout << "[";
    for (size_t i = 0; i < edges.size(); i++) {
      const auto& all = edges[i];
      
      cout << "(" << all.second.first << ", " << all.second.second << ")";

      if (i < (total - 1))
        cout << ", ";
    }

    cout << "]";
    cout << "\n\n";
    
  }

};


struct AdjMatrix {

  vector<vector<bool>> mat;
  vector<vector<int>> weights;

  AdjMatrix(int n, int m): 
    mat(n, vector<bool>(m, false)),
    weights(n, vector<int>(m, 0))
    {}

  void add_edge(int u, int v, int w) {
    mat[u][v] = true;
    weights[u][v] = w;
  }

  void debug() {
    int total = mat.size();
    cout << "Adj Matrix:\n";
    cout << "[";
    for (size_t i = 0; i < total; i++)
    {
      int comma = 1;
      int commas = mat[i].size();

      cout << "[";
      for (size_t n = 0; n < mat[i].size(); n++)
      {
        if (mat[i][n] == 1)
         cout << "True";
        else cout << "False";

        if (comma < commas)
          cout << ", ";

        comma += 1;
      }
      cout << "]";

      if (i < (total - 1))
        cout << ", \n";
    }

    cout << "]\n\n";
  }

};




int main() {
  AdjList g1(10);
  g1.add_edge(1, 2, 50);
  g1.add_edge(1, 3, 50);
  g1.add_edge(1, 4, 50);
  g1.add_edge(2, 4, 50);
  g1.add_edge(3, 5, 50);
  g1.debug();

  AdjMatrix g2(5, 5);
  g2.add_edge(1, 2, 50);
  g2.debug();

  EdgeList g3;
  g3.add_edge(1, 2, 50);
  g3.add_edge(3, 4, 55);
  g3.debug();

}
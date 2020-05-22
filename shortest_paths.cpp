#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
    int N=adj.size(), cur;
    distance[s]=0;
    unordered_set<int> relaxed;
    //先跑N轮， 看第N轮是否有距离更新
    for (int _=0; _<N; _++){
        for (int i=0; i<N; i++){
            if (distance[i] == std::numeric_limits<long long>::max()) continue;
            for (int j=0; j<adj[i].size(); j++){
                if (distance[adj[i][j]] > distance[i] + cost[i][j]){
                    distance[adj[i][j]] = distance[i] + cost[i][j];
                    if (_==N-1) relaxed.insert(adj[i][j]);
                }
            }
        }
    }
    for (int i=0; i<N; i++)
        if (distance[i] != std::numeric_limits<long long>::max())
            reachable[i]=1;
    if (relaxed.empty()) return;
    //如果第N轮有距离更新的话， 把这些点能reach的点都标记不可能有shortest path (-inf)
    for (auto& i:relaxed) {
        if (shortest[i]==0) continue;
        vector<int> st {i};
        while (!st.empty()){
            cur=st.front(); st.erase(st.begin());
            if (shortest[cur]==0) continue;
            shortest[cur]=0;
            for (int j=0; j<adj[cur].size(); j++) {
                if (shortest[adj[cur][j]]!=0)
                    st.push_back(adj[cur][j]);
            }
        }
        
    }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}

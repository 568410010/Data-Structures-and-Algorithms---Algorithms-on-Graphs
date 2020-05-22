#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using std::vector;
using std::pair;

vector<int> toposort(vector<vector<int> > adj) {
    int N=adj.size(), cur;
    vector<int> ans, st;
    vector<vector<int> > parent(N);
    for (int i=0; i<N; i++){
        for (int& j:adj[i]){
            parent[j].push_back(i);
        }
        if (adj[i].empty()) st.push_back(i);
    }
    while (!st.empty()){
        cur=st.back(); st.pop_back();
        ans.push_back(cur);
        for (int& nxt:parent[cur]){
            adj[nxt].erase(remove(adj[nxt].begin(), adj[nxt].end(), cur));
            if (adj[nxt].empty()) st.push_back(nxt);
        }
    }
    reverse(ans.begin(), ans.end()); 
    return ans;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}

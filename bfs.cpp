#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
    vector<int> layer {s}, nxtlayer;
    vector<bool> visited(adj.size());
    for (int i=0; !layer.empty(); i++){
        for (int& j:layer){
            for (int k:adj[j]){
                if (visited[k]) continue;
                if (k==t) return i+1;
                visited[k]=true;
                nxtlayer.push_back(k);
            }
        }
        layer=nxtlayer;
        nxtlayer.clear();
    }
    return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
    s--; t--;
  std::cout << distance(adj, s, t);
}

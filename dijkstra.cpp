#include <iostream>
#include <vector>
#include <queue>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <cstdint>
#include <limits>
using namespace std;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    typedef pair<int, int> pi;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int N=adj.size();
    vector<int> distances(N, 2147483647);
    vector<bool> used(N, false);
    distances[s]=0;
    while (!used[t]){
        for (int i=0; i<N; i++)
            if (distances[i]!=2147483647 && !used[i])
                pq.push(make_pair(distances[i], i));
        if (pq.empty()) return -1;
        pi top=pq.top();
        pq = priority_queue<pi, vector<pi>, greater<pi>> ();
        int dis=top.first, idx=top.second;
        //cout<<"idx "<<idx<<endl;
        for (int i=0; i<adj[idx].size(); i++)
            distances[adj[idx][i]]=\
            min(distances[adj[idx][i]], dis+cost[idx][i]);
        used[idx]=true;
    }
    return distances[t]==2147483647? -1:distances[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}

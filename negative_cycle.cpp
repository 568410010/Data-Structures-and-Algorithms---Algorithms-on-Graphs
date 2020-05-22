#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
    int N=adj.size(), cur;
    vector<int> distances(N, 0), disconn, st;
    //dfs: find all connected parts
    for (int i=0; i<N; i++){
        if (distances[i]==2147483647) continue;
        disconn.push_back(i);
        st={i};
        while (!st.empty()){
            cur=st.front(); st.erase(st.begin());
            if (distances[cur]==2147483647) continue;
            distances[cur]=2147483647;
            for (int i=0; i<adj[cur].size(); i++){
                if (distances[adj[cur][i]]==2147483647)
                    st.push_back(adj[cur][i]);
            }
        }
    }
    
    for (int& i:disconn) distances[i]=0;
    bool relaxed;
    for (int _=0; _<N; _++){
        relaxed=false;
        for (int i=0; i<N; i++){
            for (int j=0; j<adj[i].size(); j++) {
                if ( distances[i]!=2147483647 \
                    && distances[adj[i][j]] > distances[i]+cost[i][j]){
                    
                    distances[adj[i][j]]=distances[i]+cost[i][j];
                    relaxed=true;
                }
            }
        }
    }
    //for (auto& d:distances) cout<<d<<" ";
    //cout<<endl;
    return relaxed;
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
  std::cout << negative_cycle(adj, cost);
}

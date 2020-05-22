#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
    int n=adj.size();
    vector<int> color(n, -1);
    for (int i=0; i<n; i++){
        if (color[i]!=-1) continue;
        color[i]=1;
        vector<int> connected{i}, nxt;
        
        while (!connected.empty()){
            for (int j:connected){
                for (int k:adj[j]){
                    if (color[k]!=-1){
                        
                        if ((color[k]+color[j])%2==0) return 0;
                        else continue;
                        //cout<<k<<" "<<j<<endl;
                    }
                    color[k]=color[j]+1;
                    nxt.push_back(k);
                    //for (auto& m:color) cout<<m<<" ";
                    //cout<<endl;
                }
                connected=nxt;
                nxt.clear();
                
            }
        }
        
    }
    
    return 1;
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
  std::cout << bipartite(adj);
}

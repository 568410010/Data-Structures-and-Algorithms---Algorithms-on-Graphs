#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using std::vector;
using std::pair;

void dfs(int i, vector<vector<int> > &adj, bitset<1000>& bset){
    //cout<<"dfs i "<<i<<endl;
    if (bset[i]) return;
    bset[i]=1;
    for (int& nb: adj[i]){
        if (bset[nb]) continue;
        dfs(nb, adj, bset);
    }
}
int number_of_components(vector<vector<int> > &adj) {
    int ans=0;
    bitset<1000> bset;
    for (int i=0; i<adj.size(); i++){
        if (bset[i]) continue;
        ans++;
        dfs(i, adj, bset);
    }
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
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}

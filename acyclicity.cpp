#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
using std::pair;

int acyclic(vector<vector<int> > &adj) {
    vector<int> st;
    int N=adj.size(), cur;
    vector<vector<int> > parent(N);
    
    for (int i=0; i<N; i++){
        for (int& child:adj[i])
            parent[child].push_back(i);
        if (adj[i].empty()) st.push_back(i);
        //cout<<"i "<<i<<" N "<<N<<endl;
    }
    while (!st.empty()){
        cur=st.back(); st.pop_back();
        N--;
        //cout<<"cur "<<cur<<endl;
        for (int& nxt:parent[cur]){
            adj[nxt].erase(remove(adj[nxt].begin(), adj[nxt].end(), cur));
            if (adj[nxt].empty()) {st.push_back(nxt);}
        }
            
    }
    //cout<<"N "<<N<<endl;
    return N==0? 0:1;
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
  std::cout << acyclic(adj);
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <memory.h>
using namespace std;
using std::vector;
using std::pair;

void dfs(int cur, int& order, vector<vector<int>>& parent, vector<int>& postorder, vector<bool>& visited){
    visited[cur]=true;
    for (int& nxt:parent[cur]){
        if (!visited[nxt])
            dfs(nxt, order, parent, postorder, visited);
    }
    postorder[cur]=order++;
}

int number_of_strongly_connected_components(vector<vector<int>>& child) {
    int ans=0, N=child.size(), order=0;
    vector<vector<int>> parent(N);
    for (int i=0; i<N; i++){
        for (int& j:child[i]){
            parent[j].push_back(i);
        }
    }
    vector<bool> visited(N), visited2(N);
    vector<int> postorder(N);
    for (int i=0; i<N; i++)
        if (!visited[i])
            dfs(i, order, parent, postorder, visited);
    vector<pair<int, int>> post;
    for (int i=0; i<N; i++){
        post.push_back(make_pair(postorder[i], i));
    }
    //for (int& i:postorder) cout<<i<<" ";
    //cout<<endl;
    sort(post.begin(), post.end());
    reverse(post.begin(), post.end());
    for (auto& p:post){
        if (!visited2[p.second]){
            ans++;
            dfs(p.second, order, child, postorder, visited2);
        }
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
  }
  std::cout << number_of_strongly_connected_components(adj);
}

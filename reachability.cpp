#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
using std::vector;
using std::pair;


int reach(vector<vector<int> > &adj, int x, int y) {
    unordered_set<int> visited;
    stack<int> st;
    st.push(x);
    int cur;
    while (!st.empty()){
        cur=st.top(); st.pop();
        for (int& nxt:adj[cur]){
            if (nxt==y) return 1;
            else if (visited.find(nxt)!=visited.end()) continue;
            visited.insert(nxt);
            st.push(nxt);
        }
    }
    return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}

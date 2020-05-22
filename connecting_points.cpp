#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
using std::vector;
struct Distance {
    double d;
    int p1, p2;
    Distance(double d, int p1, int p2) : d(d), p1(p1), p2(p2) {}
};

struct CompareDistance {
    bool operator() (Distance const& d1, Distance const& d2) {
        return d1.d>d2.d;}
};
int findparent(int i, vector<int>& parents) {
    while (parents[i]!=i){
        parents[i]=parents[parents[i]];
        i=parents[i];
    }
    return i;
}
double minimum_distance(vector<int> x, vector<int> y) {
    double ans=0, d;
    int N=x.size(), p1, p2, parent1, parent2;
    vector<int> parents(N), rank(N, 0);
    priority_queue<Distance, vector<Distance>, CompareDistance> distances;
    for (int i=0; i<N; i++){
        parents[i]=i;
        for (int j=i+1; j<N; j++){
        d=pow(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2), 0.5);
        distances.push(Distance(d, i, j));
        }
    }
    while (N>1) {
        d=distances.top().d; p1=distances.top().p1; p2=distances.top().p2;
        distances.pop();
        parent1=findparent(p1, parents); parent2=findparent(p2, parents);
        if (parent1==parent2) continue;
        N--;
        ans+=d;
        if (rank[parent1]<rank[parent2]) {
            parents[parent1]=parent2;
        } else {
            parents[parent2]=parent1;
            if (rank[parent1]==rank[parent2])
                rank[parent1]++;
        }
    }
    return ans;
}


int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
using std::vector;
using std::pair;

struct Distance {
public:
    double d;
    int p1, p2;
    Distance(double d, int p1, int p2) : d(d), p1(p1), p2(p2) {}
};
struct CompareDistance {
    bool operator() (Distance const& d1, Distance const& d2) {
        return d1.d>d2.d;
    }
};
int findparent(int i, vector<int>& parents) {
    while (i!=parents[i]) {
        parents[i]=parents[parents[i]];
        i=parents[i];
    }
    return i;
}

double clustering(vector<int> x, vector<int> y, int k) {
    double ans=-1, d;
    int N=x.size(), groups=x.size(), p1, p2, parent1, parent2;
    priority_queue<Distance, vector<Distance>, CompareDistance> pq;
    vector<int> parents(N, 0), rank(N, 0);
    for (int i=0; i<N; i++) {
        parents[i]=i;
        for (int j=i+1; j<N; j++) {
            d=pow(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2), 0.5);
            pq.push(Distance(d, i, j));
        }
    }
    while (groups>k) {
        d=pq.top().d; p1=pq.top().p1; p2=pq.top().p2;
        //cout<<d<<" point1 "<<p1<<" point2 "<<p2<<endl;
        parent1=findparent(p1, parents); parent2=findparent(p2, parents);
        pq.pop();
        if (parent1==parent2) continue;
        if (rank[parent1]<rank[parent2]) {
            parents[parent1]=parents[parent2];
        } else {
            parents[parent2]=parents[parent1];
            if (rank[parent2]==rank[parent1])
                rank[parent1]++;
        }
        groups--;
    }
    while (true) {
        d=pq.top().d; p1=pq.top().p1; p2=pq.top().p2;
        parent1=findparent(p1, parents); parent2=findparent(p2, parents);
        pq.pop();
        if (parent1!=parent2) return d;
    }
    return ans;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}

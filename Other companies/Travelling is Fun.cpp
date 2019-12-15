// Travelling is Fun

/*
Flipkart IIT Kanpur 2018

https://www.hackerrank.com/contests/hack-it-to-win-it-paypal/challenges/q4-traveling-is-fun
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
    vector<int> par, sz;
    dsu(int n): par(n), sz(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int root(int a) {
        if (a == par[a]) return a;
        return par[a] = root(par[a]);
    }
    void merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

vector<int> findReachable(int n, int g, vector<int> from, vector<int> to) {
    dsu d(n);
    for (int k = g + 1; k <= n; k++) {
        for (int x = 2 * k; x <= n; x += k) {
            d.merge(x - 1, x - k - 1);
        }
    }

    int m = from.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back(d.root(from[i] - 1) == d.root(to[i] - 1));
    }
    return ans;
}

signed main() {
    vector<int> from {10, 4, 3, 6};
    vector<int> to {3, 6, 2, 9};
    vector<int> reachable = findReachable(10, 1, from, to);
    for (int i = 0; i < 4; i++) {
        cout << "From " << from[i] << " to " << to[i] << ": ";
        cout << (reachable[i] ? "Possible" : "Not possible") << '\n';
    }
    return 0;
}






#include<bits/stdc++.h>
using namespace std;
int root(vector &v,int a)
{
	while(v[a]!=a)
	{
		a=v[a];
	}
return a;
}

int main()
{
	int n,g,q,ri,rj,a,b;
	cin>>n>>g>>q;
	vector v(n+1);
	for(int i=0;i<=n;i++)
		v[i]=i;
	for(int i=g+1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
		if(__gcd(i,j)>g)
		{
			ri=root(v,i);
			rj=root(v,j);
			v[ri]=rj;
		}
		}
	}
	vector ans;
	vector ori(q);
	vector des(q);
	for(int i=0;i<q;i++)
	{
		cin>>ori[i];
	}
	for(int i=0;i<q;i++)
	{
		cin>>des[i];
	}
	for(int i=0;i<q;i++)
	{
		a=ori[i];
		b=des[i];
		if(root(v,a)==root(v,b))
			ans.push_back(1);
		else
			ans.push_back(0);
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]<<" ";
}



// yeah use DSU + union by rank. this code got accepted:

def connectedCities(n, g, originCities, destinationCities):
    n += 1
    parent = list(range(n))
    rank = [0] * n
    def find(x):
        if x != parent[x]:
            parent[x] = find(parent[x])
        return parent[x]
    def union(x, y):
        x, y = find(x), find(y)
        if x != y:
            if rank[x] >= rank[y]:
                parent[y] = x
                rank[x] += rank[x] == rank[y]
            else:
                parent[x] = y
    for i in range(g + 1, n):
        f = 2
        while i * f < n:
            union(i, i * f)
            f += 1
    return [int(find(s) == find(d)) for s, d in zip(originCities, destinationCities)]



 // Another approach


def connectedCities(n, g, originCities, destinationCities):
if g == 0:
    return [1] * len(originCities)
if g >= n:
    return [0] * len(originCities)
components = {i: i for i in range(g + 1, n + 1)}
for candidate in range(g + 1, n + 1):
    current = [t * candidate for t in range(1, n // candidate + 1)]
    current_components = [components[e] for e in current]
    minone = min(current_components)
    for curr in current:
        components[curr] = minone
res = []
for k in range(len(originCities)):
    origin, destination = originCities[k], destinationCities[k]
    if origin > g and destination > g and components[origin] == components[destination]:
        res.append(1)
    else:
        res.append(0)
return res
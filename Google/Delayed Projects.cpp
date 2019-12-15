// Delayed Projects

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		int n,m;
		cin>>n;
		cin>>m;
		unordered_multimap<char, char> mp;
		for(int i=0;i<n;i++)
		{
			char x,y;
			cin>>x;
			cin>>y;
			mp.insert(make_pair(y,x));
		}

		vector<char> v(m);
		for(int i=0;i<m;i++){
		    char x;
			cin>>x;
			v[i]=x;
		}
			
		vector<char> ans;
		for(int i=0;i<v.size();i++)
		{
			char x=v[i];
			ans.push_back(x);
			
			auto found_range = mp.equal_range(x);
			auto it = found_range.first;
			while(it != found_range.second){
			    auto itr = it;
			    while(itr!=mp.end())
    			{
    				ans.push_back(itr->second);
    				itr=mp.find(itr->second);
    			}
			    it++;
			}
			
		}
		sort(ans.begin(), ans.end());
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<", ";
		cout<<"\n";
	}
}





///////////////////////////////////////////////////////////////////////
// C++ Solution BFS, but we only need to care about the delay project (the delayList + the new delay project)

class Solution {
public:
    vector<char> delayedProjects(int dependNum, int delayNum, list<pair<char, char> > dependencies, list<char> delaies) {
        set<char> delaySet(begin(delaies), end(delaies));
        vector<char> delayVec;
        queue<char> q;
        for (char delay : delaies) q.push(delay);
        
        unordered_map<char, vector<char> > dependMap;
        for (pair<char, char> dependence : dependencies)
            dependMap[dependence.second].emplace_back(dependence.first);
        
        while (!q.empty()) {
            char project1 = q.front();
            q.pop();
            for (char project : dependMap[project1]) {
                if (!delaySet.count(project)) {
                    delaySet.insert(project);
                    q.push(project);
                }
            }
        }
        delayVec.assign(begin(delaySet), end(delaySet));
        return delayVec;
    }
};

int main() {
    Solution*s = new Solution();
    list<pair<char, char> > dependencies = {{'B','A'}, {'C','B'}, {'C','E'},{'D','C'},{'D','F'},{'E','A'},{'F','E'},{'G','F'}};
    list<char> delaies = {'B','F'};
    vector<char> result = s->delayedProjects(8, 2, dependencies, delaies);
    for (char pro : result) cout << pro << " ";
}
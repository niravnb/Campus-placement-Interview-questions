// C++ program for activity selection problem 
// when input activities may not be sorted. 
#include <bits/stdc++.h> 
using namespace std; 

// A job has a start time, finish time and profit. 
struct Activitiy 
{ 
    int start, finish; 
}; 

// A utility function that is used for sorting 
// activities according to finish time 
bool activityCompare(Activitiy s1, Activitiy s2) 
{ 
    return (s1.finish < s2.finish); 
} 

// Returns count of the maximum set of activities that can 
// be done by a single person, one at a time. 
void printMaxActivities(Activitiy arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr+n, activityCompare); 

    cout << "Following activities are selected n"; 

    // The first activity always gets selected 
    int i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 

    // Consider rest of the activities 
    for (int j = 1; j < n; j++) 
    { 
    // If this activity has start time greater than or 
    // equal to the finish time of previously selected 
    // activity, then select it 
    if (arr[j].start >= arr[i].finish) 
    { 
        cout << "(" << arr[j].start << ", "
            << arr[j].finish << "), "; 
        i = j; 
    } 
    } 
} 

// Driver program 
int main() 
{ 
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, 
                                    {5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMaxActivities(arr, n); 
    return 0; 
} 





// ///////////////////////////////


// C++ program for activity selection problem 
// when input activities may not be sorted. 
#include <bits/stdc++.h> 
using namespace std; 

void SelectActivities(vector<int>s,vector<int>f){ 
// Vector to store results. 
    vector<pair<int,int>>ans; 

// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p; 

    for(int i=0;i<s.size();i++){ 
        // Pushing elements in priority queue where the key is f[i] 
        p.push(make_pair(f[i],s[i])); 
    } 

    auto it = p.top(); 
    int start = it.second; 
    int end = it.first; 
    p.pop(); 
    ans.push_back(make_pair(start,end)); 

    while(!p.empty()){ 
        auto itr = p.top(); 
        p.pop(); 
        if(itr.second >= end){ 
            start = itr.second; 
            end = itr.first; 
            ans.push_back(make_pair(start,end)); 
        } 
    } 
    cout << "Following Activities should be selected. " << endl << endl; 

    for(auto itr=ans.begin();itr!=ans.end();itr++){ 
        cout << "Activity started at: " << (*itr).first << " and ends at " << (*itr).second << endl; 
    } 
} 

// Driver program 
int main() 
{ 
    vector<int>s = {1, 3, 0, 5, 8, 5}; 
    vector<int>f = {2, 4, 6, 7, 9, 9}; 
    SelectActivities(s,f); 

    return 0; 
} 

#include <bits/stdc++.h>
using namespace std;

void func(vector<pair<string,int> > arr,int n)
{
	vector<pair<string,pair<int,pair<int,float> > > > ans;
	sort(arr.begin(),arr.end());
	int max_value=arr[0].second,min_value=arr[0].second,sum=arr[0].second;
	int count=1;
	
	for(int i=1;i<n;i++)
	{
		string fruit1 = arr[i-1].first;
		string fruit2 = arr[i].first;

		if(fruit1==fruit2)
		{
			max_value=max(max_value,arr[i].second);
			min_value=min(min_value,arr[i].second);
			sum+=arr[i].second;
			count++;
			
		}
		else
		{
			float average=sum/count;
			pair<int,pair<int,float> > triplet;
			triplet.first=min_value;
			triplet.second = make_pair(max_value,average); 
			ans.push_back(make_pair(arr[i-1].first,triplet));
			max_value=arr[i].second;
			min_value=arr[i].second;
			sum=arr[i].second;
			count=1;
		}
	}

	float average=sum/count;
	pair<int,pair<int,float> > triplet;
	triplet.first=min_value;
	triplet.second = make_pair(max_value,average); 
	ans.push_back(make_pair(arr[n-1].first,triplet));
	
	

	for (int i = 0; i < ans.size(); i++)
	{
		pair<int,pair<int,float> > triplet;
		triplet= ans[i].second;
		min_value=triplet.first;
		max_value=triplet.second.first;
		float average=triplet.second.second;
		cout << ans[i].first << " " <<  min_value << " " << max_value << " " << average << endl; 
	}
	return ;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
	   int n;
	   cin >> n;
	   vector<pair<string,int> > arr;
	   string fruit;
	   int value;	   
	   for (int i=0;i<n;i++)
	   {
	   	 cin >> fruit >> value;
	   	 arr.push_back(make_pair(fruit,value));
	   }
	   func(arr,n);
	}
}
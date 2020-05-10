#include<bits/stdc++.h>
using namespace std;

bool compare(string s,string s1)
{
	return s.size()<s1.size();
}
int main()
{
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		
	}
	
	sort(v.begin(),v.end(),compare);
	
	for(int i=0;i<n-1;i++)
	{
		//cout<<"**";
		//cout<<v[i]<<endl;
		if(v[i+1].find(v[i])==string::npos)
		{
			cout<<"NO"<<endl;
			
			return 0;
		}
	}
	
	
	
	cout<<"YES"<<endl;
	
	for(auto i: v)
	{
		cout<<i<<endl;
	}
}

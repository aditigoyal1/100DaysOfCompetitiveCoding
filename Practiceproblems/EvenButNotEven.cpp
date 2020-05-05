#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int odd=0;
		string str="";
		for(char c:s)
		{
			if((c-'0')&1)
			{
			
			odd++;
			str=str+c;
	 		
	     	}
		}
		
		if(odd<2)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<str[0]<<str[str.length()-1]<<endl;
		}
		
		
    }
}

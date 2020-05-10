#include<bits/stdc++.h>
using namespace std;

long long t,j,i,s;
long long a,b;
int main()
{
	 
	cin>>t;
	for(j=0;j<t;j++)
	{
		
		cin>>a>>b;
		s=0;
		if(a-b!=1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			//cout<<"***"<<endl;
			if((a+b)%2!=0)
			{
				//cout<<"*****"<<endl;
				for(i=3;i*i<=a+b;i+=2)
				{
				
					if((a+b)%i==0)
					{
						cout<<"NO"<<endl;
						s=1;
						//cout<<"**"<<endl;
						break;
						
						
					}
				}
			
		}else
		{
			cout<<"NO"<<endl;
			continue;
		}
		
		if(s==0)
		{
			cout<<"YES"<<endl;
		}
	}
	
}
}



#include <bits/stdc++.h>
using namespace std;
multiset<int>ms;
int main(){
	int q;
	scanf("%d",&q);
	ms.insert(0);
	while(q--){
		char cmd; int x;
		scanf(" %c %d", &cmd, &x);
		if(cmd =='+') ms.insert(x);
		else if(cmd=='-') ms.erase(ms.find(x));
		else{
			int cur=0;
			for (int i=30;i>=0;--i){
				cur|=(~x&(1<<i));
			//	cout<<cur<<" "<<i<<endl;
				auto it=ms.lower_bound(cur);
				if(it==ms.end() || (*it>>i)!=(cur>>i))
					{
						cur^=1<<i;
						
						//cout<<cur<<"***"<<i<<endl;
					}
					
			}
			printf("%d\n",cur^x);
		}
	}
	return 0;
}

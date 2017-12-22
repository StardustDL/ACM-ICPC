/*
[HNOI2002]营业额统计
分析：找前驱后继，set 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
typedef set<int>::iterator it;
set<int> S;
int ans=0,n;
int main(){
	scanf("%d",&n);
	for(int i=1,tx;i<=n;i++){
		if(scanf("%d",&tx)==-1)tx=0;
		if(S.begin()==S.end()){S.insert(tx);ans+=tx;continue;}
		it I=S.upper_bound(tx);
		if(I==S.end()){
			I--;
			ans+=tx-(*I);
		}
		else{
			int t=(*I)-tx;
			if(I!=S.begin()){
				I--;
				t=min(t,tx-(*I));
			}
			ans+=t;
		}
		S.insert(tx);
	}
	printf("%d\n",ans);
	return 0;
}


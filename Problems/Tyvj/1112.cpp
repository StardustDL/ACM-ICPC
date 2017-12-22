#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,k,m,t,cnt;
int main(){
	scanf("%d%d",&n,&k);
	for(m=n;n;n--){
		for(scanf("%d",&t),cnt=0;t;cnt++,scanf("%d",&t));
		m-=(cnt<k);
	}
	printf("%d",m);
	return 0;
}


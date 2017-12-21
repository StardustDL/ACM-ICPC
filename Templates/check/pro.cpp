/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,a[MAXN+3];
int main(){
	freopen("data.in","r",stdin);
	freopen("pro.out","w",stdout);
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans=max(ans,a[i]); 
	}
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


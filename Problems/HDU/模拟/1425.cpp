/*
sort
题意：取N个数中的前M大
分析：直接sort。。TLE
	  计数排序 
*/
#include<iostream>
#include<cstring>
using namespace std;
bool b[1000001];
int main(){
	int tem,n,m;
	while(cin>>n>>m){
		memset(b,0,sizeof(b));   
		for(int i=0;i<n;i++){
			scanf("%d",&tem);
			b[500000+tem]=1;
		}
		for(int i=1000000;m>=1;i--){
			if(b[i]==1){
				printf("%d",i-500000);
				if(m>1)putchar(32);
				else putchar(10);
				m--;
			}
		}
	}
	return 0;
}

/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000000;
int n,m,a[MAXN+3];
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		printf("%d",a[n]);
		for(int i=1;i<m;i++)printf(" %d",a[n-i]);
		puts("");
	}
	return 0;
}
*/

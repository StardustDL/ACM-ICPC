/*
[PA2014]Lustra
分析：找最大，最小，判断是否存在 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int a[MAXN+3],b[MAXN+3],c[MAXN+3],d[MAXN+3];
int A,B,C,D,n,T;
const char OUT[2][5]={"NIE","TAK"};
inline bool judge(){
	for(int i=1;i<=n;i++)if(a[i]==A&&b[i]==B&&c[i]==C&&d[i]==D)return true;
	return false;
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		}
		A=*min_element(a+1,a+n+1);
		B=*max_element(b+1,b+n+1);
		C=*min_element(c+1,c+n+1);
		D=*max_element(d+1,d+n+1);
		puts(OUT[judge()]);
	}
	return 0;
}


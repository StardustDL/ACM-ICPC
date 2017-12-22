/*
[Usaco2005 qua]Who's in the Middle
分析：中位数，注意nth_element(a+1,a+index,a+n+1)，第二个不要+1 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int n,a[MAXN+3]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	nth_element(a+1,a+(n+1>>1),a+n+1);
	//sort(a+1,a+n+1);
	printf("%d\n",a[(n+1>>1)]); 
	return 0;
}


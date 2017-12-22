#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,a,cnt=0,flg=0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(a<k)cnt++;
		if(a==k)flg=1;
	}
	printf("%d\n",flg?cnt+1:-1);
	return 0;
}
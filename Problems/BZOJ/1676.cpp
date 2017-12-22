/*
[Usaco2005 Feb]Feed Accounting 饲料计算
分析：倒着用差分序列，f2每次更新，直到到f2>=f1的时候就输出
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int c,f1,f2,d,r,sum;
int a[2000+3];
int main(){
	scanf("%d%d%d%d",&c,&f1,&f2,&d);
	for(int x,y;c;c--){
		scanf("%d%d",&x,&y);
		a[x-1]--;a[y]++;
		r=max(r,y);
	}
	for(int i=r;i;i--){
		sum+=a[i];if(i<=d)f2+=sum;
		if(f2>=f1){printf("%d\n",i);break;}
	}
	return 0;
}

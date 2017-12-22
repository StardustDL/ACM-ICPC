/*
Longest Ordered Subsequence
题意：LIS
分析：nlogn方法即可，注意0<=x<=10000,将x+1当作输入可以避免lower_bound对0的误判（因为ans={0}） 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int ans[MAXN+3],top=0,n; 
int main(){
	scanf("%d",&n);
	for(int x;n;n--){
		scanf("%d",&x);x++;
		if(x>ans[top])ans[++top]=x;
		else ans[lower_bound(ans+1,ans+top+1,x)-ans]=x;
	}
	printf("%d\n",top);
	return 0;
}


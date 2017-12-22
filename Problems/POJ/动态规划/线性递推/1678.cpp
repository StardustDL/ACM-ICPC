/*
I Love this Game!
���⣺��n����������һ������[a,b],��һ��ѡ����Ҫ����������ڣ�Ȼ��ÿ��ѡn�����е�ĳ������ʹ���������ȥ������ѡ�����õ��Ĳ�ֵ��[a,b]�����ڡ�b>a>0�����һ��ѡ����ѡ�����ĺͼ�ȥ�ڶ�������ѡ�����ĺ͵�����ֵ��AҪʹsum1-sum2���B������sum1-sum2С�������Ƕ���ȡ��ѵ����� 
����������+Dp��a>0������ȡ��˳��һ���ǵ����ģ����������Ͳ����ں�Ч���ˣ�����DP��opt[i]��ʾѡ��iλ�õ������ܵõ�������ֵ������opt[i]=val[i]-max{opt[j]|val[j]-val[i]��[a,b] && n>=j>i} 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
int v[MAXN+3],opt[MAXN+3],a,b,n;
void input(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	sort(v+1,v+n+1);
}
int dp(){
	int ans=INT_MIN;
	memset(opt,0,sizeof(opt));
	for(int i=n;i>=1;i--){
		int mx=INT_MIN;
		for(int j=i+1;j<=n;j++){
			int c=v[j]-v[i];
			if(c>b)break;
			if(c>=a)mx=max(mx,opt[j]);
		}
		if(mx==INT_MIN)mx=0;
		opt[i]=v[i]-mx;
	}
	for(int i=1;i<=n;i++){
		if(v[i]>b)break;
		if(v[i]>=a)ans=max(ans,opt[i]);
	}
	return ans==INT_MIN ? 0:ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		input();
		printf("%d\n",dp());
	}
	return 0;
}


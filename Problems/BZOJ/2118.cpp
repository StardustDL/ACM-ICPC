/*
īī�ĵ�ʽ
������ͬ��ϵbfs����mnΪa[1]~a[n]��������Сֵ������Ȼ�����x�ܱ��ճ�����x+mnҲ�ܱ��ճ�������������ֻ��Ҫ֪������ÿһ��x����[0,mn)������y%mn==x����С��y����ô����֪��[1,R]��ģmn����x�������ܴճ����ĸ�����
		ע��spfa��ʱ��������Ҫ��һ��
		��Ҫ���⴦��һ��a=0��������������ݺ���a!=0
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue> 
using namespace std;
typedef long long LL;
const int MAXN=500000;
queue<int> q;
LL d[MAXN+3],l,r;
int mn,n,a[MAXN+3];
bool inq[MAXN+3];
void spfa(int s){
	for(int i=1;i<mn;i++)d[i]=1LL<<62;
	d[0]=0;while(!q.empty())q.pop();
	q.push(s);inq[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=1;i<=n;i++){
			int v=(u+a[i])%mn;
			if(d[v]>d[u]+a[i]){
				d[v]=d[u]+a[i];
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
LL query(LL x){
	LL ans=0;
	for(int i=0;i<mn;i++)if(d[i]<=x)ans+=(x-d[i])/mn+1;
	return ans;
}
int main(){
	scanf("%d%lld%lld",&n,&l,&r);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]==0)i--,n--;}mn=*min_element(a+1,a+n+1);
	spfa(0);
	printf("%lld\n",query(r)-query(l-1));
	return 0;
}


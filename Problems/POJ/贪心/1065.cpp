/*
Wooden Sticks
���⣺����Ҫ����һЩľ������һ����ʱ����1���ӣ�����ģ��ڳ���Ϊl����Ϊw��ľ��������Ǹ��ĳ���Ϊl��, ����w����ֻҪl <=l�� ����w <= w�����Ͳ���Ҫʱ�䣬������Ҫ1���ӣ�����ΰ��Ŵ���ľ����˳�򣬲���ʹ����ʱ�����١�
��������lΪ��һ�ؼ��֣�wΪ�ڶ��ؼ�������Ȼ������ÿ��Ҫѡλ�õ�������������У�������̰�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=5000;
struct data{
	int l,w;
	bool operator <(const data &t)const{
		return l<t.l||l==t.l&&w<t.w;
	}
}ds[MAXN+3];
int n;
bitset<MAXN+3> used;
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&ds[i].l,&ds[i].w);
	}
	sort(ds+1,ds+n+1);
}
int solve(){
	int ans=0,curw=0;used=0;
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		curw=ds[i].w;
		for(int j=i+1;j<=n;j++){
			if(curw<=ds[j].w&&!used[j]){
				used[j]=1;curw=ds[j].w;
			}
		}
		ans++;
	}
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		input();
		printf("%d\n",solve());
	}
	return 0;
}


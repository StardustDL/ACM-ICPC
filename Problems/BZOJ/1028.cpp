/*
[JSOI2007]麻将
分析：首先枚举加了哪张牌，再枚举哪个是一对，然后贪心判断剩下的是否能凑成m对，贪心策略为从小到大看当前牌模3剩下的是否能跟跟他连着的两个牌配对，若能，就先配对（因为必须配对 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,m,cnt[MAXN+3],temp[MAXN+3];
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	int t;
	for(int i=1;i<=3*m+1;i++){
		scanf("%d",&t);
		cnt[t]++;
	}
	for(int i=1;i<=n;i++){
		cnt[i]++;
		bool flg=true;
		for(int j=1;j<=n;j++){
			if(cnt[j]<2)continue;
			memcpy(temp,cnt,sizeof(temp));
			temp[j]-=2;flg=true;
			for(int k=1;k<=n;k++){
				temp[k]%=3;
				if(k+2>n&&temp[k]>0){
					flg=false;break;
				}
				if(temp[k+1]<temp[k]||temp[k+2]<temp[k]){
					flg=false;break;
				}
				temp[k+1]-=temp[k];
				temp[k+2]-=temp[k];
			}
			if(flg)break;
		}
		cnt[i]--;
		if(flg)q.push(i);
	}
	if(q.empty())puts("NO");
	else{
		printf("%d",q.front());q.pop();
		while(!q.empty()){
			printf(" %d",q.front());q.pop();
		}
	}
	return 0;
}


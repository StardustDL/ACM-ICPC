/*
[Usaco2005 jan]The Wedding Juicer �����ե֭��
���⣺��N*M�ĸ����ϣ�ÿ�����Ӷ���һ���߶ȡ�ˮ��Ӹ����򲻱����ߵĵط������һ�ӱ�Ե�������������װ����ˮ ��
�������Ƚ�����Χ�����񰴸߶Ȳ���С���ѣ�ÿ��ȡ��ǰ�Ѷ�x��������û���ʹ��ĵ���£�
	  ����µ�y�߶�С�ڵ�ǰ��x��˵��y����Դ�ˮ���߶�Ϊx��-y��߶ȣ��������y�������У��߶�Ϊx��ĸ߶ȣ�
	  ���y��߶ȴ��ڵ���x�㣬��ôֱ�Ӽ�����У���ǰ��ִ������˳��ѡ� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
using namespace std;
const int MAXN=300,INF=0x3f3f3f3f;
typedef long long LL;
struct P{
	int x,y,h;
	bool operator <(const P &t)const{
		return h>t.h;
	}
	P(int x,int y,int h):x(x),y(y),h(h){}
};
priority_queue<P> pq;
int W,H,b[MAXN+3][MAXN+3],v1[MAXN+3][MAXN+3],v2[MAXN+3][MAXN+3];
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
LL ans=0;
int main(){
	scanf("%d%d",&W,&H);
	for(int i=1;i<=H;i++)for(int j=1;j<=W;j++){
		scanf("%d",&b[i][j]);
		if(i==1||j==1||i==H||j==W){
			pq.push(P(i,j,b[i][j]));
			v1[i][j]=1;
		}
	}
	while(!pq.empty()){
		P t=pq.top();pq.pop();
		if(v2[t.x][t.y])continue;
		for(int i=0;i<4;i++){
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(tx<1||ty<1||tx>H||ty>W||v1[tx][ty]||v2[tx][ty])continue;
			v1[tx][ty]=1;
			if(b[tx][ty]<t.h){
				//cout<<tx<<" "<<ty<<endl;
				ans+=t.h-b[tx][ty];
				pq.push(P(tx,ty,t.h));
			}
			else pq.push(P(tx,ty,b[tx][ty]));
		}
		v2[t.x][t.y]=1;
	}
	printf("%lld\n",ans); 
	return 0;
}


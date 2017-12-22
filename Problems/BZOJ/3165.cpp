/*
[Heoi2013]Segment 
������ע��X��Χ��С�������߶�����ά�����������߶Σ�
	  �����߶�ʱ���������߶����Ϸ��ѳ�O(logn)�����������뵱ǰ��������߶β��ཻ����ôȡ���ŵģ��������ݹ����������︴�Ӷ���O(log^2(n)) 
		��ѯʱ��Ҷ�ӵ���·�������е�������߶���ȡ�����ŵļ��ɡ�O(logn)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,N=39989;
struct segment{
	double k,b;
	segment(){}
	segment(int x0,int y0,int x1,int y1){
		if(x0==x1)k=0,b=max(y0,y1);
		else k=1.0*(y0-y1)/(x0-x1),b=-k*x0+y0;
	}
	double cy(int x){
		return k*x+b;
	}
};
vector<segment> S;
inline int dcmp(double t){
	return fabs(t)<1e-8?0:(t>0?1:-1);
}
int f[N*4+3];
bool isup(int a,int b,int l,int r){//�ж�a�Ƿ���b�Ϸ� 
	return dcmp(S[a].cy(l)-S[b].cy(l))>0 && dcmp(S[a].cy(r)-S[b].cy(r))>0;
}
void insert(int x,int L,int R,int l,int r,int pos){
	if(l<=L&&r>=R){
		if(isup(pos,f[x],L,R)){f[x]=pos;return;}
		else if(isup(f[x],pos,L,R))return;
	}
	if(L==R)return;
	int mid=(L+R)>>1;
	if(l<=mid)insert(x<<1,L,mid,l,r,pos);
	if(r>mid)insert(x<<1|1,mid+1,R,l,r,pos);
}
int ans=0;
void query(int x,int l,int r,int X){
	int d=dcmp(S[f[x]].cy(X)-S[ans].cy(X));
	if(d>0 || d==0&&ans>f[x])ans=f[x];
	if(l==r)return;
	int mid=(l+r)>>1;
	X<=mid?query(x<<1,l,mid,X):query(x<<1|1,mid+1,r,X);
}
int main(){
	S.push_back(segment()); 
	S[0].b=-1;//�������붼������ 
	int n;scanf("%d",&n);
	for(int q,w,e,r,t;n;n--){
		scanf("%d",&q);
		if(q){
			scanf("%d%d%d%d",&w,&e,&r,&t);
			w=(w+ans-1)%39989+1;
			e=(e+ans-1)%1000000000+1;
			r=(r+ans-1)%39989+1;
			t=(t+ans-1)%1000000000+1;
			S.push_back(segment(w,e,r,t));
			if(w>r)swap(w,r);
			insert(1,1,N,w,r,S.size()-1); 
		}
		else{
			scanf("%d",&w);
			w=(w+ans-1)%39989+1;ans=0;query(1,1,N,w);
			printf("%d\n",ans);
		}
	}
	return 0;
}


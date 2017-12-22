/*
[POI2009]Lyz
���������Ƚ��˺�Ь�ӺŶ�Ӧ�ɶ���ͼ
	  Hall�����˶���ʹ������������У�����ͼG�е������ֶ�����ɵļ��Ϸֱ�ΪX, Y, X={X1, X2, X3,X4,.........,Xm}, Y={y1, y2, y3, y4 ,.........,yn},G����һ���޹�����ıߣ�һ��ǡ��Ϊ���X�ĵ�ĳ�ֱ�Ҫ�����ǣ�
	    X�е�����k����������Y�е�k�������ڡ���1��k��m) 
	  �����н��������������һ���˵ļ��ϵ�����<=�����ӵ�Ь������,����������˵������������о͹���  
	  ��ti��ʾЬ��Ϊi����������sigma{t[l..r]}<=(r+d-l+1)*k 
	  ��pi=ti-k,�� sigma{p[l..r]}<=d*k
	  ά��p��������������кͼ��ɣ��߶���һ��Ҫ��4���� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200000,INF=0x3f3f3f3f;
const char OUT[2][5]={"NIE","TAK"};
typedef long long LL;
struct segment_tree{
	struct node{
		LL ls,rs,sum,ms;
		node(){ls=rs=sum=ms=0;}
	}ns[4*MAXN+3];
	#define LC(x) ((x)<<1)
	#define RC(x) ((x)<<1|1)
	void change(int l,int r,int x,int pos,int ad){
		if(l==r){ns[x].sum+=ad;ns[x].ls+=ad;ns[x].rs+=ad,ns[x].ms+=ad;return;}
		int mid=(l+r)>>1;
		if(pos<=mid)change(l,mid,LC(x),pos,ad);
		else change(mid+1,r,RC(x),pos,ad);
		ns[x].sum=ns[LC(x)].sum+ns[RC(x)].sum;
		ns[x].ls=max(ns[LC(x)].sum+ns[RC(x)].ls,ns[LC(x)].ls);
		ns[x].rs=max(ns[RC(x)].sum+ns[LC(x)].rs,ns[RC(x)].rs);
		ns[x].ms=max(max(ns[LC(x)].ms,ns[RC(x)].ms),ns[LC(x)].rs+ns[RC(x)].ls);
	}
}S;
int n,m,k,d; 
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=n;i++)S.change(1,n,1,i,-k);
	for(int r,x;m;m--){
		scanf("%d%d",&r,&x);
		S.change(1,n,1,r,x);
		puts(OUT[S.ns[1].ms<=(LL)k*d]);
	}
	return 0;
}


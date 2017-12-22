/*
[Scoi2010]序列操作
分析：线段树，一套标记和信息= = 
*/
#include<iostream>
#include<cstdio>
const int MAXN=100000+5;
using namespace std;
int n,m; 
struct seg{
    int l,r;
    int l0,l1,r0,r1,mx0,mx1,sum0,sum1;
    int rev,c,full;
}t[MAXN<<2];
void rev(int k){
    swap(t[k].l0,t[k].l1);
    swap(t[k].r0,t[k].r1);
    swap(t[k].mx0,t[k].mx1);
    swap(t[k].sum0,t[k].sum1);
    if(t[k].full!=-1)t[k].full^=1;
    t[k].rev^=1; 
}
void color(int k,int v){
    t[k].rev=0;
    int s=t[k].r-t[k].l+1;
    if(v==0){
       t[k].sum0=t[k].l0=t[k].r0=t[k].mx0=s;
       t[k].sum1=t[k].l1=t[k].r1=t[k].mx1=0;
    }
    else{
       t[k].sum0=t[k].l0=t[k].r0=t[k].mx0=0;
       t[k].sum1=t[k].l1=t[k].r1=t[k].mx1=s;
    }
    t[k].full=t[k].c=v;
}
seg merge(seg a,seg b){
    seg tmp;tmp.l=a.l;tmp.r=b.r;
    tmp.rev=0;tmp.c=-1;
    tmp.l0=a.l0;tmp.l1=a.l1;
    tmp.r0=b.r0;tmp.r1=b.r1;
    tmp.mx0=max(a.mx0,b.mx0);
    tmp.mx1=max(a.mx1,b.mx1);
    tmp.mx0=max(tmp.mx0,a.r0+b.l0);
    tmp.mx1=max(tmp.mx1,a.r1+b.l1);
    tmp.sum0=a.sum0+b.sum0;
    tmp.sum1=a.sum1+b.sum1;
    if(a.full==0)tmp.l0=a.mx0+b.l0;
    else if(a.full==1)tmp.l1=a.mx1+b.l1;
    if(b.full==0)tmp.r0=b.mx0+a.r0;
    else if(b.full==1)tmp.r1=b.mx1+a.r1;
    if(a.full==b.full)tmp.full=a.full;
    else tmp.full=-1;
    return tmp;
}
void pushup(int k){
    t[k]=merge(t[k<<1],t[k<<1|1]);
}
void pushdown(int k){
    if(t[k].l==t[k].r)return;
    if(t[k].c!=-1){
        color(k<<1,t[k].c);color(k<<1|1,t[k].c);
        t[k].c=-1;
    }
    if(t[k].rev){
        //t[k<<1].rev^=1;t[k<<1|1].rev^=1;
        rev(k<<1);rev(k<<1|1);
        t[k].rev=0;
    }
}
void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].c=-1;
    if(l==r){
        scanf("%d",&t[k].full);
        if(t[k].full){t[k].l1=t[k].r1=t[k].mx1=t[k].sum1=1;}
        else{t[k].l0=t[k].r0=t[k].mx0=t[k].sum0=1;}
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);build(k<<1|1,mid+1,r);
    pushup(k);
}
void change(int k,int x,int y,int v){
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l>=x&&r<=y){
        color(k,v);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)change(k<<1,x,y,v);
    if(y>mid)change(k<<1|1,x,y,v);
    pushup(k);
}
void reverse(int k,int x,int y){
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l>=x&&r<=y){
        rev(k);
        //t[k].rev=1;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)reverse(k<<1,x,y);
    if(y>mid)reverse(k<<1|1,x,y);
    pushup(k);
}
seg ask_mx(int k,int x,int y){
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l>=x&&r<=y)return t[k];
    int mid=(l+r)>>1;
    if(mid>=y)return ask_mx(k<<1,x,y);
    else if(mid<x)return ask_mx(k<<1|1,x,y);
    else return merge(ask_mx(k<<1,x,mid),ask_mx(k<<1|1,mid+1,y));//必须要合并一下再算答案，直接区间信息是不行的= = 
}
int asksum(int k,int x,int y){
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l>=x&&r<=y)return t[k].sum1;
    int mid=(l+r)>>1,ans=0;
	if(x<=mid)ans+=asksum(k<<1,x,y);
    if(y>mid)ans+=asksum(k<<1|1,x,y);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int f,x,y;
        scanf("%d%d%d",&f,&x,&y);
        x++;y++;
        switch(f){
            case 0:change(1,x,y,0);break;
            case 1:change(1,x,y,1);break;
            case 2:reverse(1,x,y);break;
            case 3:printf("%d\n",asksum(1,x,y));break;
            case 4:printf("%d\n",ask_mx(1,x,y).mx1);break;
        }
    }
    return 0;
}

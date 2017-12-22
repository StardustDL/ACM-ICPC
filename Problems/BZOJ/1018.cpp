/*
分析：线段树维护连通性
	  以每一个区间（就是每1条横向道路连接的左右两个节点）为一个叶子节点。 
	  维护6个变量（也就是区间内的6种联通关系），分别是luru，ldrd，lurd，ldru，luld，rurd（l：left；r：right；u：up；d：down） 
	  为了便于合并两个区间，由于左边是[1..k]，右边是[k+1..n]，不知道k..k+1的连通性，所以维护一个side[1..2]表示区间右侧的[r..r+1]的两行的连通性 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100100;
struct S{bool luru,ldrd,lurd,ldru,luld,rurd,side[3];}tr[N*4];
char ch[10];
int n,r1,c1,r2,c2;
#define mid (l+r)/2
#define L k<<1,l,mid
#define R k<<1|1,mid+1,r
S update(S x,S y){
    S ans;
    ans.side[1]=y.side[1];
    ans.side[2]=y.side[2];
    ans.luru=ans.ldrd=ans.lurd=ans.ldru=ans.luld=ans.rurd=false;
    if((x.luru&&x.side[1]&&y.luru)||(x.lurd&&x.side[2]&&y.ldru)) ans.luru=true;
    if((x.ldrd&&x.side[2]&&y.ldrd)||(x.ldru&&x.side[1]&&y.lurd)) ans.ldrd=true;
    if((x.luru&&x.side[1]&&y.lurd)||(x.lurd&&x.side[2]&&y.ldrd)) ans.lurd=true;
    if((x.ldrd&&x.side[2]&&y.ldru)||(x.ldru&&x.side[1]&&y.luru)) ans.ldru=true;
    if((x.luld)||(x.luru&&x.side[1]&&y.luld&&x.side[2]&&x.ldrd)) ans.luld=true;
    if((y.rurd)||(y.luru&&x.side[1]&&x.rurd&&x.side[2]&&y.ldrd)) ans.rurd=true;
    return ans;
}
void build(int k,int l,int r){
    if(l==r){
        tr[k].luru=tr[k].ldrd=true;
        return ;
    }
    build(L);build(R);
    tr[k]=update(tr[k<<1],tr[k<<1|1]);
}
void insert_a(int k,int l,int r,int x,bool kind){
    if(l==r){
        tr[k].luld=tr[k].rurd=tr[k].lurd=tr[k].ldru=kind;
        return ;
    }
    if(x<=mid) insert_a(L,x,kind);
    else insert_a(R,x,kind);
    tr[k]=update(tr[k<<1],tr[k<<1|1]);
}
void insert_b(int k,int l,int r,int x,int y,bool kind){
    if(l==r){
        tr[k].side[y]=kind;
        return ;
    }
    if(x<=mid) insert_b(L,x,y,kind);
    else insert_b(R,x,y,kind);
    tr[k]=update(tr[k<<1],tr[k<<1|1]);
}
S query(int k,int l,int r,int x,int y){
    S ans1,ans2;
    bool left=false,right=false;
    if(x<=l&&y>=r) return tr[k];
    if(x<=mid) ans1=query(L,x,y),left=true;
    if(y>mid) ans2=query(R,x,y),right=true;
    if(right&&left) return update(ans1,ans2);
    else return left?ans1:ans2;
}
bool check(){
    S now,pre,last;
    if(c1>c2){
        swap(r1,r2);
        swap(c1,c2);
    }
    now=query(1,1,n,c1,c2);
    pre=query(1,1,n,1,c1);
    last=query(1,1,n,c2,n);
    if(r1==r2){
        if((r1==1)&&((now.luru)||(last.luld&&now.lurd)||(pre.rurd&&now.ldru)||(pre.rurd&&now.ldrd&&last.luld))) return true;
        if((r1==2)&&((now.ldrd)||(last.luld&&now.ldru)||(pre.rurd&&now.lurd)||(pre.rurd&&now.luru&&last.luld))) return true;
    }
    else{
        if((r1==1)&&((now.lurd)||(last.luld&&now.luru)||(pre.rurd&&now.ldrd)||(pre.rurd&&now.ldru&&last.luld))) return true;
        if((r1==2)&&((now.ldru)||(last.luld&&now.ldrd)||(pre.rurd&&now.luru)||(pre.rurd&&now.lurd&&last.luld))) return true;
    }
    return false;
}
int main(){
    int i,j;
    scanf("%d",&n);
    build(1,1,n);
    while(scanf("%*c%s",&ch)){
        if(ch[0]=='E') break;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        if(ch[0]=='O'){
            if(c1==c2) insert_a(1,1,n,c1,1);
            else insert_b(1,1,n,min(c1,c2),r1,1);
        }
        if(ch[0]=='C'){
            if(c1==c2) insert_a(1,1,n,c1,0);
            else insert_b(1,1,n,min(c1,c2),r1,0);
        }
        if(ch[0]=='A'){
            if(check()) printf("Y\n");
            else printf("N\n");
        }
    }
}

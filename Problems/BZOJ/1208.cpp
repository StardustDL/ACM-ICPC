/*
[HNOI2004]宠物收养所
分析：维护一个集合:
	  支持插入元素，删除元素，查询比某个元素大的最小值和比
	  某个元素小的最大值。
	  Splay，删除时用其后继替换， 
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000,MAXN=80000;
int n,size,rt,kind,t1,t2;
long long ans;
int tr[MAXN+3][2],num[MAXN+3],fa[MAXN+3];
void rotate(int x,int &k){
	int y=fa[x],z=fa[y],l,r;
	if(tr[y][0]==x)l=0;else l=1;r=l^1;
	if(y==k)k=x;
	else{if(tr[z][0]==y)tr[z][0]=x;else tr[z][1]=x;}
	fa[x]=z;fa[y]=x;fa[tr[x][r]]=y;
	tr[y][l]=tr[x][r];tr[x][r]=y;
}
void splay(int x,int &k){
	int y,z;
	while(x!=k){
		y=fa[x],z=fa[y];
		if(y!=k){
			if((tr[y][0]==x)^(tr[z][0]==y))rotate(x,k);
			else rotate(y,k);
		}
		rotate(x,k);
	}
}
void ins(int &k,int x,int last){
	if(k==0){k=++size;num[k]=x;fa[k]=last;splay(k,rt);return;}
	if(x<num[k])ins(tr[k][0],x,k);else ins(tr[k][1],x,k);
}
void del(int x){
	splay(x,rt);
	if(tr[x][0]*tr[x][1]==0)rt=tr[x][0]+tr[x][1];
	else{
		int k=tr[x][1];
		while(tr[k][0])k=tr[k][0];
		tr[k][0]=tr[x][0];fa[tr[x][0]]=k;
		rt=tr[x][1];
	}
	fa[rt]=0;
}
void ask_before(int k,int x){
	if(k==0)return;
	if(num[k]<=x){t1=k;ask_before(tr[k][1],x);}
	else ask_before(tr[k][0],x);
}
void ask_after(int k,int x){
	if(k==0)return;
	if(num[k]>=x){t2=k;ask_after(tr[k][0],x);}
	else ask_after(tr[k][1],x);
}
int main(){
    scanf("%d",&n);
    int f,x;
    for(int i=1;i<=n;i++){
		scanf("%d%d",&f,&x);
		if(!rt){kind=f;ins(rt,x,0);}
		else if(kind==f){ins(rt,x,0);}
		else {
			t1=t2=-1;
			ask_before(rt,x);ask_after(rt,x);
			if(t1==-1){(ans+=num[t2]-x)%=MOD;del(t2);}
			else if(t2==-1){(ans+=x-num[t1])%=MOD;del(t1);}
			else{
				if(x-num[t1]>num[t2]-x){(ans+=num[t2]-x)%=MOD;del(t2);}
				else{(ans+=x-num[t1])%=MOD;del(t1);}
			}
		}	
	}
	cout<<ans<<endl;
    return 0;
}

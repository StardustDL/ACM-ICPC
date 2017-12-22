/*
[NOI2007]项链工厂
分析：线段树可做 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
#define N 500010
#define INF (1<<30)
using namespace std;
int data[N],n;
struct segment_color{
	int l,r,sum;
	segment_color(){}
	segment_color(int x){
		sum=1;
		if(!x) sum=0;
		l=r=x;
	}
	friend segment_color operator + (segment_color a,segment_color b){
		segment_color re(0);
		re.l=a.l ? a.l : b.l;
		re.r=b.r ? b.r : a.r;
		re.sum=a.sum+b.sum-(a.r==b.l);
		return re;
	}
};
struct node{
    int size;       //以当前点位根的子树的大小
    int col;        //当前节点的颜色
    int ch[2],pnt; 
    bool reverse;   //反转标记
    int lab;      //颜色标记
    segment_color w;
};
node tr[N];
int tot=0;
int root=1;
void update(int x){
    int l=tr[x].ch[0];
    int r=tr[x].ch[1];
    tr[x].size=tr[l].size+tr[r].size+1;
    tr[x].w=tr[l].w+segment_color(tr[x].col)+tr[r].w;
}
void downlab(int x){
    int l=tr[x].ch[0];
    int r=tr[x].ch[1];
    if(tr[x].reverse){
        tr[l].reverse^=1;
        tr[r].reverse^=1;
        swap(tr[l].ch[0],tr[l].ch[1]);
        swap(tr[r].ch[0],tr[r].ch[1]);
        swap(tr[l].w.l,tr[l].w.r);
        swap(tr[r].w.l,tr[r].w.r);
        tr[x].reverse=0;
    }
    if(tr[x].lab){
        if(l){
            tr[l].col=tr[l].lab=tr[x].lab;
            tr[l].w=segment_color(tr[x].lab);
        }
        if(r){
            tr[r].col=tr[r].lab=tr[x].lab;
            tr[r].w=segment_color(tr[x].lab);
        }
        tr[x].lab=0;
    }      
}
void build(int l,int r,int fa){
    int mid=(l+r)>>1;
    tot++;
    int now=tot;
    tr[now].pnt=fa;
    tr[now].col=data[mid];
    tr[now].w=segment_color(data[mid]);
    tr[now].size=1;
    if(l<mid) {
        tr[now].ch[0]=tot+1;
        build(l,mid-1,now);
    }
    if(mid<r){
        tr[now].ch[1]=tot+1;
        build(mid+1,r,now);
    }
    update(now);
}
void rotate(int x,bool b){
    int l=tr[x].ch[!b];
    int r=tr[x].ch[b];
    int fa=tr[x].pnt;
    int g=tr[fa].pnt;
    tr[x].pnt=g;
    tr[fa].pnt=x;
    if(r) tr[r].pnt=fa;
    tr[x].ch[b]=fa;
    tr[fa].ch[!b]=r;
    if(g){
        if(tr[g].ch[0]==fa) tr[g].ch[0]=x;
        else tr[g].ch[1]=x;
    }
    update(fa);
}
void splay(int x,int target){
    while(tr[x].pnt!=target){
        int y=tr[x].pnt;
        int g=tr[y].pnt;
        if(tr[y].ch[0]==x){
            if(g!=target && tr[g].ch[0]==y)
                rotate(y,1);
            rotate(x,1);
        }
        else {
            if(g!=target && tr[g].ch[1]==y)
                rotate(y,0);
            rotate(x,0);
        }
        }
    update(x);
    if(target==0) root=x;
}
int search(int x,int target){
    int pos=root;
    while(1){
        downlab(pos);
        if(x==tr[tr[pos].ch[0]].size+1) {
            splay(pos,target);
            return pos;
        }
        if(x<=tr[tr[pos].ch[0]].size) pos=tr[pos].ch[0];
        else {
            x=x-tr[tr[pos].ch[0]].size-1;
            pos=tr[pos].ch[1];
        }
    }
}
void print(int x){
downlab(x);
if(tr[x].ch[0]) print(tr[x].ch[0]);
printf("(%d %d %d %d)",tr[x].col,tr[x].w.l,tr[x].w.r,tr[x].w.sum);
if(tr[x].ch[1]) print(tr[x].ch[1]);
}
int main(){
    int k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&data[i]);
    }
    data[0]=data[n+1]=0;
    build(0,n+1,0);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        char str[3];
        scanf("%s",str);
        if(str[0]=='R'){
            int k;
            scanf("%d",&k);
            int l=search(n-k+1,0);
        	int r=search(n+2,root);
        	int tmp=tr[r].ch[0];
        	tr[r].ch[0]=0;
        	update(r);
        	update(root);
        	l=search(1,0);
        	r=search(2,root);
        	tr[r].ch[0]=tmp;
        	tr[tmp].pnt=r;
        	update(r);
        	update(root);
        //	print(root);
            continue;
        }
        if(str[0]=='F'){
            int pos=search(2,0);
        	pos=search(n+2,root);
        	int tmp=tr[pos].ch[0];
        	tr[tmp].reverse^=1;
        	swap(tr[tmp].ch[0],tr[tmp].ch[1]);
        	swap(tr[tmp].w.l,tr[tmp].w.r);
			update(tr[root].ch[1]);
        	update(root);
        //	print(root);
            continue;
        }
        if(str[0]=='S'){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==b) continue;
       	 	if(a>b) swap(a,b);
        	int l=search(a+1,0);
        	int r=search(b+1,root);
        	swap(tr[l].col,tr[r].col);
        	update(r);
        	update(l);
            continue;
        }
        if(str[0]=='P'){
            int a,b,x;
            scanf("%d%d%d",&a,&b,&x);
            if(a<=b){
            	int l=search(a,0);
            	int r=search(b+2,root);
            	int tmp=tr[r].ch[0];
            	tr[tmp].col=tr[tmp].lab=x;
            	tr[tmp].w=segment_color(x);
            //	print(root);
      	 	}
        	else{
            	int l=search(a,0);
            	int r=search(n+2,root);
            	int tmp=tr[r].ch[0];
            	tr[tmp].col=tr[tmp].lab=x;
            	tr[tmp].w=segment_color(x);
            	l=search(1,0);
            	r=search(b+2,root);
            	tmp=tr[r].ch[0];
            	tr[tmp].col=tr[tmp].lab=x;
            	tr[tmp].w=segment_color(x);
        	}
            continue;
        }
        if(str[0]=='C' && strlen(str)==1){
        	int a,b;
        	a=1,b=n;
            int l=search(a,0);
            int r=search(b+2,root);
            int tmp=tr[r].ch[0];
            int res=tr[tmp].w.sum-(tr[tmp].w.l==tr[tmp].w.r);
            printf("%d\n",res ?  res : 1);
            continue;
        }
        if(str[0]=='C' && strlen(str)==2){
            int a,b;
            scanf("%d%d",&a,&b);
            int res=0;
            if(a==b) res=1;
            else if(a<b){
            	int l=search(a,0);
            	int r=search(b+2,root);
            	int tmp=tr[r].ch[0];
            	res=tr[tmp].w.sum;
			}
    	 	else{
        	    int l=search(a,0);
        	    int r=search(n+2,root);
        	    int tmp=tr[r].ch[0];
				segment_color w=tr[tmp].w;
            	l=search(1,0);
            	r=search(b+2,root);
            	tmp=tr[r].ch[0];
            	w=w+tr[tmp].w;
            	res=w.sum;
            }
            if(res==0) res=1;
            printf("%d\n",res);
        }  
    }
    return 0;
}

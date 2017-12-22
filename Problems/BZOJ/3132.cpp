/*
上帝造题的七分钟
分析：二维树状数组支持区间修改，维护区间和 ，1D：维护一个差分数组a[i] ，维护一个差分数组的倍数数组b[i]，即b[i]=a[i]*(i-1)，这样答案=sum_a[x]*x-sum_b[x] 
		二维就维护四个，然后。。一堆修改 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2050,INF=0x3f3f3f3f;
int n,m,a[MAXN+3],del;
struct BIT{
	#define lowbit(x) (x&-x)
	int c[MAXN+3][MAXN+3];
	void add(int x,int y,int ad){
		for(int i=x;i<=n;i+=lowbit(i))
			for(int j=y;j<=n;j+=lowbit(j))
				c[i][j]+=ad;
	}
	int sum(int x,int y){
		int ans=0;
		for(int i=x;i;i-=lowbit(i))
			for(int j=y;j;j-=lowbit(j))
				ans+=c[i][j];
		return ans;
	}
}b1,b2,b3,b4;
void update(int x, int y) {
    if (!x || !y) return;
    b1.add(x,y,x*y*del);
    b2.add(x,1,x*del),b2.add(x,y,-x*del);
    b3.add(1,y,y*del),b3.add(x,y,-y*del);
    b4.add(1,1,del),b4.add(x,y,del);
    b4.add(x,1,-del),b4.add(1,y,-del);
}
int query(int x, int y){
    return b1.sum(x,y)+b2.sum(x,y)*y+b3.sum(x,y)*x+b4.sum(x,y)*x*y;
}
int main() {
    char oper;
    int x1,x2,y1,y2;
    scanf(" %*c%d%d\n",&n,&m);
    while(scanf(" %c%d%d%d%d",&oper,&x1,&y1,&x2,&y2)!= EOF){
        if(oper=='L'){
            scanf("%d",&del);
            update(x2,y2),update(x1-1,y1-1);
            del=-del;
            update(x2,y1-1),update(x1-1,y2);
        } else
        printf("%d\n",query(x2,y2)+query(x1-1,y1-1)-query(x2,y1-1)-query(x1-1,y2));
    }
    return 0;
}

/* 1D
void update(int l,int r,int ad){
	if (!x || !y) return;
	b1.add(l,ad);
	b1.add(r,-ad);
	b2.add(l,-ad*(l-1));
	b2.add(r,ad*(r-1));
}
int _query(int x){
	return b1.sum(x)*x+b2.sum(x);
}
int query(int l,int r){return _query(r)-_query(l-1);}
*/


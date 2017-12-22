/*
Toy Storage
分析：Toys(2318)的升级版，只是中间的n个隔板未排序，输出的是装有i个玩具的区域的个数，其他完全一样
	  这里采用另一种判断方法 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Point{
    int x, y;
};
struct Line{
   Point a, b;
} line[5005];
int cnt[5005],ans[5005];
bool cmp(const Line& l1, const Line& l2) {
    if (min(l1.a.x, l1.b.x) == min(l2.a.x, l1.b.x))
        return max(l1.a.x, l1.b.x) < max(l2.a.x, l1.b.x);
    return min(l1.a.x, l1.b.x) < min(l2.a.x, l1.b.x);
}
int Multi(Point p1, Point p2, Point p0) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
void BSearch(Point a, int n){
    int l,r,mid;
    l=0; r=n-1;
    while (l<r){
        mid=(l+r)>>1;
        if(Multi(a,line[mid].a,line[mid].b)>0)l=mid+1;
        else r=mid;
    }
    if(Multi(a,line[l].a,line[l].b)<0)cnt[l]++;
    else cnt[l+1]++;
}
int main(){
    int n,m,x1,y1,x2,y2;
    int i,t1,t2;
    Point a;
    while(scanf("%d",&n)&&n){
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(i=0; i<n;i++){
            scanf ("%d%d", &t1, &t2);
            line[i].a.x=t1;
            line[i].a.y=y1;
            line[i].b.x=t2;
            line[i].b.y=y2;
        }
        sort(line,line+n,cmp);
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        for (i = 0; i < m; i++) {
            scanf ("%d%d",&a.x,&a.y);
            BSearch(a,n);
        }
        for(i=0;i<=n;i++)ans[cnt[i]]++;
        printf("Box\n");
        for(i=1;i<=m;i++)
            if(ans[i]!=0){
                printf("%d: %d\n",i,ans[i]);
                m-=i*cnt[i];
            }
    }
    return 0;
}


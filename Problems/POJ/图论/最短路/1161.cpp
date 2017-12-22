/*
Walls
题意：有 n 个小镇，他们两两之间可能存在一些墙（不是每两个都有），把整个二维平面分成多个区域，当然这些区域都是一些封闭的多边形（除了最外面的一个），现在，如果某几个小镇上的人想要聚会，为选择哪个区域为聚会地点，可以使他们所有人总共需要穿过的墙数最小，题目上有说明，不在某个点上聚会（聚会点在某个多边形内部），行进过程中不穿过图中的点（也就是除出发点外的其他小镇）。
		输入给出每个区域有哪些点围成 
分析：建图好题。
	  每个人的出发点一定属于某个环（多边形），两个相邻环之间要想通行的话，穿过一面墙就可以直接到达，
	  如果不相邻的话，需要先穿过其他区域间接到达。这样，一个最短路模型就出来了。
	  把每个环当成点，以两个环之间的距离为边建图，相邻环之间距离为 1 ，不相邻的先设为无穷大，
	  然后 floyd ，最后枚举每个区域到所有人的距离之和，找到那个合适的区域就可以了。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,club[300];
int town[300];
map<int,int> exist;
int dis[300][300];
vector<int> region[300];
void floyd(){
    for(int k=1;k<=m;k++)
    	for(int i=1;i<=m;i++)
    		for(int j=1;j<=m;j++)
    	   		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main(){
    while(scanf("%d",&m)!=EOF){
        int ans=INF,num,temp;
        memset(dis,INF,sizeof(dis));
        for(int i=1;i<=m;i++)dis[i][i]=0;
        exist.clear();
        scanf("%d%d",&n,&num);
        for(int i=0;i<num;i++)scanf("%d",&club[i]);
        for(int i=1;i<=n;i++)region[i].clear();
        for(int area=1,tt;area<=m;area++){
            scanf("%d",&temp);
            for(int i=0;i<temp;i++){
                scanf("%d",&town[i]);
                region[town[i]].push_back(area);
            }
            for(int i=0;i<temp-1;i++){
                if(town[i]<town[i+1])tt=town[i]*1000+town[i+1];
                else tt=town[i+1]*1000+town[i];
                if(exist[tt])dis[exist[tt]][area]=dis[area][exist[tt]]=1;
                else exist[tt]=area;
            }
            if(town[0]<town[temp-1])tt=town[0]*1000+town[temp-1];
            else tt=town[temp-1]*1000+town[0];
            if(exist[tt])dis[exist[tt]][area]=dis[area][exist[tt]]=1;
            else exist[tt]=area;
        }
        floyd();
        for(int i=1,tt=0;i<=m;i++){
            for(int j=0,temp=INF;j<num;j++){
                for(int k=0;k<region[club[j]].size();k++)
					temp=min(temp,dis[region[club[j]][k]][i]);
                tt+=temp;
            }
            ans=min(tt,ans);
        }
        printf("%d\n",ans);
    }
}

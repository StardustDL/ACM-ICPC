/*
Walls
���⣺�� n ��С����������֮����ܴ���һЩǽ������ÿ�������У�����������άƽ��ֳɶ�����򣬵�Ȼ��Щ������һЩ��յĶ���Σ������������һ���������ڣ����ĳ����С���ϵ�����Ҫ�ۻᣬΪѡ���ĸ�����Ϊ�ۻ�ص㣬����ʹ�����������ܹ���Ҫ������ǽ����С����Ŀ����˵��������ĳ�����Ͼۻᣨ�ۻ����ĳ��������ڲ������н������в�����ͼ�еĵ㣨Ҳ���ǳ��������������С�򣩡�
		�������ÿ����������Щ��Χ�� 
��������ͼ���⡣
	  ÿ���˵ĳ�����һ������ĳ����������Σ����������ڻ�֮��Ҫ��ͨ�еĻ�������һ��ǽ�Ϳ���ֱ�ӵ��
	  ��������ڵĻ�����Ҫ�ȴ������������ӵ��������һ�����·ģ�;ͳ����ˡ�
	  ��ÿ�������ɵ㣬��������֮��ľ���Ϊ�߽�ͼ�����ڻ�֮�����Ϊ 1 �������ڵ�����Ϊ�����
	  Ȼ�� floyd �����ö��ÿ�����������˵ľ���֮�ͣ��ҵ��Ǹ����ʵ�����Ϳ����ˡ�
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

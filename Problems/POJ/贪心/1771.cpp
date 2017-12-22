/*
Elevator Stopping Plan 
题意：N个人要到f1,f2...fn层楼，已知电梯每升一层要4秒，到某一层要停留10秒，人爬楼梯上一层要20秒。求出所有人都到达自己想去的楼层的最短时间。
分析：二分+贪心。对时间二分，贪心的判断在这固定的时间内是否能让所有人到达自己想去的楼层。贪心的判断就是让电梯尽可能的往上跑，以给要到较高楼层的人节省中间停留时间，而让时间比较充裕的到较低层的人尽可能多走楼梯，从而让总体时间最小。
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int fl[33],n,Ans;
vector<int> ans;
vector<int> temp;
bool check(int time){
	temp.clear(); 
    int pos=1,curt=0,tmp;
    for(int i=1;i<=n;i++){
        if(fl[i]<=pos||curt+(fl[i]-pos)*20<=time)continue;
        tmp=(time-curt+4*pos+20*fl[i]-(pos!=1?10:0))/24;//剩余时间能爬到哪里 
        if(tmp<fl[i])return false;
		curt+=(tmp-pos)*4+(pos!=1?10:0);
		pos=tmp;
		temp.push_back(pos);
    }
    return true;
}
int main(){
    int st,ed;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)scanf("%d",&fl[i]);
        Ans=fl[n]*4+20*(fl[n]-fl[1]);
        int l=0,r=Ans-1,mid;
        while(l<r){
        	mid=(l+r)>>1;
        	if(check(mid)){
        		Ans=mid,ans=temp; 
        		r=mid;
			}
			else l=mid+1;
		}
		printf("%d\n%d ",Ans,ans.size());
        for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);puts("");
    }
    return 0;
}



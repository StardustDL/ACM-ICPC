
/*
Elevator Stopping Plan 
题意：N个人要到f1,f2...fn层楼，已知电梯每升一层要4秒，到某一层要停留10秒，人爬楼梯上一层要20秒。求出所有人都到达自己想去的楼层的最短时间。
分析：二分+贪心。对时间二分，贪心的判断在这固定的时间内是否能让所有人到达自己想去的楼层。贪心的判断就是让电梯尽可能的往上跑，以给要到较高楼层的人节省中间停留时间，而让时间比较充裕的到较低层的人尽可能多走楼梯，从而让总体时间最小。
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int fl[30010],n;
bool OK(int time){
    int pos=1,curt=0,tmp;
    bool mark=false;
    for(int i=0;i<n;i++){
        if((fl[i]-pos)*20+curt>time){//步行不可行 
            if(mark)curt+=10;
            if((fl[i]-pos)*4+curt>time)return false;
            for(tmp=fl[i];(tmp-pos)*4+(tmp-fl[i])*20+curt<=time;tmp++);//尽量向上走，直到走到必须要停 
            tmp--;
            curt+=(tmp-pos)*4;
            pos=tmp;mark=true;
        }
    }
    return true;
}
int main(){
    int st,ed;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++)scanf("%d",&fl[i]);
        st=(fl[0]-1)*4-1;
        ed=(fl[n-1]-1)*20;
        while(ed-st>1){
            int m=(st+ed)>>1;
            if(OK(m))ed=m;
            else st=m;
        }
        printf("%d\n",ed);
    }
    return 0;
}



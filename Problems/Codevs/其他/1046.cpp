/*
旅行家的预算
分析：贪心
	  1.如果在能到达的加油站中，油费有比当前加油站便宜的，就到一个距离最近且油费比当前加油站便宜的加油站去，在当前加油站加上刚好能到那个加油站的油，使到达加油站时油用光。
	  2.如果在能到达的加油站中，油费没有比当前加油站便宜的，那就在此加油站加满油，然后开到能到达的加油站中油费最小的加油站去。
	  一直循环下去，当能到达终点了，并且后面的站中油费没有更小的了，这就是最终答案。
	  当找不到加油站了，即无解。 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
double d1,c,d2,p,n,i[22],dis[22],pi[22],x[22],shen[22],h,flag,len,sum;
int j,k;
double go(){
	len = c*d2;
	shen[0] = 0;
	for( k = 0; k <= n;){
		j = k + 1;
        if(dis[j] - dis[k] > len) return 0;
        while(dis[j] - dis[k] <= len && j <= n){
            if(pi[j] < pi[k])break;
            j++;
        }
        if(dis[j] - dis[k] < len){
            if(shen[k]*d2 >= dis[j] - dis[k])
                shen[j] = shen[k] - (dis[j] - dis[k])/d2;
            else
                x[k]=(dis[j] - dis[k])/d2 - shen[k];
        }
        else{
            x[k] = c - shen[k];
            j = k + 1;
            shen[j] = c - (dis[j]-dis[k])/d2;
        }
        k=j;
    }
    sum=0;
    for(int f = 0; f <= n; f++)
        sum += x[f]*pi[f];
    return sum;
}
int first(){
    while(cin>>d1){
        memset(pi,0,sizeof(pi));
        memset(i,0,sizeof(i));
        memset(dis,0,sizeof(dis));
        memset(x,0,sizeof(x));
        flag = 0;
        cin>>c>>d2>>pi[0]>>n;
        for(k = 1; k <= n; k++)cin>>dis[k]>>pi[k];
        dis[k] = d1;
        flag = go();
        if(!flag)cout<<"No Solution"<<endl;
        else{
            cout.setf(ios::fixed);
            cout.precision(2);
            cout<<flag<<endl;
        }
    }
    return 0;
}
int main(){
    first();
    return 0;
}



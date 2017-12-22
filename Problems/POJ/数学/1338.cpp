/*
Ugly Numbers
分析：暴力枚举，每次选最小的 
*/
#include<iostream>
#include<algorithm> 
using namespace std;
const int M=1501;
int ans[M];
int main(){
    int a2=1,a3=1,a5=1,tmp,n;
    ans[1]=1;
    for(int i=2;i<M;i++){
        tmp=min(ans[a2]*2,min(ans[a3]*3,ans[a5]*5));
        ans[i]=tmp;
        if(tmp==ans[a2]*2)++a2;
        if(tmp==ans[a3]*3)++a3;
        if(tmp==ans[a5]*5)++a5;
    }
    while(scanf("%d",&n)&&n)printf("%d\n",ans[n]);
    return 0;
}


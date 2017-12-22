/*
[HAOI2011]problem a
分析：求最多说真话的人数，答案即为n-ans
		设dp[i]表示在前i名中最多有多少人说真话
		dp[i] = max{dp[j-1]+sum[j][i]} 其中sum[j][i]表示名次区间为[j, i]的人数
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
#include<map>
using namespace std;
const int MAXN=100000;
map<pair<int,int>,int> s;
vector<int> q[MAXN+3];
int n,opt[MAXN+3];
int main(){
    scanf("%d",&n);
    for(int i=1,a,b;i<=n;i++){
        scanf("%d%d",&a,&b);
        int l=a+1,r=n-b;//和他相等的人有[a+1..n-b]，如果是真话，他们说的应该一样 
        if(l>r)continue;
        s[make_pair(l,r)]++;
        if(s[make_pair(l,r)]==1)q[r].push_back(l);
    }
    for(int i=1;i<=n;i++){
        opt[i]=opt[i-1];
        for(int j=0;j<q[i].size();j++)
            opt[i]=max(opt[i],opt[q[i][j]-1]+min(i-q[i][j]+1,s[make_pair(q[i][j],i)]));//后面要取min 
    }
    printf("%d\n",n-opt[n]);
    return 0;
}

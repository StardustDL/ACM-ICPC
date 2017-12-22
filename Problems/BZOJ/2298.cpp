/*
[HAOI2011]problem a
�����������˵�滰���������𰸼�Ϊn-ans
		��dp[i]��ʾ��ǰi��������ж�����˵�滰
		dp[i] = max{dp[j-1]+sum[j][i]} ����sum[j][i]��ʾ��������Ϊ[j, i]������
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
        int l=a+1,r=n-b;//������ȵ�����[a+1..n-b]��������滰������˵��Ӧ��һ�� 
        if(l>r)continue;
        s[make_pair(l,r)]++;
        if(s[make_pair(l,r)]==1)q[r].push_back(l);
    }
    for(int i=1;i<=n;i++){
        opt[i]=opt[i-1];
        for(int j=0;j<q[i].size();j++)
            opt[i]=max(opt[i],opt[q[i][j]-1]+min(i-q[i][j]+1,s[make_pair(q[i][j],i)]));//����Ҫȡmin 
    }
    printf("%d\n",n-opt[n]);
    return 0;
}

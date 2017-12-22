/*
[Poi2010]Antisymmetry
分析：首先奇数长度的串是肯定不行的，套用manacher，只处理分隔符部分的，不能统计原数组部分的答案= = 
		还有一种枚举中点，hash+二分 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000+100,INF=0x3f3f3f3f;
int a[MAXN+3],p[MAXN+3],id,mx,l;
char s[MAXN+3];
long long solve(int n){
	int mx=1,id=1;long long ans=0;
    for(int i=1;i<=n;i+=2){
        if(mx>=i)p[i]=min(p[2*id-i],mx-i+1);
        else p[i]=1;
        for(;a[i+p[i]]+a[i-p[i]]==2&&i+p[i]<n&&i-p[i]>0;p[i]++);
        if(i+p[i]-1>=mx){mx=i+p[i]-1;id=i;}
    }
    for(int i=1;i<=n;i+=2)ans+=p[i]/2;
    return ans;
}
int main(){
    scanf("%d",&l);scanf("%s",s);
    for(int i=1;i<=l;i++)a[i*2]=(s[i-1]=='1')?2:0;
    for(int i=1;i<=l;i++)a[i*2-1]=1;a[l*2+1]=1;
    printf("%lld\n",solve(l*2+1));
    return 0;
}

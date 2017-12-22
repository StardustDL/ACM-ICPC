/*
[Usaco2008 Dec]Patting Heads 轻拍牛头
分析：对于每个a[i]，它对于所有ans[j]的贡献为1（j%i=0）
		然后我们可以用一种类似于筛法的方法对每个a[i]进行处理 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100000+3],d[1000000+3],n,ans[1000000+3];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[a[i]]++;
    }
    int mx=*max_element(a+1,a+n+1);
    for(int i=1;i<=mx;i++)
        if(d[i])for(int j=i;j<=mx;j+=i)ans[j]+=d[i];
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[a[i]]-1);
    return 0;
}


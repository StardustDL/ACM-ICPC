/*
[Usaco2008 Dec]Patting Heads ����ţͷ
����������ÿ��a[i]������������ans[j]�Ĺ���Ϊ1��j%i=0��
		Ȼ�����ǿ�����һ��������ɸ���ķ�����ÿ��a[i]���д��� 
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


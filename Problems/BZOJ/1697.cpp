/*
[Usaco2007 Feb]Cow Sortingţ����
������������ת���û������Է����û���һ��ѭ����һ��������С��ȥ�������Ľ�����������һ�֣���ȫ�����С�Ľ������������н������ٽ�����ȥ�����ܸ��� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=10000;
int a[MAXN+3],b[MAXN+3],c[10*MAXN+3],n;//ע��c����ֵ��Χ 
vector<int> g[MAXN+3];
bool vis[MAXN+3];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)c[b[i]]=i;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int id=c[a[i]];
        if(vis[id])continue;
        cnt++;
        do{
        	g[cnt].push_back(b[id]);//Ҳ����д��a[id]����ʵ�Ͳ�һλ ����Ϊ��ѭ�������Բ���� 
        	vis[id]=1;
        	id=c[a[id]];
		}while(!vis[id]);
    }
    long long sum=0;
    for(int i=1;i<=cnt;i++){
        int sz=g[i].size(),mn=*min_element(g[i].begin(),g[i].end());
        for(int j=0;j<sz;j++)sum+=g[i][j];
        sum-=mn;
        sum+=min((sz-1)*mn,(sz-1)*b[1]+2*(b[1]+mn));
    }
    printf("%lld\n",sum);
    return 0;
}

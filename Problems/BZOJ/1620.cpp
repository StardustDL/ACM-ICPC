/*
[Usaco2008 Nov]Time Management ʱ�����
������̰�ģ�ÿ��ʱ�䶼�и����ʱ�䣬��ô���Ǿʹ����� ���ʱ��Ŀ�ʼ��ǰ��
		ÿһ�θ������翪ʼʱ�䣨min(ans, a[i].y)����i�¼���������ʱ�䣩 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1000;
struct thing{
    int t,s;
    bool operator <(const thing &t)const{
         return s<t.s;
    }
}ts[MAXN+3];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&ts[i].t,&ts[i].s);
    sort(ts+1,ts+n+1);
    int ans=ts[n].s;
    for(int i=n;i>=1;i--){
        ans=min(ans,ts[i].s)-ts[i].t; 
    } 
    if(ans<0)puts("-1");
    else printf("%d\n",ans);
    return 0;
}



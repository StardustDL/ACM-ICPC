/*
���⣺����n̨���ԣ���ʼ�������Լ���Ϊ���ġ�Ȼ��һЩѯ�ʣ�E x����x�������Ķ�Զ�� I x y ����һ��x��y�ĳ���Ϊ|x-y|(mod 1000)�ıߣ���ʹ��ԭ��x��Ⱥ������ת�Ƶ�y��Ⱥ�ϡ�
���������鼯��+ά��·������a[x]=a[fa[x]]+a[x] 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=30000;
int fa[MAXN+3],dist[MAXN+3];
int find(int x){
    if(x==fa[x])return x;
    else{
		int fx=find(fa[x]);
        dist[x]+=dist[fa[x]];//%1000;
        return fa[x]=fx;
    }
}
void uniset(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    else{
        fa[fx]=x;
        dist[fx]=dist[x];
        fa[x]=y;
        dist[x]=abs(y-x)%1000;
    }
}
int main(){
	int T;
    for(scanf("%d",&T);T;T--){
        int n,x,y;char s[2];
        scanf("%d",&n);
        for(int i=1;i<=n;i++)fa[i]=i,dist[i]=0;
        while(scanf("%s",s),s[0]!='O'){
            if(s[0]=='E'){
                scanf("%d",&x);
                find(x);
                printf("%d\n",dist[x]);
            }
            else{
                scanf("%d%d",&x,&y);
                uniset(x,y);
            }
        }
    }
    return 0;
}

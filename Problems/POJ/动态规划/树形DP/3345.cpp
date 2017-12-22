/*
Bribing FIPA
���⣺������n�����ӣ�����Ҫ������m������Ϊ��ͶƱ�����������i�����ӵĴ�����val[i]��������Щ���Ӵ��ڴ�����ϵ�����B������A������������AҲ��ζ����ͨ��B��������Щ��ϵ�Ǵ��ݵġ�������СҪ�����Ĵ����Ƕ��٣�
��������������DP����ϱ�����dp[i][j]��ʾ�Ե�i�ڵ�Ϊ�������������Ҫ����j�����ҵ���С���ۡ�
	  dp[u][j+k] = min(dp[u][j+k], val[u], dp[v][k]+dp[u][j])��
	  ����Ҫ��ע��һ�㣬�����ڰ�����k��Ϊ������ʱ������j��ʾ�����б����������໥Ӱ�졣������Ҫ��Ԥ����һ�¡�����֮ǰ�Ľ���浽��һ������
	  Ҳ����ͨ�������ű�������������⣨�������ص�������������е��鷳������Ҫ�ȴ�����������ڵ��� 
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm> 
#include<map>
#include<string>
#include<bitset>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int opt[MAXN+3][MAXN+3],tmp[MAXN+3],num[MAXN+3],val[MAXN+3],n,m;
bitset<MAXN+3> isroot;
void addedge(int u,int v){
	g[u].push_back(v);
}
void dfs(int u){
	//printf("%d:\n",u);
    num[u]=1;
    memset(opt[u],INF,sizeof(opt[u]));
    opt[u][0]=0;
    opt[u][1]=val[u];
    for(int i=0,v;i<g[u].size();i++){
        v=g[u][i];
        //printf("%d,",v);
        dfs(v);
        num[u]+=num[v];
        memcpy(tmp,opt[u],(num[u]+1)*sizeof(int));//Ԥ����opt[u][j]
        for(int j=0;j<=num[u]-num[v];j++)
            for(int k=1;k<=num[v];k++)
                opt[u][j+k]=min(opt[u][j+k],min(val[u],opt[v][k]+tmp[j]));
    }
    //puts("");
}
map<string,int> mp;
string t;
char str[105];
int main(){
    while(gets(str)&&str[0] != '#'){//sscanf()����Ӧ����������ʺϣ���str��Ϊ��������
        sscanf(str,"%d%d",&n,&m);
        mp.clear();isroot=0;
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=1,v,p,q,cnt=0;i<=n;i++){
            cin>>t>>v;
            if(mp.count(t)>0)p=mp[t];
            else p=mp[t]=++cnt;
            val[p]=v;
            while(getchar()!='\n'){
                cin>>t;
                if(mp.count(t)>0)q=mp[t];
            	else q=mp[t]=++cnt;
            	isroot[q]=1;
            	addedge(p,q);
            }
        }
        val[0]=INF;
        for(int i=1;i<=n;i++)if(!isroot[i])addedge(0, i);
        dfs(0);
        printf("%d\n", opt[0][m]);
    }
    return 0;
}

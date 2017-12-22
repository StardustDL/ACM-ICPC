/*
分析：因为转移的优先顺序，所以到达每一个目标的转移过程是一定的。
		f[x][i]表示第x个柱子上有i个盘子，把他们都移动到g[x][i]这个柱子上要花得步数。
		首先考虑i=1，因为操作有优先顺序，因此g[x][1]可以确定，f[x][1]都是1。
		接下来考虑任意的i，那么我们需要把i-1个移动到g[x][i-1]上面去，再把剩下的一个移动到（1+2+3-x-g[x][i-1]）上。
		现在原来在x上的i个处在的两个柱子上，其中一个放了1个盘子，另一个放了i-1个盘子。
		设g[x][i-1]=y，即i-1个盘子所在的柱子是y；1+2+3-x-g[x][i-1]=z，即一个盘所在的柱子是k。
	  分两种情况讨论：
		(1)若g[y][i-1]=z，那么把这i-1个直接移到z上转移就完成了。
		g[x][i]=k   f[x][i]=f[x][i-1]+1+f[y][i-1]

		(2)若g[y][i-1]=x，说明不能直接从y->z，这种情况要麻烦一些：
		把i-1个从y移动到x上，再把1个从z移动到y上，最后把i-1个从x上移动到y上。
		g[x][i]=y  f[x][i]=f[x][i-1]+1+f[y][i-1]+1+f[x][i-1]
		不过为什么能z->y呢（本来也有这个操作啊）——可以证明，上述策略一定能完成汉诺塔游戏
		答案就是f[1][n]，无论g[1][n]，因为“目标是柱子A移动到柱子B或柱子C上面” 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
int vis[5],g[5][50],n; 
LL f[5][50];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=6;i++){  
        char s[5];  
        scanf("%s",s);  
        int from=s[0]-'A'+1,to=s[1]-'A'+1;  
        if(vis[from])continue;  
        vis[from]=1;  
        g[from][1]=to,f[from][1]=1;  
    } 
    for(int i=2;i<=n;i++){
    	for(int x=1;x<=3;x++){
    		int y=g[x][i-1],z=6-x-y;
    		f[x][i]=f[x][i-1]+1;//i-1移动到y,1移动到z 
    		if(g[y][i-1]==z)f[x][i]+=f[y][i-1],g[x][i]=z;//g[y][i-1]==z 
			else f[x][i]+=f[y][i-1]+1+f[x][i-1],g[x][i]=y;//g[y][i-1]==x
		}
	}
	printf("%lld\n",f[1][n]);
	return 0;
}


/*
[POI2008]KUP
分析：这道题应该是权值非负吧，不然好像没办法做。
	  首先考虑1*n的情况
		如果存在[k,2k]之间的点，直接输出
		否则如果存在一个区间满足和>=k且任意元素<k 则有解 否则无解
		这个很显然 因为区间内所有元素都<k 因此前缀和不会跨越[k,2k]直接到达(2k,+∞)
		那么我们把这个结论扩展到二维 也是对的
		证明：如果存在一个子矩形满足和>=k且所有元素<k，那么：
		如果这个子矩形的和<=2k，那么满足条件直接输出
		否则这个子矩形的和一定>2k
		下面讨论：
		如果这个子矩形只有一行，那么同上面那种情况
		否则我们取这个矩阵最上方的一行和最下方的一行
		易知一定存在一行的和<=整个矩形的和的一半
		那么我们把这一行砍掉 由于整个矩形的和>2k 因此砍掉后矩形的和一定>k
		这样无限砍下去，总有一时刻矩形的和会<=2k，此时直接输出即可

		将>2k的点判断为坏点，用悬线法/单调队列搞出所有的极大子矩形，依次判断即可
		时间复杂度O(n^2) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3],n,K,h[MAXN+3],sum[MAXN+3][MAXN+3];
long long getsum(int x1,int y1,int x2,int y2){  
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];  
}
void output(int x1,int y1,int x2,int y2){  
    while(getsum(x1,y1,x2,y2)>K*2){  
        if(x1==x2)y2--;  
        else{  
            if(getsum(x1+1,y1,x2,y2)>=K)x1++;  
            else x2--;
        }
    }  
    printf("%d %d %d %d\n",y1,x1,y2,x2);
    exit(0);
}  
void getmax(int base){
	static int sta[MAXN+3],top,l[MAXN+3],r[MAXN+3],i;//计算每个位置i向左向右保持h[i] 高度的最长区间 
	for(top=0,i=1;i<=n+1;i++){
		while(top && h[sta[top]]>h[i])r[sta[top--]]=i-1;
		sta[++top]=i;
	}
	for(top=0,i=n;~i;i--){
		while(top && h[sta[top]]>h[i])l[sta[top--]]=i+1;
		sta[++top]=i;
	}
	for(i=1;i<=n;i++)
		if(h[i]){  
            if(getsum(base-h[i]+1,l[i],base,r[i])>=K)output(base-h[i]+1,l[i],base,r[i]);  
        }
}
int main(){
	scanf("%d%d",&K,&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		scanf("%d",&mp[i][j]);
		if(mp[i][j]>=K && mp[i][j]<=K*2){
			printf("%d %d %d %d\n",j,i,j,i);  
			return 0;
		}
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)h[j]=mp[i][j]>K*2?0:h[j]+1;
		getmax(i);
	}
	puts("NIE");
	return 0;
}


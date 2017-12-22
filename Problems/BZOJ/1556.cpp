/*
分析：注意机关墙数量少，状压。
		 f(s,r,c,dir)表示当且已经触碰到的开关的集合为s，DP位于r行c列，朝向为dir的停下来的次数。当然，细细分析，状态中只有机关周围的四个格子是有用的，状态可简化为f(s,t,dir)，表示DP位于第t个机关的dir方向。转移只需要枚举上一次从哪个点过来即可。这需要预处理出任意两个位于机关四周的点之间的距离。 
		 直接BFS的话，要注意bfs的队列中需要保证前面的状态的停留次数不多于后面的，就可以保证一定可以搜到最优解了，要实时更新已经push到队列中的状态。
		 如果spfa的话就无所谓了 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define p(x,y) (x-1)*4+y+1
const int INF=0x3f3f3f3f; 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char ch[105];
int bin[20];
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int n,m,T,ed,bx,by;
int x[25],y[25];
int f[65536][65],dis[65][65],d[105][105][5];
int qx[200005],qy[200005];
bool inq[105][105],rock[105][105];
void bfs(int bx,int by,int id){
	if(rock[bx][by]||bx<1||by<1||bx>n||by>m)return;	
	memset(d,127/3,sizeof(d));
	qx[0]=bx;qy[0]=by;inq[bx][by]=1;
	for(int k=0;k<4;k++)d[bx][by][k]=0;
	int head=0,tail=1;
	while(head!=tail){
		int x=qx[head],y=qy[head];head++;
		for(int k=0;k<4;k++){
			int nowx=x+xx[k],nowy=y+yy[k];
			if(rock[nowx][nowy]||nowx<1||nowy<1||nowx>n||nowy>m)continue;
			for(int b=0;b<4;b++)
				if(d[x][y][k]+(k!=b)<d[nowx][nowy][b]){
					d[nowx][nowy][b]=d[x][y][k]+(k!=b);//加上是否需要调整方向 
					if(!inq[nowx][nowy]){
						inq[nowx][nowy]=1;
						qx[tail]=nowx;qy[tail]=nowy;
						tail++;
					}
				}
		}
		inq[x][y]=0;
	}
	for(int i=1;i<=T;i++)
		for(int k=0;k<4;k++){
			int t=INF,tx=x[i]+xx[k],ty=y[i]+yy[k];
			for(int l=0;l<4;l++)
				t=min(t,d[tx][ty][l]+(tx+xx[l]!=x[i]||ty+yy[l]!=y[i]));//加上是否需要调整方向 
			dis[id][p(i,k)]=t;
		}
}
int ans=INF;
void dp(){
	for(int i=0;i<=ed;i++)
		for(int x=1;x<=4*T+1;x++)f[i][x]=INF;
	f[0][4*T+1]=0;
	for(int i=0;i<=ed;i++)
		for(int x=1;x<=4*T+1;x++)
			if(f[i][x]!=INF)
				for(int y=1;y<=4*T;y++){
					int t=i|bin[(y-1)/4];
					f[t][y]=min(f[t][y],f[i][x]+dis[x][y]+1);//先得转一个向，才能走，因为这时一定是撞机关墙了 
				}
	for(int x=1;x<=4*T;x++)ans=min(ans,f[ed][x]);
}
int main(){
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	memset(dis,127/3,sizeof(dis));
	n=read();m=read();T=read();
	ed=bin[T]-1;
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=m;j++)
			if(ch[j]=='#')rock[i][j]=-1;
	}
	for(int i=1;i<=T;i++)
		x[i]=read(),y[i]=read();
	for(int i=1;i<=T;i++)
		for(int k=0;k<4;k++)
			bfs(x[i]+xx[k],y[i]+yy[k],p(i,k));
	bx=read();by=read();
	bfs(bx,by,4*T+1);
	dp();
	printf("%d\n",ans);
	return 0;
}

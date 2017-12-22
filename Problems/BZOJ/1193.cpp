/*
[HNOI2006]马步距离
分析：这题其实有规律。如果对棋盘进行黑白染色，显然走奇数步只能走到与起点异色的点，偶数步只能走到同色点。
		假设走x步，那么终点到起点的曼哈顿距离应<=3x，且起点与终点的横坐标之差与纵坐标之差都应<=2x。
		那么一路枚举下去即可。
		但是对于5*5的图中，离出发点最近的几个点却需要3-4步，这个在枚举中会出错（得到1，2）
		特判一下即可 
	  或者可以大范围贪心，小范围bfs 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath> 
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int xp,yp,xs,ys,d,a,b,ans=0; 
int main(){
	scanf("%d%d%d%d",&xp,&yp,&xs,&ys);
	d=(a=abs(xp-xs))+(b=abs(yp-ys));
	for(ans=0;;ans++){
		if(((xp+yp&1)^(xs+ys&1))!=(ans&1))continue;//判断点的颜色能否走到 
		if(d<=ans*3&&a<=ans*2&&b<=ans*2)break;
	}
	//cout<<ans<<endl;
	if(d==1)ans=3;
	else if(d==4&&a==2&&b==2)ans=4;
	printf("%d\n",ans); 
	return 0;
}


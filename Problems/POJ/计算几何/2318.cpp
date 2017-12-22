/*
TOYS
题意：给定一个长方形箱子，中间有n条线段，将其分为n+1个区域，给定m个玩具的坐标，统计每个区域中的玩具个数。 
分析：对每个玩具，二分线段下标，判断在线段左边还是右边，找到之后进行统计即可
	  判断在左边还是在右边有两种方法：叉积的正负，或另一个，没有懂，见代码
	  注意在一条线段的左边，是右指针左移 
	  这种方法不好，最好把直线用两个点表示，而不采用方向向量，因为方向向量的方向直接影响左边还是右边，还要加判断，至于为什么过了。。数据水吗？
	  引用：确定连续线段是向左转还是向右转
		对于线段p0p1和p1p2，采用叉积可以避免计算角度，只需简单的计算一下p0p2是位于p0p1的顺时针还是逆时针方向。计算叉积
		(p2-p0)×(p1-p0) = (x2-x0)(y1-y0) - (x1-x0)(y2-y0)
		若结果为负，p0p2在p0p1的逆时针方向，在p1处左转；结果为正则右转；为0表示三点共线。 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5000;
struct Point{
	double x,y;
	
	Point(){};
	
	Point(double a,double b){x=a,y=b;}
	
	Point operator - (const Point &t)const{
		return Point(x-t.x,y-t.y);
	}
	
	Point operator + (const Point &t)const{
		return Point(x+t.x,y+t.y);
	}
};
typedef Point Vector;
double Cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}
struct Line{
	Point p;Vector v;
};
int n,m,x1,x2,y1,y2,cnt[MAXN+3];
Line ls[MAXN+3];Point ps[MAXN+3];
bool input(){
	cin>>n;if(n==0)return false;
	cin>>m>>x1>>y1>>x2>>y2;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		ls[i].p=Point(x,y1);
		ls[i].v=Point(y,y2)-Point(x,y1);
		//这里是y2-y1，所以Isleft中叉积<0，若此处为y1-y2，且起点为y2，Isleft中叉积就为>0，因为叉积表示左右要考虑向量的方向 
	}
	for(int i=1;i<=m;i++)cin>>ps[i].x>>ps[i].y;
	return true;
}
bool Isleft(Point p,Line l){
	return Cross(l.v,p-l.p)<0;//小于0为在左侧，即l.v逆时针旋转得到(p-l.p)，因为向量是从上方指向下方的 
}
int get(Point p){
	int l=0,r=n-1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(Isleft(p,ls[mid]))r=mid;
		else l=mid+1;
	}
	if(Isleft(p,ls[l]))return l;
	else return l+1;
}
/*
int Multi(Point p1, Point p2, Point p0) {  
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);  
}
int get(Point p){
	int l=0,r=n-1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(Multi(p,ls[mid].p,ls[mid].p+ls[mid].v)<0)r=mid;
		else l=mid+1;
	}
	if(Multi(p,ls[l].p,ls[l].p+ls[l].v)<0)return l;
	else return l+1;
}*/
void solve(){
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=m;i++){
		cnt[get(ps[i])]++;
	}
	for(int i=0;i<=n;i++)cout<<i<<": "<<cnt[i]<<endl;
	cout<<endl;
}
int main(){
	while(input())solve();
	return 0;
}

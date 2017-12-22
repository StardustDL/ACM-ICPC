/*
[SCOI2003]切割多边形
分析：P很小，暴力枚举排列，注意相邻两直线不要平行 ，注意题中其实已经给了最终凸包的信息了。 
		用了next_permutation慢了= = 
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-6;
const int MAXP=10;
int dcmp(double t){return (fabs(t) <= eps)?0:(t<0?-1:1);}
int n, m, p;
struct Point{
    double x, y;
    Point(double _x = 0, double _y = 0): x(_x), y(_y) {}
    Point operator - (const Point &b)const{return Point(x-b.x,y-b.y);}
	Point operator + (const Point &b)const{return Point(x+b.x,y+b.y);}
	bool operator == (const Point &b)const{return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;}
	double operator * (const Point &b)const{return x*b.y-y*b.x;}
	Point operator *(const double b)const{return Point(x*b,y*b);}
	double operator / (const Point &b)const{return x*b.x+y*b.y;}
} a[MAXP], center;
bool cmp(const Point &a0, const Point &b0){//围绕中心点极角排序
    Point a = a0-center,b=b0-center;
    return dcmp(atan2(a.y, a.x)-atan2(b.y, b.x)) < 0; 
}
#define parallel(a,b) (dcmp(a*b)==0)
#define sqr(x) ((x)*(x))
inline double length(const Point &a){return sqrt(sqr(a.x)+sqr(a.y));}
struct Line{
    Point p,v;
    Line() {}
    Line(Point _p, Point _v): p(_p), v(_v) {}
} l[MAXP];
Point intersect(const Line &a, const Line &b){
    double temp=(b.v*(a.p-b.p))/(a.v*b.v);
    return a.p+a.v*temp;
}
bool inhalf(const Point &p, const Line &l){return dcmp(l.v*(p - l.p))>=0;}//在半平面一侧（左侧，逆时针） 
bool inrec(const Point &a){return dcmp(a.x) >= 0 && dcmp(a.y) >= 0 && dcmp(a.x-n) <= 0 && dcmp(a.y-m) <= 0;}//在大矩形中
Point tmp[4];Line lst[4];
Line inrec(const Line &l){//截取一条直线在大矩形中的部分，注意l实际是一条线段l.p~(l.p+l.v) 
    if(dcmp(l.v.x)==0)return Line(Point(l.p.x, 0), Point(0, m));
    if(dcmp(l.v.y)==0)return Line(Point(0, l.p.y), Point(n, 0));
    bool hv = false;
    Point p;
    for(int i=0;i<4;i++){//求出与边界的交点 
    	tmp[i]=intersect(l,lst[i]);
    	if(inrec(tmp[i])){
    		if(hv&& (!(p==tmp[i])))return Line(p,tmp[i]-p);//注意判一下p=tmp[i]的情况，就是tmp[i]=(0,0)的情况，不然会WA 
			hv=1;p=tmp[i];
		}
	}
    return Line(p,tmp[3]-p);
}
double ans = 1e300;
int f[MAXP];
int main(){
    scanf("%d%d%d", &n, &m, &p);
    lst[0]=Line(Point(0,0),Point(n,0));
    lst[1]=Line(Point(0,0),Point(0,m));
    lst[2]=Line(Point(0,m),Point(n,m)-Point(0,m));
    lst[3]=Line(Point(n,0),Point(n,m)-Point(n,0));
    for (int i=0; i<p; ++i){
        scanf("%lf%lf",&a[i].x,&a[i].y);
        center=center+a[i];
    }
    center.x/=p,center.y/=p;
    sort(a,a+p,cmp);
    for (int i=0; i<p-1;++i)
        l[i]=Line(a[i],a[i+1]-a[i]);
    l[p-1]=Line(a[p-1],a[0]-a[p-1]);
    for(int i=0;i<p;i++)f[i]=i;
	do{
		double temp=0;
		for(int i=0;i<p;i++){
			Line x=inrec(l[f[i]]);
	        for (int j=0;j<i;++j){
	        	Line &y=l[f[j]]; 
	            if(!parallel(y.v, x.v)){
	                Point p=intersect(x,y);
	                if (dcmp((x.p - p)/(x.p + x.v - p)) < 0){//如果l两端点在交点两侧，则必有一端点在答案外 
	                    if(!inhalf(x.p, y))x=Line(p, x.p + x.v - p);
	                    else if (!inhalf(x.p + x.v, y))x = Line(x.p, p - x.p);
	                }
	            }
	        }
	        temp+=length(x.v);
	    }
	    ans=min(ans,temp);
	}while(next_permutation(f,f+p));
    printf("%.3lf\n", ans);
    return 0;
}
/*
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-6;
const int MAXP=10;
int dcmp(double t){return (fabs(t) <= eps)?0:(t<0?-1:1);}
int n, m, p;
struct Point{
    double x, y;
    Point(double _x = 0, double _y = 0): x(_x), y(_y) {}
    Point operator - (const Point &b)const{return Point(x-b.x,y-b.y);}
	Point operator + (const Point &b)const{return Point(x+b.x,y+b.y);}
	bool operator == (const Point &b)const{return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;}
	double operator * (const Point &b)const{return x*b.y-y*b.x;}
	Point operator *(const double b)const{return Point(x*b,y*b);}
	double operator / (const Point &b)const{return x*b.x+y*b.y;}
} a[MAXP], center;
bool cmp(const Point &a0, const Point &b0)
{
    Point a = a0-center,b=b0-center;
    return dcmp(atan2(a.y, a.x)-atan2(b.y, b.x)) < 0;
}
#define parallel(a,b) (dcmp(a*b)==0)
#define sqr(x) ((x)*(x))
inline double length(const Point &a){return sqrt(sqr(a.x)+sqr(a.y));}
struct Line{
    Point p,v;
    Line() {}
    Line(Point _p, Point _v): p(_p), v(_v) {}
} l[MAXP];
Point intersect(const Line &a, const Line &b){
    double temp=(b.v*(a.p-b.p))/(a.v*b.v);
    return a.p+a.v*temp;
}
bool inhalf(const Point &p, const Line &l){return dcmp(l.v*(p - l.p))>=0;}//在半平面一侧（左侧，逆时针） 
bool inrec(const Point &a){return dcmp(a.x) >= 0 && dcmp(a.y) >= 0 && dcmp(a.x-n) <= 0 && dcmp(a.y-m) <= 0;}//在大矩形中
Point tmp[4];Line lst[4];
Line inrec(const Line &l){//截取一条直线在大矩形中的部分 
    if(dcmp(l.v.x)==0)return Line(Point(l.p.x, 0), Point(0, m));
    if(dcmp(l.v.y)==0)return Line(Point(0, l.p.y), Point(n, 0));
    bool hv = false;
    Point p;
    for(int i=0;i<4;i++){
    	tmp[i]=intersect(l,lst[i]);
    	if(inrec(tmp[i])){
    		if(hv&& (!(p==tmp[i])))return Line(p,tmp[i]-p);
			hv=1;p=tmp[i];
		}
	}
    return Line(p,tmp[3]-p);
}
bool v[MAXP] = {0};
double ans = 1e300;
void dfs(int num, double cur){
    if(dcmp(cur-ans)>= 0)return;
    if(num==p){ans=cur;return;}
    for(int i = 0; i < p; ++i){
        if(v[i])continue;
        Line x=inrec(l[i]);
        for (int j=0;j<p;++j)
            if (v[j]&&!parallel(l[j].v, x.v)){
                Point p=intersect(x, l[j]);
                if (dcmp((x.p - p)/(x.p + x.v - p)) < 0){
                    if(!inhalf(x.p, l[j]))x=Line(p, x.p + x.v - p);
                    else if (!inhalf(x.p + x.v, l[j]))x = Line(x.p, p - x.p);
                }
            }
        v[i] = 1;
        dfs(num + 1, cur + length(x.v));
        v[i] = 0;
    }
}
int f[MAXP];
int main(){
    scanf("%d%d%d", &n, &m, &p);
    lst[0]=Line(Point(0,0),Point(n,0));
    lst[1]=Line(Point(0,0),Point(0,m));
    lst[2]=Line(Point(0,m),Point(n,m)-Point(0,m));
    lst[3]=Line(Point(n,0),Point(n,m)-Point(n,0));
    for (int i=0; i<p; ++i){
        scanf("%lf%lf",&a[i].x,&a[i].y);
        center=center+a[i];
    }
    center.x/=p,center.y/=p;
    sort(a,a+p,cmp);
    for (int i=0; i<p-1;++i)
        l[i]=Line(a[i],a[i+1]-a[i]);
    l[p-1]=Line(a[p-1],a[0]-a[p-1]);
    dfs(0, 0);
    printf("%.3lf\n", ans);
    return 0;
}
*/ 

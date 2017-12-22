/*
圆的面积并
分析：对于三次以下多项式函数的定积分，有一个Simpson公式：
		∫[l,r]f(x)=(r-l)(f(l)+f(r)+4f(mid))/6
		公式可以利用导数证明，但是对于三次以上或者其他函数是不成立的；
		比如圆的参数方程，三角函数之类的奇怪东西；
		虽说如此，不成立的时候，也可以利用这个公式来干点什么。。
		利用这个公式来拟合曲线！
		对于一段区间[l,r]，我们求得f(l),f(r),f(mid)；
		然后直接带入公式，就得到了过三个点的二次函数曲线的面积；
		这并不一定是解，但是离解应该也比较接近；
		所以验证一下，再套[l,mid]与[mid,r]的公式，也可以得到一个这个区间的面积；
		如果这两个面积差不多那答案就差不多啦，如果差的很多呢？
		递归计算！
		分别对[l,mid],[mid,r]区间递归算值，一直递归到可以接受的地步；
		这个过程将曲线划分越来越细，然后对每一段拟合一个函数曲线；
		像是一个适应曲线的过程(？)，所以这个算法被称为Simpson自适应法；
		这个算法显然不够完美，比如面对非连续函数几乎无法得到正确结果；
		即使是连续函数也可以构造出很多的神奇数据卡掉算法(BZOJ这道题并没有卡就是了)；
		对策就是在验证以及递归计算的时候随机分段，或者分成多段；
		这样时间效率会慢一些但是被卡的几率降低了很多；
		坑点：EPS要到1e-13，预先将内含于其他圆的圆删掉，不然会T 
*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1100
#define pr pair<double,double>
using namespace std;
const double pi=acos(-1.0);
const double EPS=1e-13;
const double INF=1e100;
struct Point{
	int x,y;
	friend double dis(Point a,Point b){
		return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}
};
struct Circle{
	Point p;
	int r;
	void read(){scanf("%d%d%d",&p.x,&p.y,&r);}
	friend bool operator <(Circle a,Circle b){
		if(a.p.x-a.r<b.p.x-a.r)
			return a.p.x+a.r<b.p.x+a.r;
		return a.p.x-a.r<b.p.x-a.r;
	}
	pr f(double x){
		if(r<=fabs(p.x-x))	return pr(0,0);
		double t=r*r-(p.x-x)*(p.x-x);
		t=sqrt(t);
		return pr(p.y-t,p.y+t);
	}
}O[N];
bool ban[N];
pr p[N];
int n;
double Cut(double x){
	double ret=0,last=-INF;
	int cnt=0;
	for(int i=1;i<=n;i++){
		p[++cnt]=O[i].f(x);
		if(p[cnt]==pr(0,0))cnt--;
	}
	sort(p+1,p+cnt+1);
	for(int i=1;i<=cnt;i++){
		if(p[i].first>last)
			ret+=p[i].second-p[i].first,last=p[i].second;
		else if(p[i].second>last)
			ret+=p[i].second-last,last=p[i].second;
	}
	return ret;
}
double Simpson(double l,double r,double mid,double Cl,double Cr,double Cm){
	double tCl=Cut((l+mid)/2),tCr=Cut((mid+r)/2);
	double ans=(r-l)*(Cl+Cr+4*Cm)/6,
		lans=(mid-l)*(Cl+Cm+4*tCl)/6,
		rans=(r-mid)*(Cr+Cm+4*tCr)/6;
	if(fabs(lans+rans-ans)<EPS)return ans;
	else return 
		Simpson(l,mid,(l+mid)/2,Cl,Cm,tCl)
		+Simpson(mid,r,(mid+r)/2,Cm,Cr,tCr);
}
int main(){
	double l,r;
	scanf("%d",&n);
	l=INF,r=-INF;
	for(int i=1;i<=n;i++){
		O[i].read();
		l=min(l,(double)O[i].p.x-O[i].r);
		r=max(r,(double)O[i].p.x+O[i].r);
	}
	sort(O+1,O+n+1);
	for(int i=1;i<=n;i++){
		if(ban[i])continue;
		for(int j=i+1;j<=n;j++){
			if(ban[j])continue;
			if(dis(O[i].p,O[j].p)+O[j].r<=O[i].r)ban[j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!ban[i])continue;
		swap(ban[i],ban[n]);
		swap(O[i--],O[n--]);
	}
	printf("%.3lf\n",Simpson(l,r,(l+r)/2,0,0,Cut((l+r)/2)));
	return 0;
}


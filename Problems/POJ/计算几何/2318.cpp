/*
TOYS
���⣺����һ�����������ӣ��м���n���߶Σ������Ϊn+1�����򣬸���m����ߵ����꣬ͳ��ÿ�������е���߸����� 
��������ÿ����ߣ������߶��±꣬�ж����߶���߻����ұߣ��ҵ�֮�����ͳ�Ƽ���
	  �ж�����߻������ұ������ַ��������������������һ����û�ж���������
	  ע����һ���߶ε���ߣ�����ָ������ 
	  ���ַ������ã���ð�ֱ�����������ʾ���������÷�����������Ϊ���������ķ���ֱ��Ӱ����߻����ұߣ���Ҫ���жϣ�����Ϊʲô���ˡ�������ˮ��
	  ���ã�ȷ�������߶�������ת��������ת
		�����߶�p0p1��p1p2�����ò�����Ա������Ƕȣ�ֻ��򵥵ļ���һ��p0p2��λ��p0p1��˳ʱ�뻹����ʱ�뷽�򡣼�����
		(p2-p0)��(p1-p0) = (x2-x0)(y1-y0) - (x1-x0)(y2-y0)
		�����Ϊ����p0p2��p0p1����ʱ�뷽����p1����ת�����Ϊ������ת��Ϊ0��ʾ���㹲�ߡ� 
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
		//������y2-y1������Isleft�в��<0�����˴�Ϊy1-y2�������Ϊy2��Isleft�в����Ϊ>0����Ϊ�����ʾ����Ҫ���������ķ��� 
	}
	for(int i=1;i<=m;i++)cin>>ps[i].x>>ps[i].y;
	return true;
}
bool Isleft(Point p,Line l){
	return Cross(l.v,p-l.p)<0;//С��0Ϊ����࣬��l.v��ʱ����ת�õ�(p-l.p)����Ϊ�����Ǵ��Ϸ�ָ���·��� 
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

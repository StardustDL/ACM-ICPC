/*
[SCOI2007]����������
���������ȴ�һ����͹���ϡ�
	  Ȼ�����ö��͹���ϵĶԽ��ߣ�ά���Խ������ߵ�ָ�루��ʵָ���ֵ�����������ߣ�һ����ö�ٵ��������Է��֣����ŶԽ��ߵ���ת��������ʹ�������ָ��Ҳ�ǵ����ġ�
	  ��ת���ǡ�������д���ܼ�࣬���Ե���ģ�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &t)const{
		return Point(x+t.x,y+t.y);
	}
	Point operator -(const Point &t)const{
		return Point(x-t.x,y-t.y);
	}
	Point operator *(const double d)const{
		return Point(x*d,y*d);
	}
	double operator *(const Point &t)const{
		return x*t.x+y*t.y;
	}
	double operator ^(const Point &t)const{
		return x*t.y-t.x*y; 
	}
	bool operator <(const Point &t)const{
		return x==t.x?y<t.y:x<t.x;
	}
}pt[MAXN+3];
int bag[MAXN+3],tmp[MAXN+3],top=-1,tp=0,n;
double max_S(){
	double ans=0;
	for(int i=0;i<top;i++){
		int p=1,q=1;
		for(int j=i+2;j<top;j++){
			while(((pt[bag[p+1]]-pt[bag[i]])^(pt[bag[j]]-pt[bag[i]]))
					> ((pt[bag[p]]-pt[bag[i]])^(pt[bag[j]]-pt[bag[i]])))p=(p+1)%top;
			while(((pt[bag[q+1]]-pt[bag[i]])^(pt[bag[j]]-pt[bag[i]]))
					< ((pt[bag[q]]-pt[bag[i]])^(pt[bag[j]]-pt[bag[i]])))q=(q+1)%top;
			ans=max(ans,((pt[bag[p]]-pt[bag[i]])^(pt[bag[j]]-pt[bag[i]])) - ((pt[bag[q]]-pt[bag[i]])^(pt[bag[j]]-pt[bag[i]])));
		}
	}
	return ans;
}
void get_bag(){
	sort(pt+1,pt+n+1);top=-1;tp=0;
	for(int i=1;i<=n;i++){
		while(tp>1&&( ((pt[i]-pt[tmp[tp]])^(pt[tmp[tp]]-pt[tmp[tp-1]])) >=0))tp--;
		tmp[++tp]=i;
	}
	for(int i=1;i<tp;i++)bag[++top]=tmp[i]; //��Ҫ�����һ�����ϣ���������ͻ��ظ��� 
	tp=0;
	for(int i=1;i<=n;i++){
		while(tp>1&&( ((pt[i]-pt[tmp[tp]])^(pt[tmp[tp]]-pt[tmp[tp-1]])) <=0))tp--;
		tmp[++tp]=i;
	}
	for(int i=tp;i>=1;i--)bag[++top]=tmp[i]; //����ɨ 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&pt[i].x,&pt[i].y);
	get_bag();
	printf("%.3lf\n",max_S()/2.0);
	return 0;
}


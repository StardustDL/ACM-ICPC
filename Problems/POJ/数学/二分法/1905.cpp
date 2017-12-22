/*
Expanding Rods
题意：一根两端固定在两面墙上的杆 受热弯曲后变弯曲，求前后两个状态的杆的中点位置的距离，其实对应到圆上就是R-弦心距
分析：列方程，然后得到L'与Ans的关系式（然而这个式子并不好求），所以二分Ans，判断由此得到的L''与真实L'(= (1+n*C)*L)的大小关系 
	  下界自然是0 (不弯曲)，关键确定上界，注意题目：数据要保证没有一条杆能够延伸超过其初始长度的一半，则有MAXL'=3/2L，进而能求出h的上届 
	  为保证答案正确，稍放宽上界， 取H=0.5L
	  注意精度 
*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double esp=1e-5;
int main(){
	double L,n,c,s,h,r;//L:杆长,n:温度改变度,c:热力系数,s:延展后的杆长（弧长）,h:延展后的杆中心到延展前杆中心的距离,r:s所在圆的半径
	while(cin>>L>>n>>c){
		if(L<0&&n<0&&c<0)break;
		double low=0.0,high=0.5*L,mid;
		s=(1+n*c)*L;
		while(high-low>esp){//由于都是double，不能用low<high，否则会陷入死循环，必须限制low与high的精度差 
			mid=(low+high)/2;
			r=(4*mid*mid+L*L)/(8*mid);
			if(2*r*asin(L/(2*r))<s)low=mid;//h偏小
			else high=mid;//h偏大
		}
		h=mid;
		cout<<fixed<<setprecision(3)<<h<<endl;
	}
	return 0;
}

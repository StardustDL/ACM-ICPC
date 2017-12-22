/*
Expanding Rods
���⣺һ�����˹̶�������ǽ�ϵĸ� �������������������ǰ������״̬�ĸ˵��е�λ�õľ��룬��ʵ��Ӧ��Բ�Ͼ���R-���ľ�
�������з��̣�Ȼ��õ�L'��Ans�Ĺ�ϵʽ��Ȼ�����ʽ�Ӳ������󣩣����Զ���Ans���ж��ɴ˵õ���L''����ʵL'(= (1+n*C)*L)�Ĵ�С��ϵ 
	  �½���Ȼ��0 (������)���ؼ�ȷ���Ͻ磬ע����Ŀ������Ҫ��֤û��һ�����ܹ����쳬�����ʼ���ȵ�һ�룬����MAXL'=3/2L�����������h���Ͻ� 
	  Ϊ��֤����ȷ���Էſ��Ͻ磬 ȡH=0.5L
	  ע�⾫�� 
*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double esp=1e-5;
int main(){
	double L,n,c,s,h,r;//L:�˳�,n:�¶ȸı��,c:����ϵ��,s:��չ��ĸ˳���������,h:��չ��ĸ����ĵ���չǰ�����ĵľ���,r:s����Բ�İ뾶
	while(cin>>L>>n>>c){
		if(L<0&&n<0&&c<0)break;
		double low=0.0,high=0.5*L,mid;
		s=(1+n*c)*L;
		while(high-low>esp){//���ڶ���double��������low<high�������������ѭ������������low��high�ľ��Ȳ� 
			mid=(low+high)/2;
			r=(4*mid*mid+L*L)/(8*mid);
			if(2*r*asin(L/(2*r))<s)low=mid;//hƫС
			else high=mid;//hƫ��
		}
		h=mid;
		cout<<fixed<<setprecision(3)<<h<<endl;
	}
	return 0;
}

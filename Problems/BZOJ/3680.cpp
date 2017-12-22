/*
吊打XXX
分析：设桌子的高度为h0，每根绳子长l0[i]，在座子上的长度为a[i]，那么E=Σw[i]*(h0-l0[i])+Σw[i]*a[i]
		只要最小化Σw[i]*a[i]即可，所以问题转化为广义费马点。那么就模拟退火吧。 
		爬山算法是一种简单的贪心搜索算法，该算法每次从当前解的临近解空间中选择一个最优解作为当前解，直到达到一个局部最优解。
	  	模拟退火算法以一定的概率来接受一个比当前解要差的解，因此有可能会跳出这个局部的最优解，达到全局的最优解。以图1为例，模拟退火算法在搜索到局部最优解A后，会以一定的概率接受到E的移动。也许经过几次这样的不是局部最优的移动后会到达D点，于是就跳出了局部最大值A。
         模拟退火算法描述：
         若J( Y(i+1) )>= J( Y(i) )  (即移动后得到更优解)，则总是接受该移动
         若J( Y(i+1) )< J( Y(i) )  (即移动后的解比当前解要差)，则以一定的概率接受移动，而且这个概率随着时间推移逐渐降低（逐渐降低才能趋向稳定）
	　　这里的“一定的概率”的计算参考了金属冶炼的退火过程，这也是模拟退火算法名称的由来。
		根据热力学的原理，在温度为T时，出现能量差为dE的降温的概率为P(dE)，表示为：
		P(dE) = exp( dE/(kT) )=e^( dE/(kT) ) 其中k是一个常数，exp表示自然指数，且dE<0。这条公式说白了就是：温度越高，出现一次能量差为dE的降温的概率就越大；温度越低，则出现降温的概率就越小。又由于dE总是小于0（否则就不叫退火了），因此dE/kT < 0 ，所以P(dE)的函数取值范围是(0,1) 。
		随着温度T的降低，P(dE)会逐渐降低。
		我们将一次向较差解的移动看做一次温度跳变过程，我们以概率P(dE)来接受这样的移动。 
		算法中维护T值即可
			* J(y)：在状态y时的评价函数值
			* Y(i)：表示当前状态
			* Y(i+1)：表示新的状态
			* r： 用于控制降温的快慢
			* T： 系统的温度，系统初始应该要处于一个高温的状态
			* T_min ：温度的下限，若温度T达到T_min，则停止搜索
			while( T > T_min ){
			　　dE = J( Y(i+1) ) - J( Y(i) ) ; 
			　　if ( dE >=0 )Y(i+1) = Y(i) ; //如果移动后得到更优解，则总是接受移动
			　　else{
					if ( exp( dE/T ) > random( 0 , 1 ) )// 函数exp( dE/T )的取值范围是(0,1) ，dE/T越大，则exp( dE/T )也越大
						Y(i+1) = Y(i) ; //接受从Y(i)到Y(i+1)的移动
			　　}
			　　T = r * T ; //降温退火 ，0<r<1 。r越大，降温越慢；r越小，降温越快。若r过大，则搜索到全局最优解的可能会较高，但搜索的过程也就较长。若r过小，则搜索的过程会很快，但最终可能会达到一个局部最优值
			　　i ++ ;
			} 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double ansx,ansy;
struct data{double x,y;int w;}p[10005];
#define sqr(x) ((x)*(x))
inline double dis(double x,double y,data p){return sqrt(sqr(x-p.x)+sqr(y-p.y));}
void solve(){
	double t=1000,x,y;//t维护接受解的程度，它满足先下降，然后逐步稳定在一个值 
    for(int i=1;i<=n;i++)
        ansx+=p[i].x*p[i].w,ansy+=p[i].y*p[i].w;
    ansx/=n;ansy/=n;//计算初始位置（横纵坐标加权平均） 
    while(t>0.00000001){
        x=y=0;
        for(int i=1;i<=n;i++){//计算x,y方向上的受力 
            x+=(p[i].x-ansx)*p[i].w/dis(ansx,ansy,p[i]);
            y+=(p[i].y-ansy)*p[i].w/dis(ansx,ansy,p[i]);
        }
        ansx+=x*t;ansy+=y*t;//接受t程度的解 
        if(t>0.5)t*=0.5;//使t先下降，然后维持 
        else t*=0.97;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf%d",&p[i].x,&p[i].y,&p[i].w);
    solve();
    printf("%.3lf %.3lf",ansx,ansy);
    return 0;
}

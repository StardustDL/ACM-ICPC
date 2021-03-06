/*
Chocolate
题意：c种巧克力，每种数量无穷大，取出n个放桌上，如果出现同种巧克力的就必须吃掉，即桌面上同种巧克力只能有0个或者1个。问取出n个后剩余m种巧克力的概率。
分析：状态 dp( i, j ) 表示 拿出i块巧克力，桌面上剩余j块的概率
	  若再拿出一块巧克力，则可能出现两种情况
	  一，一种是，从 桌面已出现的 J 种取 一种，然后被吃掉，则桌面总数量减少1，得到状态 dp（I+1，J-1），概率为 DP（I，J）*J/C，
	  二，一种是，从 桌面上未出现的C-J种取 一种，然后桌面数量增加一个，得到状态DP（I+1，J+1），概率为DP（I，J）*（C-J）/C
	  注意到 第一种情形出现的条件是 J-1 >= 0 ,第二种出现条件为 J+1 <= C
	  另外，我们知道当 M>C ，以及 M，N奇偶性不同时，概率必定为0.
	  但是这样过不去。。。网上说n>1000就奇数=1001，偶数=1000 。因为输出只要求小数点后三位，猜想,当n很大时误差可以忽略不计。猜想n>1000时，直接将n取1000或者1001即可。当n无穷大时，就是样本无穷多，此时概率收敛为一个稳定值也是可以理解的。 
	  注：上面的转移方程可以调一下形式变为opt[i][j]=A+B 
	  注意N很大，用滚动数组 
	  关于证明：引用自POJDiscuss：
	  	这就是个典型的markov链：q(t+1)=P*q(t) -> q(n)=(P^n)*q(0)=Q'*D^n*Q*q(0)
		P包含1、-1以及其他绝对值小于1的特征值，所以D的偶次方和奇次方会分别收敛到不同对角阵
		所以n要区分奇偶，n的上界可以这么估计：c=100的时候，可以得到绝对值小于1且最大的特征值0.98，那么由0.98^n<0.001可得n>342 
*/
#include<cstdio> 
#include<cstring>
using namespace std;
const int MAXC=100;
double opt[2][MAXC+3];
int c,n,m;
int main(){
	while(scanf("%d%d%d",&c,&n,&m),c!=0){
		memset(opt,0,sizeof(opt));
		if(m>c||m>n||(m+n)%2){printf("0.000\n");continue;}
		if(n>1000)n=1000+n%2;
		opt[1][1]=opt[0][0]=1.0;//n=0,m=0时候输出1.000
		for(int i=2;i<=n;i++){
			//两端的赋值，均为1/c的概率 
			opt[i%2][0]=opt[(i-1)%2][1]/c;
			opt[i%2][c]=opt[(i-1)%2][c-1]/c;
			for(int j=1;j<=i&&j<c;j++){
				opt[i%2][j]=
					opt[(i-1)%2][j-1]*(c-(j-1.0))/c
					+opt[(i-1)%2][j+1]*(j+1.0)/c;//此为上述方程变形后的值 
			}
		}
		printf("%.3lf\n",opt[n%2][m]);
	}
	return 0;
}

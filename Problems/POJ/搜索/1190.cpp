/*
生日蛋糕
分析：搜索+剪枝：最优性和可行性，注意只考虑搜索时侧面积即可，因为另外的面积正好是底面积的2倍 
*/
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
int m,n,ans,mins[25],minv[25];;
void dfs(int curf,int lastr,int lasth,int leftv,int sum){//写的多一点就更清楚一些，而且能够减少数组的使用；curf：当前层数；lastr：上一层蛋糕的半径值；lasth：上一层蛋糕的高度；leftv：余下的可使用体积；sum：当天蛋糕的面积的和（包括底层的底面积）
    int maxh,curv,curs,h;
    if(sum+mins[curf]>=ans||leftv<minv[curf])return;//剪枝的两个条件：1.当前面积和+最小的可加面积都要比最小的记录面积大，那么需要剪枝。2.当前的剩余体积值比最小可剩余体积值小，那么剪枝
    if(curf==0){
        if(leftv==0&&sum<ans)ans=sum;//当前层数到0并且剩余体积为0并且最小值min大于给定的sum值，则进行记录
        return;
    }
    for(int i=lastr-1;i>=curf;i--){//如果i的值比curf小了，以后就没法再逐渐建立小了，枚举i
        h=(int)((leftv-minv[curf-1])/(double)(i*i));//剪枝（求h的数值：h/i*i）
        maxh=min(h,lasth-1);
        for(int j=maxh;j>=curf;j--){
            curs=2*i*j;
            curv=i*i*j;
            if(2*(leftv-curv)/i+sum+curs>=ans)continue;//剪枝,如果当前最小面积>=已经求得的面积
            if(curf==m) curs+=i*i;//如果当前层数为第m层，则还需要加上地面积
            dfs(curf-1,i,j,leftv-curv,sum+curs);//递归调用
        }
    }
}
int main(){
    for(int i=1;i<=20;i++){//先求出这个，便于后面的剪枝，因为r和h的值都是依次减一的，如果剩余的值不够下面几层逐渐减一的话肯定要剪枝处理掉，所以先求出这个，然后根据这个对下面的剪枝进行处理
        mins[i]=mins[i-1]+2*i*i;//计算从该节点到目标节点最小的面积值，既上几层蛋糕的总面积加上这一层蛋糕的侧面积值（在最小的r值前提下），用于以后的比较以及操作
        minv[i]=minv[i-1]+i*i*i;//同理，计算该节点到目标节点最小的体积值，既上几层蛋糕总体积加上这一层蛋糕的体积值，这一层蛋糕的体积值明显为r*r*h，但是由于h也存在r的递减性质，所以这个地方可以用i来代替
    }
    while(scanf("%d%d",&n,&m)!=EOF&&m&&n){
        ans=INF;
        int beg=(int)sqrt(n/(double)m)+1;
        dfs(m,beg,beg,n,0);
        if(ans==INF)printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}

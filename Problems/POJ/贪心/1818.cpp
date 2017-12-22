/*
ATP
题意：有2^e个人，每个人的排名为其次序，若a-b>=k则a一定能赢b，否则不一定
	  现要求出最小的t，使得t在一定的比赛安排后可以赢得整场比赛 
分析：贪心 + 二分
	  设答案是排名为p的人，则贪心策略是： p最后一轮与（p-k）比赛。这个还是有点显然的，因为所有与p比赛且能被p赢的人中，（p-k）是最容易撑到最后一轮的。
	  证明：否则，设p最后一轮与m比赛，（则m > p-k），(p-k)在某一轮与a比赛时被打败，
　　　　　　同时这一轮m是与b比赛且m胜利（因为m撑到了最后一轮）。则我们交换这一轮中的（p-k）和m，
　　　　　　即这一轮中让m与a比赛，因为（p-k）能被a打败，m也一定能被a打败；（p-k）与b比赛，（p-k）胜利。
　　　　　　这样，在后续的安排中，m的位置都改为（p-k）且（p-k）撑到最后一轮。其他都没有发生变化。
　　　　　　因此按贪心策略的比赛安排是存在的。
	  有了以上结论，就可以“递归”的安排比赛。如（p-k）在倒数第二轮优先选择和（p-k-k）比赛。
	  二分最后胜利的人，按以上规则判断是否可行。O(nlogn) 
	  据说有logn做法 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,queue[5010],add;char elio[5010];
bool vali(int person){
    int kase,tail,t,x=(int)(log10(n*1.0)/log10(2.0));
    memset(elio,0,sizeof(elio));
    //可以认为：elio[i]=j 表示i最后一次胜利是在倒数第j轮
    elio[person]=1;tail=person;
    add=0;queue[add++]=person;
    //总共x轮（这里kase=i实际上表示倒数第i轮比赛）
    for(kase=1;kase<=x;kase++){
        t=add;
        for(int i=0;i<t;i++){
            for(int j=max(1,queue[i]-k);j<=tail;j++){
                if(elio[j]==0){
                   elio[j]=kase+1;
                   queue[add++]=j;//放入数组，因为下一轮循环（即上一轮比赛）需要为其分配对手
				   break;
                }
            }
        }
    }
    for(int i=1;i<=tail;i++)if(elio[i]==0)return 0;//之前还有人没分配到，即没有合法方案
    return 1;
}
int main(){
    int st,ed,mid,i;
    scanf("%d %d",&n,&k);
    st=1,ed=n;
    if(vali(ed))st=ed;
    else while(ed-st>1){//二分
         mid=(st+ed)>>1;
		 if(vali(mid))st=mid;
         else ed=mid;
    }
    printf("%d\n",st);
    return 0;
}

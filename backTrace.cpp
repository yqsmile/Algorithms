#include <iostream>
#include<cmath>
using namespace std;

static int num;
static int *x;
static int sum;

void backtrack(int);
bool place(int);

void backtrack(int t)
{
    if(t>num) //num为皇后的数目
    {
        sum++;//sum为所有的可行的解
        for(int m = 1;m<=num;m++)
        {
            cout<<x[m];//这一行用输出当递归到叶节点的时候，一个可行解
        }
        cout<<endl;
    }
    else
        for(int i = 1;i<=num;i++)
        {
            x[t] = i;
            if(place(t)) backtrack(t+1);//此处的place函数用来进行我们上面所说的条件的判断，如果成立，进入下一级递归
        }
}

bool place(int k)
{
    for(int j = 1;j<k;j++)
        if(abs(x[k] - x[j]) == abs(k-j)||x[j] == x[k])
            return false;
        return true;

}


int main()
{
    num = 4;
    sum = 0;
    x = new int[num+1];
    for(int i= 0;i<=num;i++)
        x[i] = 0;
    backtrack(1);
    cout<<"方案共有"<<sum;


}

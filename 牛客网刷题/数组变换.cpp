#include <iostream>
# include <vector>

using namespace std;

/*
 链接：https://www.nowcoder.com/questionTerminal/c55f4f15cc3f4ff0adede7f9c69fa0c1
来源：牛客网

牛牛有一个数组，里面的数可能不相等，现在他想把数组变为：所有的数都相等。问是否可行。
牛牛可以进行的操作是：将数组中的任意一个数改为这个数的两倍。
这个操作的使用次数不限，也可以不使用，并且可以对同一个位置使用多次。

输入描述:

输入一个正整数N (N <= 50)
接下来一行输入N个正整数，每个数均小于等于1e9.


输出描述:

假如经过若干次操作可以使得N个数都相等，那么输出"YES", 否则输出"NO"
示例1
输入

2
1 2
输出

YES
 * 
 * 
 * 把数组每一个元素都除以2，直到它为奇数。如果此时数组每个元素都一样，满足条件
 * 
 * A乘以2能得到B，B除以2也可以得到A啊，不过除法可以有终止条件嘛（除到奇数为止），但乘法很难计算上限
 */

int div2(int x){
    while(x%2==0){
        x/=2;
    }
    return x;
}

int main(int argc, char** argv) {
    int n;
    cin>>n;
    vector<int> v;
    int temp  =-1;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    
    bool equals = true;
    for(int i=0;i<n;i++){
        v[i] = div2(v[i]);
        if(v[0]!=v[i]){
            equals = false;
            break;
        }
    }
    
    if(equals){
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;
}


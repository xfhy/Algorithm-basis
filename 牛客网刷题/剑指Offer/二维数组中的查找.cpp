#include <iostream>
#include <cstdlib>
# include <vector>

using namespace std;

/*
 *在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * */

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        /**
         * 思路:从右上角开始排除　　
         * 如果比右上角的数大，那么排除这一行
         * 如果比右上角的数小，那么排除这一列
		 * 如果相等，那么结束循环
         * */
        bool result = false;
        
        int row=array[0].size(),col=array.size();
        int i=0,j=col-1;
        while(i!=row && j!=-1){
            if(target==array[i][j]){
                result = true;
                break;
            }else if(target<array[i][j]){
                j--;
            } else {
                i++;
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<vector<int> > array;
    
    vector<int> temp;  //第一行为　１　３　５　７
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(7);
    array.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(6);
    temp.push_back(8);
    array.push_back(temp);
    temp.clear();
    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(7);
    temp.push_back(9);
    array.push_back(temp);
    temp.clear();
    temp.push_back(4);
    temp.push_back(6);
    temp.push_back(8);
    temp.push_back(10);
    array.push_back(temp);
    
    //输出
//    for(int i = 0; i < 4; i++)
//    {
//        for(int j = 0;j < 4; j++)
//        {
//            cout << array[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    bool result = solution.Find(18,array);
    cout<<result;
    return 0;
}


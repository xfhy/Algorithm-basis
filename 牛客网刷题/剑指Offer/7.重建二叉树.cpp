#include <iostream>

using namespace std;

/*
 * 重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建出如下图所示的二叉树并输出它的头结点。　
 * */

struct TreeNode {
    int value;
    TreeNode *pLeft;
    TreeNode *pRight;
};

TreeNode *Construct(int *preOrder, int *inOrder, int length);

TreeNode *ConstructCore(int *startPreOrder, int *endPreOrder, int *startInOrder,
                        int *endInOrder);

void showTree(TreeNode* T);

/**
 * 重建二叉树
 * @param preOrder 前序数组
 * @param inOrder  中序数组
 * @param length  长度
 * @return 头结点
 */
TreeNode *Construct(int *preOrder, int *inOrder, int length) {
    if (preOrder == nullptr || inOrder == nullptr || length <= 0) {
        return nullptr;
    }
    return ConstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

/**
 * 递归下去构建
 * @param startPreOrder
 * @param endPreOrder
 * @param startInOrder
 * @param endInOrder
 * @return
 */
TreeNode *ConstructCore(int *startPreOrder, int *endPreOrder, int *startInOrder,
                        int *endInOrder) {
    //前序数组的第一个即是这一次的根节点
    int rootValue = startPreOrder[0];
    TreeNode *root = new TreeNode();
    root->value = rootValue;
    root->pLeft = root->pRight = nullptr;

    //如果先序序列只有1个值
    if (startPreOrder == endPreOrder) {
        if (startInOrder == endInOrder && *startPreOrder == *startInOrder) {
            return root;
        } else {
            cout<<"输入错误";
        }
    }

    //接下来在中序序列中,查找根节点位置
    int *rootTemp = startInOrder;
    while (rootTemp <= endInOrder && *rootTemp != rootValue) {
        rootTemp++;
    } //出循环时找到了根节点的位置

    //判断合法性
    if (rootTemp == endInOrder && *rootTemp != rootValue) {
        //未找到   说明不合法
        throw "输入不合法";
    }

    //当前root左子树长度
    int leftLength = rootTemp - startInOrder;
    //当前root左子树的结束位置
    int *leftPreOrderEnd = startPreOrder + leftLength;

    if (leftLength > 0) {
        //构建左子树
        root->pLeft = ConstructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder,
                      rootTemp - 1);
    }

    if (leftLength < endPreOrder - startPreOrder) {
        //构建右子树
        root->pRight = ConstructCore(leftPreOrderEnd + 1, endPreOrder, rootTemp + 1,
                      endInOrder);
    }

    return root;
}

//先序遍历
void showTree(TreeNode* T){
    if(T!= nullptr){
        cout<<T->value<<endl;
        showTree(T->pLeft);
        showTree(T->pRight);
    }
}

int main() {
    // 前序
    int preOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    // 中序
    int inOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode* T = Construct(preOrder, inOrder, 8);
    showTree(T);
    return 0;
}
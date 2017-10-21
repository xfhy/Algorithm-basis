#include <iostream>

// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode *m_pParent;
};

// ==================== 辅助代码用来构建二叉树 ====================

//创建一个节点
BinaryTreeNode *CreateBinaryTreeNode(int value) {
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;

    return pNode;
}

//连接
void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
    if (pParent != nullptr) {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if (pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if (pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}

//打印节点
void PrintTreeNode(BinaryTreeNode *pNode) {
    if (pNode != nullptr) {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if (pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");

        if (pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    } else {
        printf("this node is null.\n");
    }

    printf("\n");
}

//打印二叉树
void PrintTree(BinaryTreeNode *pRoot) {
    PrintTreeNode(pRoot);

    if (pRoot != nullptr) {
        if (pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if (pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

//销毁二叉树
void DestroyTree(BinaryTreeNode *pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

//正式代码----------------------------------------
BinaryTreeNode *GetNext(BinaryTreeNode *pNode) {
    if (pNode == nullptr) {
        return nullptr;
    }

    BinaryTreeNode *next = nullptr;
    //如果当前节点有右子树,那么下一个节点是右子树的最左边的节点
    BinaryTreeNode *current = pNode;
    if (pNode->m_pRight != nullptr) {
        BinaryTreeNode *pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr) {
            pRight = pRight->m_pLeft;
        }
        next = pRight;
    } else {
        //当前节点没有右子树
        //1. 当前是父节点的左节点 那么下一个就是父节点
        //2. 当前是父节点的右节点,那么下一个是依次向上遍历,直到遍历的节点是父节点的左节点
        BinaryTreeNode *parent = current->m_pParent;
        while (current->m_pParent != nullptr && parent->m_pRight == current) {
            current = parent;
            parent = parent->m_pParent;
        }
        next = parent;
    }
    return next;
}

// ====================测试代码====================
void Test(char *testName, BinaryTreeNode *pNode, BinaryTreeNode *expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    BinaryTreeNode *pNext = GetNext(pNode);
    if (pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7() {
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

    DestroyTree(pNode8);
}

int main() {
    Test1_7();
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

/*
 * 2017年10月22日20:30:41
 * 用2个队列实现栈
 * 思路:
 *
 * 插入时直接插入到queue1中,弹栈时判断queue1中是否为空
 * 1.非空->弹出queue1中最后插入的元素,并将其他元素出队列到queue2中
 * 2. 空->将queue2中的全部元素出队列到queue1中,除了最后一个,将最后一个弹出
 *
 * */

template<typename T>
class CQueue {
public:
    CQueue(void);

    ~CQueue(void);

    void appendTail(const T &node);

    T deleteHead();

private:
    queue<T> queue1;
    queue<T> queue2;
};

template<typename T>
CQueue<T>::CQueue(void) {
}

template<typename T>
CQueue<T>::~CQueue(void) {
}

template<typename T>
void CQueue<T>::appendTail(const T &element) {
    queue1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead() {
    T result;

    if (!queue1.empty()) {
        while (!queue1.empty()) {
            if (queue1.size() == 1) {
                result = queue1.front();
                queue1.pop();
                break;
            }
            queue2.push(queue1.front());
            queue1.pop();
        }
    } else if (queue1.empty() && !queue2.empty()) {
        while (!queue2.empty()) {
            if (queue2.size() == 1) {
                result = queue2.front();
                queue2.pop();
                break;
            }
            queue1.push(queue2.front());
            queue2.pop();
        }
    } else {
        cout << "无法出队列" << endl;
    }

    return result;
}

// ====================测试代码====================
void Test(char actual, char expected) {
    if (actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main() {
    CQueue<char> queue;
    /*queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');
    cout << queue.deleteHead();
    cout << queue.deleteHead();
    cout << queue.deleteHead();*/

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'c');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'd');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'e');

    head = queue.deleteHead();
    Test(head, 'a');

    return 0;
}
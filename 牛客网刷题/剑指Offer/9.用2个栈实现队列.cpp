#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class CQueue {
public:
    CQueue(void);

    ~CQueue(void);

    void appendTail(const T &node);

    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T>
CQueue<T>::CQueue(void) {
}

template<typename T>
CQueue<T>::~CQueue(void) {
}

template<typename T>
void CQueue<T>::appendTail(const T &element) {
    stack1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead() {
    //如果stack2是空的,则将stack1中的全部弹栈再压入stack2中
    T result;
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T t = stack1.top();
            stack1.pop();
            stack2.push(t);
        }

        if (stack2.empty()) {
            cout<<"无法出队列"<<endl;
        } else {
            result = stack2.top();
            stack2.pop();
        }

    } else {
        //如果stack2是非空的,那么直接将stack2中的最上面那个弹栈
        result = stack2.top();
        stack2.pop();
    }
    return result;
}

int main() {
    CQueue<char> queue;
    /*queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');
    cout << queue.deleteHead();
    cout << queue.deleteHead();
    cout << queue.deleteHead();*/
    cout << queue.deleteHead();

    return 0;
}
#include <iostream>
#include <cstdlib>

using namespace std;

class Stack{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();

    void Push(int value);
    void Pop();
    int Top();

    int Size();
    bool IsEmpty();
    bool IsFull();
};

Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::Push(int value) {
    if(IsFull()) {
        cout << "Stack에 공간이 부족합니다." << "\n";
        exit(EXIT_FAILURE);
    }
    cout << "Push : " << value << "\n";
    arr[++top] = value;
}

void Stack::Pop() {
    if(IsEmpty()) {
        cout << "Stack에 값이 없습니다." << "\n";
        exit(EXIT_FAILURE);
    }

    cout << "Pop : " << Top() << "\n";
    arr[top--];
}

int Stack::Top() {
    if(!IsEmpty()) {
        return arr[top];
    }
    else {
        cout << "Stack이 비었습니다." << "\n";
        exit(EXIT_FAILURE);
    }
}

int Stack::Size() {
    return top+1;
}

bool Stack::IsEmpty() {
    return top == -1;
}

bool Stack::IsFull() {
    return top == capacity-1;
}

void menuPrint() {
    cout << "==============Stack===============" << "\n";
    cout << "[1] Push" << "\n";
    cout << "[2] Pop" << "\n";
    cout << "[3] Top" << "\n";
    cout << "[4] Size" << "\n";
    cout << "[5] Empty" << "\n";
    cout << "[Exit] Exit(1~5제외 아무키나 누르세요)" << "\n";
}

int main() {
    int size;
    cout << "Stack의 크기를 할당하세요 : ";
    cin >> size;
    cout << endl;
    Stack sta(size);

    while(true) {
        menuPrint();
        char cmd;
        cin >> cmd;
        if(cmd == '1') {
            int value;
            cout << "Push할 값 입력 : ";
            cin >> value;
            sta.Push(value);
        }
        else if(cmd == '2') {
            sta.Pop();
        }
        else if(cmd == '3') {
            cout << "Top : " << sta.Top() << "\n";
        }
        else if(cmd == '4') {
            cout << sta.Size() << "\n";
        }
        else if(cmd == '5') {
            cout << sta.IsEmpty() << "\n";
        }
        else {
            exit(0);
        }
    }
}
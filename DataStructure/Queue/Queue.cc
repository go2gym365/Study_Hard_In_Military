#include <iostream>
#include <cstdlib>

using namespace std;

class Queue{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;
    
public:
    Queue(int size);
    ~Queue();

    void Push(int value);
    void Pop();
    int Front();

    int Size();
    bool IsEmpty();
    bool IsFull();
};

Queue::Queue(int size) {
    capacity = size+1;
    arr = new int[capacity];
    front = 0;
    rear = 0;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::Push(int value) {
    if(IsFull()) {
        cout << "Queue에 공간이 부족합니다." << "\n";
        exit(EXIT_FAILURE);
    }
    cout << "Push : " << value << "\n";
    rear = (rear+1)%capacity;
    arr[rear] = value;
    count++;
}

void Queue::Pop() {
    if(IsEmpty()) {
        cout << "Queue에 값이 없습니다." << "\n";
        exit(EXIT_FAILURE);
    }

    cout << "Pop : " << Front() << "\n";
    count--;
    front = (front+1) % capacity;
}

int Queue::Front() {
    if(IsEmpty()) {
        cout << "Queue가 비었습니다." << "\n";
        exit(EXIT_FAILURE);        
    }
    else {
        return arr[(front+1) % capacity];
    }
}

int Queue::Size() {
    return count;
}

bool Queue::IsEmpty() {
    return front == rear;
}

bool Queue::IsFull() {
    return front == (rear + 1)%capacity;
}

void menuPrint() {
    cout << "==============Queue===============" << "\n";
    cout << "[1] Push" << "\n";
    cout << "[2] Pop" << "\n";
    cout << "[3] front" << "\n";
    cout << "[4] Size" << "\n";
    cout << "[5] Empty" << "\n";
    cout << "[Exit] Exit(1~5제외 아무키나 누르세요)" << "\n";
}

int main() {
    int size;
    cout << "Queue의 크기를 할당하세요 : ";
    cin >> size;
    cout << endl;
    Queue queue(size);

    while(true) {
        menuPrint();
        char cmd;
        cin >> cmd;
        if(cmd == '1') {
            int value;
            cout << "Push할 값 입력 : ";
            cin >> value;
            queue.Push(value);
        }
        else if(cmd == '2') {
            queue.Pop();
        }
        else if(cmd == '3') {
            cout << "front : " << queue.Front() << "\n";
        }
        else if(cmd == '4') {
            cout << queue.Size() << "\n";
        }
        else if(cmd == '5') {
            if(queue.IsEmpty()) {
                cout << "Queue가 비었습니다." << "\n";
            }
            else {
                cout << "Queue에 값이 존재합니다." << "\n";
            }
        }
        else {
            exit(0);
        }
    }
}
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    Node* prev;
    Node* next;
    int data;
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
    int size = 0;

public:
    DoublyLinkedList();
    ~DoublyLinkedList() {}
    void AddHead(int value);
    void AddTail(int value);
    void AddSomewhere(Node* node, int value);
    void DeleteHead();
    void DeleteTail();
    void DeleteSomewhere(Node* node);
    Node* FindByIndex(int idx);
    void PrintAll();
};

DoublyLinkedList::DoublyLinkedList() {
    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;

    size = 0;
}

void DoublyLinkedList::AddHead(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = head->next;
    head->next = newNode;
    newNode->prev = newNode->next->prev;
    newNode->next->prev = newNode;

    size++;
}

void DoublyLinkedList::AddTail(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    newNode->prev = tail->prev;
    tail->prev = newNode;
    newNode->next = newNode->prev->next;
    newNode->prev->next = newNode;

    size++;
}

void DoublyLinkedList::AddSomewhere(Node* node, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = node;
    node->prev->next = newNode;
    newNode->prev = node->prev;
    node->prev = newNode;

    size++;
}

void DoublyLinkedList::DeleteHead() {
    
    head->next = head->next->next;
    delete(head->next->prev);
    head->next->prev = head;

    size--;
}

void DoublyLinkedList::DeleteTail() {
    tail->prev = tail->prev->prev;
    delete(tail->prev->next);
    tail->prev->next = tail;

    size--;
}

void DoublyLinkedList::DeleteSomewhere(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete(node);

    size--;
}

Node* DoublyLinkedList::FindByIndex(int idx) {
    if(idx < 0 || idx > size) return tail;

    Node* temp = head->next;
    for(int i = 0; i < idx-1; i++) {
        temp = temp->next;
    }

    return temp;
}

void DoublyLinkedList::PrintAll() {
    cout << "Head";
    Node* node = head->next;
    while(node != tail) {
        cout << " - " << node->data;
        node = node->next;
    }
    cout << " - Tail" << "\n";
}

void menuPrint() {
    cout << "==============SinglyLinkedList===============" << "\n";
    cout << "[1] AddHead" << "\n";
    cout << "[2] AddTail" << "\n";
    cout << "[3] AddSomewhere" << "\n";
    cout << "[4] DeleteHead" << "\n";
    cout << "[5] DeleteTail" << "\n";
    cout << "[6] DeleteSomewhere" << "\n";
    cout << "[7] PrintAll" << "\n";
    cout << "[Exit] Exit(1~6제외 아무키나 누르세요)" << "\n";
}

int main() {
    DoublyLinkedList DLL;

    while(true) {
        menuPrint();
        char cmd;
        cin >> cmd;
        if(cmd == '1') {
            int value;
            cout << "제일 처음에 삽입 할 값 입력 : ";
            cin >> value;
            DLL.AddHead(value);
        }
        else if(cmd == '2') {
            int value;
            cout << "제일 끝에 삽입 할 값 입력 : ";
            cin >> value;
            DLL.AddTail(value);
        }
        else if(cmd == '3') {
            int value, idx;
            
            cout << "원하는 인덱스 : " ;
            cin >> idx;
            cout << "\n";
            cout << "삽입 할 값 입력 : ";
            cin >> value;
            DLL.AddSomewhere(DLL.FindByIndex(idx), value);
        }
        else if(cmd == '4') {
            DLL.DeleteHead();
        }        
        else if(cmd == '5') {
            DLL.DeleteTail();
        }
        else if(cmd == '6') {
            int idx;            
            cout << "삭제를 원하는 인덱스 : " ;
            cin >> idx;
            DLL.DeleteSomewhere(DLL.FindByIndex(idx));
        }
        else if(cmd == '7') {
            DLL.PrintAll();
        }
        else {
            exit(0);
        }
    }
}
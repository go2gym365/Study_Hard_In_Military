#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

class SinglyLinkedList{
private:
    Node* head;
    Node* tail;
    int size = 0;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}
    ~SinglyLinkedList() {}
    void AddNodeFront(int value);
    void AddNodeEnd(int value);
    void AddNodeOnAnywhere(int idx, int value);
    void SortAdd(int value);
    void DeleteEndNode();
    void DeleteNode(int idx);
    void PrintAll();
};

void SinglyLinkedList::AddNodeFront(int value) {
    Node* node = new Node;

    size++;
    node->data = value;
    node->next = nullptr;

    //노드가 하나도 없을 때
    if(head == nullptr) {
        head = node;
        tail = node;
    }
    //노드가 1개 이상일 떄
    else { 
        node->next = head;
        head = node;
    }
}

void SinglyLinkedList::AddNodeEnd(int value) {
    Node* node = new Node;

    size++;
    node->data = value;
    node->next = nullptr;

    //노드가 하나도 없을 때
    if(head == nullptr) {
        head == node;
        tail == node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void SinglyLinkedList::AddNodeOnAnywhere(int idx, int value) {
    Node* node = new Node;
    if(idx <= 1) {
        AddNodeFront(value);
    }
    else {
        Node* prev = head;
        
        int cnt = 1;
        while(cnt != idx-1) {
            prev = head->next;
            cnt++;
        }

        Node* node = new Node;
        node->data = value;
        node->next = prev->next;
        prev->next = node;
    }
    size++;
}

void SinglyLinkedList::SortAdd(int value) {
    if(size == 0) {
        AddNodeFront(value);
    }
    else {
        Node* temp = head;
        while(temp->next != nullptr && (value > temp->next->data)) {
            temp = temp->next;
        }
        

        Node* node = new Node;
        node->data = value;

        if(value < temp->data) {
            node->next = temp;
            head = node;
        }
        else {
            node->next = temp->next;
            temp->next = node;
        }

    }
    size++;
}

void SinglyLinkedList::DeleteEndNode() {
    if(size == 0) {
        cout << "삭제할 노드가 없습니다." << "\n";
        exit(EXIT_FAILURE);
    }

    if(size == 1) {
        delete(tail);
        tail = nullptr;
        head = nullptr;
    }
    else {
        Node* prev = head;
        Node* target = head->next;
        
        while(target != tail) {
            prev = target;
            target = target->next;
        }

        delete(target);
        tail = prev;
        prev->next = nullptr;
    }
    size--;
}

void SinglyLinkedList::DeleteNode(int idx) {
    if(size == 0) {
        cout << "삭제할 노드가 없습니다." << "\n";
        exit(EXIT_FAILURE);
    }
    
    if(size == 1) {
        delete(tail);
        tail = nullptr;
        head = nullptr;
    }
    else {
        Node* prev = head;
        
        int cnt = 1;
        while(cnt != idx-1) {
            prev = prev->next;
            cnt++;
        }

        prev->next = prev->next->next;
        delete(prev->next);
    }
    size--;
}

void SinglyLinkedList::PrintAll() {
    cout << "Head";
    Node* node = head;
    while(node != nullptr) {
        cout << " - " << node->data;
        node = node->next;
    }
    cout << " - Tail" << "\n";
}

void menuPrint() {
    cout << "==============SinglyLinkedList===============" << "\n";
    cout << "[1] AddNodeFront" << "\n";
    cout << "[2] AddNodeEnd" << "\n";
    cout << "[3] AddNodeOnAnywhere" << "\n";
    cout << "[4] SortAdd" << "\n";
    cout << "[5] DeleteEndNode" << "\n";
    cout << "[6] DeleteNode" << "\n";
    cout << "[7] PrintAll" << "\n";
    cout << "[Exit] Exit(1~6제외 아무키나 누르세요)" << "\n";
}

int main() {
    SinglyLinkedList SSL;

    while(true) {
        menuPrint();
        char cmd;
        cin >> cmd;
        if(cmd == '1') {
            int value;
            cout << "제일 처음에 삽입 할 값 입력 : ";
            cin >> value;
            SSL.AddNodeFront(value);
        }
        else if(cmd == '2') {
            int value;
            cout << "제일 끝에 삽입 할 값 입력 : ";
            cin >> value;
            SSL.AddNodeEnd(value);
        }
        else if(cmd == '3') {
            int value, idx;
            
            cout << "원하는 인덱스 : " ;
            cin >> idx;
            cout << "\n";
            cout << "삽입 할 값 입력 : ";
            cin >> value;
            SSL.AddNodeOnAnywhere(idx, value);
        }
        else if(cmd == '4') {
            int value;
            cout << "정렬하여 삽입할 값 입력 : ";
            cin >> value;
            SSL.SortAdd(value);
        }        
        else if(cmd == '5') {
            SSL.DeleteEndNode();
        }
        else if(cmd == '6') {
            int idx;            
            cout << "삭제를 원하는 인덱스 : " ;
            cin >> idx;
            SSL.DeleteNode(idx);
        }
        else if(cmd == '7') {
            SSL.PrintAll();
        }
        else {
            exit(0);
        }
    }
}
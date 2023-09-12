#include<iostream>

using namespace std;

int main() {
    string str = "WelcomeToSMUPC";

    int N;
    cin >> N;

    cout << str[N % str.length() - 1];
}
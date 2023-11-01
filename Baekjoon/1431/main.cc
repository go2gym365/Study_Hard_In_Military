#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> input;

bool cmp(string a, string b) {
    
    //1번 조건
    if(a.length() != b.length()) return a.length() < b.length();

	//2번 조건
    int aNum = 0;
    int bNum = 0;
    for(int i = 0; i < a.length(); i++) {
        if(isdigit(a[i])) aNum += (a[i] - '0');
    }
    for(int i = 0; i < b.length(); i++){
        if(isdigit(b[i])) bNum += (b[i] - '0');
    }
    if(aNum != bNum) return aNum < bNum;
    
    //3번 조건
    return a < b;
}


int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        
        input.push_back(str);
    }
    
    sort(input.begin(), input.end(), cmp);
    
    for(int i = 0; i < input.size(); i++) {
        cout << input[i] << "\n";
    }
}

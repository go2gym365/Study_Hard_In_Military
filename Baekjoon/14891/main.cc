#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    deque<char> gear1;
    deque<char> gear2;
    deque<char> gear3;
    deque<char> gear4;
    
    for(int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        
        for(int j = 0; j < 8; j++) {
            if(i == 0) {
                gear1.push_back(str[j]);
            }
            else if(i == 1) {
                gear2.push_back(str[j]);
            }
            else if(i == 2) {
                gear3.push_back(str[j]);
            }
            else if(i == 3) {
                gear4.push_back(str[j]);
            }
        }
    }
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int gNum, type;
        cin >> gNum >> type;
        
        if(gNum == 1) {
            if(type == 1) {
                char prev2, prev6;
                prev2 = gear1[2];
                prev6 = gear1[6];
                gear1.push_front(gear1.back());
                gear1.pop_back();
                if(prev2 != gear2[6]){
                    prev2 = gear2[2];
                    prev6 = gear2[6];
                    gear2.push_back(gear2.front());
                    gear2.pop_front();
                } else continue;
                if(prev2 != gear3[6]){
                    prev2 = gear3[2];
                    prev6 = gear3[6];
                    gear3.push_front(gear3.back());
                    gear3.pop_back();
                } else continue;
                if(prev2 != gear4[6]){
                    prev2 = gear4[2];
                    prev6 = gear4[6];
                    gear4.push_back(gear4.front());
                    gear4.pop_front();
                } else continue;
            }
            else if(type == -1) {
                char prev2, prev6;
                prev2 = gear1[2];
                prev6 = gear1[6];
                gear1.push_back(gear1.front());
                gear1.pop_front();
                if(prev2 != gear2[6]){
                    prev2 = gear2[2];
                    prev6 = gear2[6];
                    gear2.push_front(gear2.back());
                    gear2.pop_back();
                } else continue;
                if(prev2 != gear3[6]){
                    prev2 = gear3[2];
                    prev6 = gear3[6];
                    gear3.push_back(gear3.front());
                    gear3.pop_front();
                } else continue;
                if(prev2 != gear4[6]){
                    prev2 = gear4[2];
                    prev6 = gear4[6];
                    gear4.push_front(gear4.back());
                    gear4.pop_back();
                } else continue;
            }
        }
        else if(gNum == 2) {
            if(type == 1) {
                char prev2, prev6;
                prev2 = gear2[2];
                prev6 = gear2[6];
                gear2.push_front(gear2.back());
                gear2.pop_back();
                if(prev6 != gear1[2]){
                    gear1.push_back(gear1.front());
                    gear1.pop_front();
                } 
                if(prev2 != gear3[6]){
                    prev2 = gear3[2];
                    prev6 = gear3[6];
                    gear3.push_back(gear3.front());
                    gear3.pop_front();
                } else continue;
                if(prev2 != gear4[6]){
                    prev2 = gear4[2];
                    prev6 = gear4[6];
                    gear4.push_front(gear4.back());
                    gear4.pop_back();
                }
            }
            else if(type == -1) {
                char prev2, prev6;
                prev2 = gear2[2];
                prev6 = gear2[6];
                gear2.push_back(gear2.front());
                gear2.pop_front();
                if(prev6 != gear1[2]){
                    gear1.push_front(gear1.back());
                    gear1.pop_back();
                }
                if(prev2 != gear3[6]){
                    prev2 = gear3[2];
                    prev6 = gear3[6];
                    gear3.push_front(gear3.back());
                    gear3.pop_back();
                } else continue;
                if(prev2 != gear4[6]){
                    prev2 = gear4[2];
                    prev6 = gear4[6];
                    gear4.push_back(gear4.front());
                    gear4.pop_front();
                }
            }
        }
        else if(gNum == 3) {
            if(type == 1) {
                char prev2, prev6;
                prev2 = gear3[2];
                prev6 = gear3[6];
                gear3.push_front(gear3.back());
                gear3.pop_back();
                if(prev2 != gear4[6]){
                    gear4.push_back(gear4.front());
                    gear4.pop_front();
                }
                if(prev6 != gear2[2]){
                    prev2 = gear2[2];
                    prev6 = gear2[6];
                    gear2.push_back(gear2.front());
                    gear2.pop_front();
                } else continue;
                if(prev6 != gear1[2]){
                    gear1.push_front(gear1.back());
                    gear1.pop_back();
                }
            }
            else if(type == -1) {
                char prev2, prev6;
                prev2 = gear3[2];
                prev6 = gear3[6];
                gear3.push_back(gear3.front());
                gear3.pop_front();
                if(prev2 != gear4[6]){
                    gear4.push_front(gear4.back());
                    gear4.pop_back();
                }
                if(prev6 != gear2[2]){
                    prev2 = gear2[2];
                    prev6 = gear2[6];
                    gear2.push_front(gear2.back());
                    gear2.pop_back();
                } else continue;
                if(prev6 != gear1[2]){
                    gear1.push_back(gear1.front());
                    gear1.pop_front();
                } 
            }
        }
        else if(gNum == 4) {
            if(type == 1) {
                char prev2, prev6;
                prev2 = gear4[2];
                prev6 = gear4[6];
                gear4.push_front(gear4.back());
                gear4.pop_back();
                if(prev6 != gear3[2]){
                    prev2 = gear3[2];
                    prev6 = gear3[6];
                    gear3.push_back(gear3.front());
                    gear3.pop_front();
                } else continue;
                if(prev6 != gear2[2]){
                    prev2 = gear2[2];
                    prev6 = gear2[6];
                    gear2.push_front(gear2.back());
                    gear2.pop_back();
                } else continue;
                if(prev6 != gear1[2]){
                    prev2 = gear1[2];
                    prev6 = gear1[6];
                    gear1.push_back(gear1.front());
                    gear1.pop_front();
                }
            }
            else if(type == -1) {
                char prev2, prev6;
                prev2 = gear4[2];
                prev6 = gear4[6];
                gear4.push_back(gear4.front());
                gear4.pop_front();
                if(prev6 != gear3[2]){
                    prev2 = gear3[2];
                    prev6 = gear3[6];
                    gear3.push_front(gear3.back());
                    gear3.pop_back();
                } else continue;
                if(prev6 != gear2[2]){
                    prev2 = gear2[2];
                    prev6 = gear2[6];
                    gear2.push_back(gear2.front());
                    gear2.pop_front();
                } else continue;
                if(prev6 != gear1[2]){
                    prev2 = gear1[2];
                    prev6 = gear1[6];
                    gear1.push_front(gear1.back());
                    gear1.pop_back();
                }
            }
        }
    }
    
    int ans = gear1[0]-'0' + (gear2[0]-'0')*2 + (gear3[0]-'0')*4 + (gear4[0]-'0')*8;
    cout << ans;
}

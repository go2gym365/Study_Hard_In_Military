#include <iostream>

using namespace std;


int seat[10];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) { //입력 받는 횟수
        int left;
        cin >> left;
        
        for(int j = 0; j < n; j++) {
            //내 앞에 키 큰 사람 자리가 마련되어 있고 내 자리가 비었다면 앉기
            //하지만 지금 자리에 나보다 작은 애가 앉아있다면 다음 자리에 앉기
            if(left == 0 && !seat[j]) { 
                seat[j] = i+1;
                break;
            }
            // 내 앞에 키 큰 사람이 남아있고, 지금 앉아야 할 자리도 비었다면 
            else if(!seat[j]) {
                left--;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        cout << seat[i] << ' ';
}

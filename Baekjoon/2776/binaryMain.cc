#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> note1;

int binarySerach(int goal) {
    int left = 0;
    int right = n-1;
    int mid;
    
    while(left <= right) {
        mid = (left + right) / 2;
        
        if(note1[mid] == goal) {
            return note1[mid];
        }
        
        if(note1[mid] < goal) {
            left = mid+1;
        }
        else right = mid-1;
    }
    
    return right;
}

int main()
{
    int t; 
    scanf("%d", &t);
    
    while(t--) {
        note1.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            note1.push_back(a);
        }
        sort(note1.begin(), note1.end());
        
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            int a;
            scanf("%d", &a);
            
            if(binarySerach(a) == a) printf("1\n");
            else printf("0\n");
            //cout << binarySerach(a) << "\n";
        }
    }
}

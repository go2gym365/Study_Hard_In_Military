#include<bits/stdc++.h>

using namespace std;

int n;

struct Line {
    int x1;
    int x2;
    int y1;
    int y2;
};

Line line[3001];
int parent[3001];
int cnt[3001];

int find(int a) {
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long outer = (x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1);
    
    if(outer > 0) return 1;
    else if(outer == 0) return 0;
    else if(outer < 0) return -1;
}

bool isCross(Line a, Line b) {
    int abc = ccw(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
    int abd = ccw(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
    int cda = ccw(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
    int cdb = ccw(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);
    
    if(abc * abd <= 0 && cda * cdb <= 0) {
        if((a.x1 > b.x1 && a.x1 > b.x2 && a.x2 > b.x1 && a.x2 > b.x2) || 
            (b.x1 > a.x1 && b.x1 > a.x2 && b.x2 > a.x1 && b.x2 > a.x2)) return false;
        else if((a.y1 > b.y1 && a.y1 > b.y2 && a.y2 > b.y1 && a.y2 > b.y2) || 
            (b.y1 > a.y1 && b.y1 > a.y2 && b.y2 > a.y1 && b.y2 > a.y2)) return false;
        else return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
        parent[i] = i;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(isCross(line[i], line[j])) {
                join(i, j);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cnt[find(i)]++;
    }
    
    int groupCnt = 0;
    int maxCnt = 0;
    
    for(int i = 1; i <= n; i++) {
        if(cnt[i] > 0) groupCnt++;
        maxCnt = max(maxCnt, cnt[i]);
    }
    cout << groupCnt << '\n' << maxCnt;
}
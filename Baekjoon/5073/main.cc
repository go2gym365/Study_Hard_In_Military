#include <bits/stdc++.h>

using namespace std;

int main() {
    while (1) {
        int tri[3];

        for (int i = 0; i < 3; i++) {
            cin >> tri[i];
        }

        sort(tri, tri + 3);

        if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0)
            break;

        if (tri[2] >= tri[0] + tri[1])
            cout << "Invalid\n";
        else if (tri[0] == tri[1] && tri[1] == tri[2])
            cout << "Equilateral\n";
        else if (tri[0] == tri[1] || tri[1] == tri[2] || tri[2] == tri[1])
            cout << "Isosceles\n";
        else if (tri[0] != tri[1] && tri[1] != tri[2]) 
            cout << "Scalene\n";
        
    }
}
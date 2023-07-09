#include<bits/stdc++.h>

using namespace std;

int main() {
    double avg = 0; 
    float sumGrade = 0;

	for (int i = 0; i < 20; ++i)
	{
	    string majorName, input; 
	    double score; float grade;
		
        cin >> majorName >> grade >> input;
		
        if (input == "A+") score = 4.5;
		else if (input == "A0") score = 4.0;
		else if (input == "B+") score = 3.5;
		else if (input == "B0") score = 3.0;
		else if (input == "C+") score = 2.5;
		else if (input == "C0") score = 2.0;
		else if (input == "D+") score = 1.5;
		else if (input == "D0") score = 1.0;
		else if (input == "F") score = 0.0;
		else if (input == "P") continue;
		avg += (score * grade);
		sumGrade += grade;
	}
	avg = avg / sumGrade;

    cout << fixed;
	cout.precision(6);
	cout << avg;
}
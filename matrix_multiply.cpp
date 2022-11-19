#include <iostream> 
#include <vector> 
#include <fstream> 

using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int s;
    fin >> s;
    vector <long long> n(s);
    vector <long long> m(s);

    long long n_num;
    long long m_num;
    
    for (int i = 0; i < s; i++) {
        fin >> n_num >> m_num;
        n[i] = n_num;
        m[i] = m_num;
    }

    vector <vector <long long>> result(s, vector <long long>(s));

    for (int i = 0; i < s; i++) {
        result[i][i] = 0;
        if (i != s - 1) {
            long long a = n[i] * m[i] * m[i + 1];
            result[i][i + 1] = a;
        }

    }

    for (int l = 1; l < s; l++) {
        for (int i = 0; i < s - l + 1; i++) {
            int j = i + l;
            long long min = INT_MAX;
            if (j == s) {
                break;
            }
            for (int k = i; k < j; k++) {
                long long a = result[i][k] + result[k + 1][j] + n[i] * m[k] * m[j];
                if (min > a) {
                    min = a;
                }
            }
            result[i][j] = min;
        }
    }
    fout << result[0][s - 1];
}
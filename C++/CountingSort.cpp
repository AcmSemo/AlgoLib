#include <iostream>
#include <vector>
#define MAXN 1000000
using namespace std;

vector<int> counting_sort(vector<int> &v) {
    vector<int> count(MAXN);
    vector<int> res;
    for (auto &x: v) {
        count[x]++;
    }
    for (int i=0; i<MAXN; i++) {
        while (count[i] > 0) {
            res.push_back(i);
            count[i]--;
        }
    }
    return res;
}

int main() {
    std::vector<int> test1 = {52,10,85,0,99,10,13,37,0};
    vector<int> res1 = counting_sort(test1);
    for (auto &x: res1) cout << x << " ";
    cout << endl;
    std::vector<int> test2 = {100,864,1642,1882,85,549,41,99,458,2211};
    vector<int> res2 = counting_sort(test2);
    for (auto &x: res2) cout << x << " ";
    cout << endl;
}

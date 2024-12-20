#include <bits/stdc++.h>
using namespace std;
int main() {
    int i = 0;
    vector<int> vec;
    while (i < 1176) {
        string s;
        cin >> s;
        int x = (s[0] - '0') * 10 + (s[1] - '0');
        int y = (s[3] - '0') * 10 + (s[4] - '0');
        int cnt1 = count(vec.begin(), vec.end(), x);
        int cnt2 = count(vec.begin(), vec.end(), y);
        if (cnt1 == 0 && cnt2 == 0) {
            vec.push_back(x);
            vec.push_back(y);
        } else if (cnt1 == 0) {
            auto it = find(vec.begin(), vec.end(), y);
            if (it != vec.end()) {
                vec.insert(it, x); 
            }
        } else if (cnt2 == 0) {
            auto it = find(vec.begin(), vec.end(), x);
            if (it != vec.end()) {
                vec.insert(it + 1, y); 
            }
        } else {
            auto it1 = find(vec.begin(), vec.end(), x);
            auto it2 = find(vec.begin(), vec.end(), y);
            if (it1 != vec.end() && it2 != vec.end() && it1 > it2) {
                swap(*it1, *it2); 
            }
        }
        i++;
    }
    i = 0;
    int count = 0;
    while (i < 192) {
        int a;
        cin >> a;
        vector<int> vec1;
        while (a) {
            vec1.push_back(a);
            cin >> a;
        }
        int flag = 0;
        for (int m = 1; m < vec1.size(); m++) {
            auto it1 = find(vec.begin(), vec.end(), vec1[m]);
            auto it2 = find(vec.begin(), vec.end(), vec1[m - 1]);
            if (it1 != vec.end() && it2 != vec.end()) {
                if (it2 > it1) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            count += vec1[vec1.size() / 2]; 
        }
        i++;
    }
    cout << count;
    return 0;
}

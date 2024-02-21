#include "cyklib.hpp"
#include <set>
#include <vector>
#include <iostream>

using namespace std;

long long curr;
long long curr2;
set<int> imposs;

int isOver(int x) {
    long long tmp = circular_shift(x);
    curr2 = tmp;
    if (tmp == curr) return 0;
    long long tmp2 = circular_shift(x);
    curr2 = tmp2;
    imposs.insert(x);
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            imposs.insert(i);
            imposs.insert(x / i);
        }
    }
    if (tmp2 > curr && tmp2 < tmp) return -1;
    if (tmp < curr && (curr < tmp2 || tmp2<tmp)) return -1;
    if (tmp2 == curr) return 2;
    return 1;
}

int main()
{
    int mov = 0;
        imposs = {};
        curr = circular_shift(0);
        int up = 500000;
        int d = 1;
        int pyt = 0;

        int tmp = 1;
        int len = 0;
        int ll = 0;
        do {
            len = (up - d) / 2;
            len += d;
            tmp = isOver(len);
            curr = curr2;
            pyt += 3;
            if (tmp == 1)
                d = len+1;
            else if (tmp == -1)
                up = len-1;
            else if (tmp == 2) {
                len *= 2;
                break;
            }
            else
                break;

            if (len == ll && (d == len || up == len)) {
                len *= 2;
                len--;
                break;
            }
            ll = len;

        } while (true);
        vector<int> div;
        div.push_back(len);
        for (int i = 1; i <= len / i; i++) {
            if (len % i == 0) {
                if (imposs.find(i) == imposs.end())
                    div.push_back(i);
                if (imposs.find(len / i) == imposs.end())
                    div.push_back(len / i);
            }
        }

        for (int i = 0; i < div.size(); i++) {
            for (int j = 1; j < div.size() - i; j++) {
                if (div[j - 1] < div[j]) {
                    int tmp = div[j - 1];
                    div[j - 1] = div[j];
                    div[j] = tmp;
                }
            }
        }
        long long ctmp = curr;
        do {
            curr = ctmp;
            ctmp = circular_shift(div[div.size() - 1]);
            pyt++;
            if (ctmp == curr) break;
            div.pop_back();

        } while (true);

        give_answer(div[div.size() - 1]);
}
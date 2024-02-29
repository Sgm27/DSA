#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc-- > 0) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        int sum = 0, ans = -1;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int cur_sum = 0;
        for (int i = 1; i <= n; i++) {
            if (sum - a[i] - cur_sum == cur_sum) {
                ans = i;
                break;
            }
            cur_sum += a[i];
        }

        cout << ans << endl;
    }

    return 0;
}
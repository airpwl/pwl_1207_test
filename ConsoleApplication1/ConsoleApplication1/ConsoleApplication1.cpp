#include<iostream>
using namespace std;
#include<vector>
#include<deque>
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> dq;  // 存储索引

    for (int i = 0; i < nums.size(); i++) {
        // 1. 维护窗口大小
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. 维护单调递减性
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // 3. 加入当前元素
        dq.push_back(i);
        for (auto& c : dq)
        {
            cout << c << " ";
        }
        cout << endl;
        // 4. 记录结果
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}
int main()
{
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
        int k = 3;
    maxSlidingWindow(nums,k);
    return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

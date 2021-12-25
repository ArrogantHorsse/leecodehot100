#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    } 
    // 将原始nums进行排序
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[i]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    int m = 0;
    int n = 1    ;
    int k = nums.size()-1;
    vector<vector<int>> result;
    for (m = 0; m < nums.size() - 2; m++) {
        if(m>0&&nums[m] == nums[m-1]){
            continue;
        }
        n = m+1;
        k = nums.size()-1;
        while(n<k) {
            // 第二个数与前一次重复
            if((n>m+1&&nums[n] == nums[n-1])) {
                ++n;
                continue;
            }
            
            if(nums[n]+nums[k] == -nums[m]) {
                result.push_back({nums[m],nums[n],nums[k]});
                ++n;
                k--;
            } else if(nums[n]+nums[k]< (-nums[m])){
                n++;
            } else {
                k--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> vector_data = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    vector<vector<int>> result = threeSum(vector_data);
    for (auto m : result) {
        cout << "{";
        for (auto n : m) {
            cout << n << " ";
        }
        cout << "}" << endl;
    }
}
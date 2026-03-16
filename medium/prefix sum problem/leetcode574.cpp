// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
        // int  n =  nums.size();
        // int count = 0;
        // for(int i = 0 ; i<n;i++){
        //     int sum =0 ;
        //     for(int j =i ; j<n;j++){
        //         sum = sum + nums[j];   // this is my approach that i think but i unable to write in code
    

        //         if(sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
//         unordered_map<int,int> mp;
//         mp[0]=1;
//         int count = 0;
//         int prefixsum = 0;
//         for(int i = 0 ; i<nums.size();i++){
//             prefixsum = prefixsum + nums[i];
//             if(mp.find(prefixsum-k)!= mp.end()){
//                  count = count + mp[prefixsum -k];
//             }
//             mp[prefixsum]++;
//         }
//     return count;
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int count = 0;
        int prefixsum = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixsum = prefixsum + nums[i];

            if(mp.find(prefixsum - k) != mp.end()) {
                count = count + mp[prefixsum - k];
            }

            mp[prefixsum]++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 1, 1};
    int k = 2;

    int result = obj.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}
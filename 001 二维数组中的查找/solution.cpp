// 脑残遍历解法
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for(int i=0; i < array.size(); i++){
            for(int j =0; j < array[i].size(); j++){
                if (array[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};

// 二分查找，这个题应该只能按行或列分别二分查找，所以复杂度为 n log(n)
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int N = array.size();
        for(int i = 0; i < N; i++){
            int low = 0;
            int high = array[i].size()-1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(array[i][mid] < target){
                    low = mid + 1;
                }else if(array[i][mid] > target){
                    high = mid - 1;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};

// 对角线查找 官方推荐方法
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int i = row-1;
        int j = 0;
        while(i != -1 and j != col){
            if(array[i][j] == target){
                return true;
            }else if(array[i][j] < target){
                j++;
            }else{
                i--;
            }
        }
        return false;
    }
};
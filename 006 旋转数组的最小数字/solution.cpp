// 求解的关键在于 某一位大于后一位，则后一位必为最小值
// emmm 题目说的数组是非减数组的旋转，如果本身也是它的旋转的话，还应该比较一下第一位和最后一位
// 如果第一位小于最后一位，第一位就是最小值
// 后面的求解，假设本身不是它的一个旋转

// 顺序求解
// -1 表示输入有错，不加会通不过编译器，因为有分支没有 return 值 
// emmm 想了一下，也可以加个中间变量，break一下，就不需要要看到返回 -1了
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == NULL)
            return 0;

        for(int i=0; i<rotateArray.size()-1; i++){
            if (rotateArray[i] > rotateArray[i+1])
                return rotateArray[i+1];
        }
        return -1;
    }
};

// 二分查找求解
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == NULL)
            return 0;

        int begin = 0;
        int end = rotateArray.size()-1;
        int mid = (rotateArray.size()-1) / 2;
        while(begin <= end){
            if (rotateArray[mid] > rotateArray[mid+1])
                return rotateArray[mid+1];
            if (rotateArray[mid] > rotateArray[0]){
                begin = mid;
            } else {
                end = mid;
            }
            mid = (begin + end) / 2;
        }
        return -1;
    }
};
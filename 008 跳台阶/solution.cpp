// 递归解
class Solution {
public:
    int jumpFloor(int number) {
        if(number == 1){
            return 1;
        }
        else if (number == 2){
            return 2;
        }
        return jumpFloor(number-1) + jumpFloor(number-2);
    }
};

// 循环求解
class Solution {
public:
    int jumpFloor(int number) {
        vector <int> array;
        array.push_back(0);
        array.push_back(1);
        array.push_back(2);
        
        if (number <= 2){
            return array[number];
        }
        
        for(int i = 3; i <= number; i++){
            array.push_back(array[i-1] + array[i-2]);
        }
        return array[number];
    }
};

// 数组简化版本
class Solution {
public:
    int jumpFloor(int number) {
        int array[number]; 
        array[0] = 1;
        array[1] = 2;
        
        for(int i = 2; i < number; i++){
            array[i] = array[i-1] + array[i-2];
        }
        return array[number-1];
    }
};
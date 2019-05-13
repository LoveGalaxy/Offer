// 基础双循环版本
class Solution {
public:
    int jumpFloorII(int number) {
        int array[number];
        for(int i = 0; i < number; i++){
            array[i] = 1;
            for(int j = 0; j < i; j++){
                array[i] += array[j];
            }
        }
        return array[number-1];
    }
};

// 找规律 n 个台阶的可能为 2^(n-1) 种
// 简单方法
class Solution {
public:
    int jumpFloorII(int number) {
        int array[number];
        array[0] = 1;
        for(int i = 1; i < number; i++){
            array[i] = array[i-1] * 2;
        }
        return array[number-1];
    }
};

// 二分递归
class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 1){
            return 1;
        }
        if(number == 2){
            return 2;
        }
        if(number % 2 == 0){
            int x = jumpFloorII((number)/2);
            return x * x * 2;
        }else{
            int x = jumpFloorII((number+1)/2);
            return x * x;
        }
    }
};

// 二进制才是最吊的
class Solution {
public:
    int jumpFloorII(int number) {
        return 1<<(number-1);
    }
};
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> array;
        array.push_back(0);
        array.push_back(1);
        if (n < 2){
            return array[n];
        }
        
        for(int i=2; i<=n; i++){
            array.push_back(array[i-1] + array[i-2]);
        }
        return array[n];
    }
};
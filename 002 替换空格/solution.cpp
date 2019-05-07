// 这个题实际上是这样，首先毙掉了不能创建新的字符串，如果创建新的字符串，然后依次替换，这样占用内存会更多些 O（N）
// 接着定义问题为只能在原地址上进行，因此有了两种思路，最直观的思路是从前向后替换，但是这样每次替换空格时，需要将后面所有字符向后移动
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i = 0; i < length; i++){
            if(*(str+i+count) == ' '){
                count += 2;
                for(int j = length+count-1; j >= i+count+1; j--){
                    *(str+j) = *(str+j-2);
                }
                *(str+i+count-2) = '%';
                *(str+i+count-1) = '2';
                *(str+i+count) = '0';
            }
        }
    }
};

// O（N）算法 先计算空格数，再根据空格数从后向前替换
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i=0; i < length; i++){
            if(str[i] == ' '){
                count += 1;
            }
        }
        for(int i=length-1; i >= 0; i--){
            if(str[i]!=' '){
                str[i+2*count]=str[i];
            }
            else{
                count--;
                str[i+2*count]='%';
                str[i+2*count+1]='2';
                str[i+2*count+2]='0';
            }
        }

    }
};

// 指针描述
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i=0; i < length; i++){
            if(*(str+i) == ' '){
                count += 1;
            }
        }
        char *p = (str)+length-1;
        char *end = (str)+length+2*count-1;
        while(p != end){
            if(*p != ' '){
                *end = *p;
                p--;
                end--;
            }else{
                *end = '0';
                *(end-1) = '2';
                *(end-2) = '%';
                end -= 3;
                p--;
            }
        }
    }
};
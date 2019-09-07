
// 找出所有极值点，求出相邻极值点之间的最大装水面积，再用这些面积的和减去
// 非极值点的高度。

typedef struct EXPONT {
    int height;
    struct EXPONT* next;
}EXPONT;

int area(int* height, int i, int j) {
    return height[i] <= height[j] ? height[i]*(j-i) : height[j]*(j-i);
}

int maxArea(int* height, int i, int j) {
    int max_area = area(height, i, j);
    int tmp = 0;
    while(i < j - 1) {
        if(height[i] <= height[j]) {
            i = i + 1;
            tmp = area(height, i, j);
            if(tmp > max_area) max_area = tmp;
        } else {
            j = j - 1;
            tmp = area(height, i, j);
            if(tmp > max_area) max_area = tmp;
        }
    }
    return max_area;
}

int trap(int* height, int heightSize) {
    EXPONT* points = NULL;
    for(int i = 0; i < heightSize; ++i) {
        if(i == 0) {
            
        }
    }
}
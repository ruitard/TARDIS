
int area(int* height, int i, int j) {
    return height[i] <= height[j] ? height[i]*(j-i) : height[j]*(j-i);
}

int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;
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

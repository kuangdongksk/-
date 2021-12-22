#include<stdio.h>

typedef struct sqtable{
    int a[30]; 
    int length=0;

}sqtable; 

int f(sqtable st, int value,int low,int high) {
    int middle;
    if (low <= high) {
        middle = (low + high) / 2;
        if (st.a[middle] > value) {
            high = middle - 1;
            return f(st,value,low,high);
        }
        else if (st.a[middle] < value) {
            low = middle + 1;
            return f(st, value, low, high);
        }
        else {
            return middle;
        }
    }
    return -1;
}
int main() {
    sqtable st;
    st.a[0] = -100;
    int position;
    int n,v;
    printf("请输入你要输入的有序数列的长度：");
    scanf_s("%d", &n);
    printf("请输入你要输入的有序数列：\n");
loop: 
    for (int i = 1; i <= n; i++) {
        if (st.a[i] > st.a[i - 1]) {
            printf("输入错误请重新输入");
            goto loop;
        }
        scanf_s("%d", &st.a[i]);
        st.length++;
    }
    printf("请输入你要查询的数：\n");
    scanf_s("%d", &v);
    position = f(st, v,1, st.length);
    if(position != -1)
        printf("%d在第%d个",v,position);
    else
    {
        printf("没找到%d", v);
    }
    return 0;
}
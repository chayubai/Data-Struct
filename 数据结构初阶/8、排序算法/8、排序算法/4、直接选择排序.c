#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//选择排序思想:
//每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的第一个位置，第二个位置...直到全部待排序的数据元素排完。

//选择排序之直接选择排序

//摸一张牌，对它进行排序 - - 插入排序
//一把牌全部摸上来，进行排序  - - 选择排序
//思路：降序排列
//假设a[0]是最大的，依次与后n-1个数比较，如果有更大的则交换最大的数，放在a[0]位置
//假设a[1]是最大的，依次与后n-2个数比较，如果有更大的则交换最大的数，放在a[1]位置
//...
//即每次重复“在剩余的数中找最大数的一个”，最后把最大的数依次从数组的第一个位置开始放入数组中。
//注意：实际上就是找数组中的最大数，多加了一层循环演变而来的

void swap03(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectSort01(int* a, int n)//降序排列
{
    //6, 2, 4, 5, 1, 3, -1
    //max = 6  a[1]=2

    //6, 2, 4, 5, 1, 3, -1
    //max = 2  a[2]=4
    //max = 4  a[2]=2
    //6, 2, 2, 5, 1, 3, -1
    //max = 4  a[3]=5
    //max = 5  a[3]=4
     //6, 2, 2, 4, 1, 3, -1
     //max = 5
     //6, 5, 2, 4, 1, 3, -1

    for (int j = 0; j < n-1; j++)//n个数需要找n-1个最大的数
    {
        int max = a[j];
        for (int i = j + 1; i < n; i++)
        {
            //这种方法是可行的
            if (max < a[i])//如果是升序排列，则if (min > a[i])
                swap03(&max, &a[i]);
            /*
            if (max < a[i])
                max = a[i];//这种方法不可行，会将原来j下标的数据给覆盖，导致丢失
            */  

            //注意：找最大数进行交换，而不是赋值更新最大的数。
        }
        a[j] = max;
    }
}

//一次选两个，即最大和最小的数的下标，如果有更大或更小的数，则与最大和最小的下标对应的数进行交换，然后，分别放在两端。
//注意：不能选最大的数或最小的数，而是选最大的数或最小的数对应的下标。即选下标，而不是选数。
//如果选最大的数或最小的数，则放到两端会覆盖当前下标的数据，可能导致下一次要找的数丢失。
//错误答案：
/*
void SelectSort02(int* a, int n)//升序排列
{
    int begin = 0, end = n - 1;
    while (begin < end)
    {
        int maxi = begin, mini = begin;//最大和最小的数下标
        for (int i = begin; i <= end; i++)
        {
            if (a[i] < a[mini])
            {
                mini = i;
            }
            if (a[i] > a[maxi])
            {
                maxi = i;
            }
        }
        swap03(&a[begin], &a[mini]);//最小的换到左边
        //对于9, 3, 5, 2, 7, 8, 6,-1，9, 4, 0结果就会出问题
        //分析原因：由于begin和maxi重叠了，下一步和上一步连续执行，
        //先执行mini和begin下标的值交换，此时maxi处的数据变为了mini的值，然后又执行maxi位置的下标的数交换，
        //将mini的值换到了end位置上
        swap03(&a[maxi], &a[end]);//最大的换到右边
        begin++;
        end--;
    } 
}
*/
void SelectSort02(int* a, int n)
{
    int begin = 0, end = n - 1;
    while (begin < end)
    {
        int maxi = begin, mini = begin;
        for (int i = begin; i <= end; i++)
        {
            if (a[i] < a[mini])
            {
                mini = i;
            }
            if (a[i] > a[maxi])
            {
                maxi = i;
            }
        }
        swap03(&a[begin], &a[mini]);
        //如果begin和maxi重叠
        if (begin == maxi)
            maxi = mini;//由于上一步交换了一下，同时更新一下maxi的数的下标为mini的下标
        swap03(&a[maxi], &a[end]);
        /*
        //对于降序排列，除了上面加个判断外，直接这两行代码也可以
        swap03(&a[begin], &a[mini]);
        swap03(&a[maxi], &a[end]);
        */
        begin++;
        end--;
    }
}

/***********************************************************************************************************************************
注意：
    //降序
    swap(&a[mini], &a[end]);//先执行
    swap(&a[begin], &a[maxi]);//后执行
    //例如：6, 2, 4, 5, 1, 3, -1。因为先执行a[mini], a[end]的交换，降序就不会有问题。(因为先将mini放入了，后面不会影响mini)
    //注意：这个方法只能排降序。和不重叠的升序。排升序就变为了“升序中的第二种情况”发生的错误。

    swap(&a[begin], &a[maxi]);//先执行
    swap(&a[mini], &a[end]);//后执行
    //注意：执行这两行代码，是会导致执行顺序的不同而出现问题。
    //例如：6, 2, 4, 5, 1, 3, -1。因为先执行a[maxi], a[begin]的交换，降序就会有问题。(因为mini和end重叠了，先放的是maxi，后面会影响mini)
    解决方法：
    swap(&a[begin], &a[maxi]);
    //如果begin和maxi重叠
    if (mini == end)
        mini = maxi;//由于上一步交换了值，最小的值变为了maxi位置处，同时更新一下mini的数的下标为maxi的下标
    swap(&a[mini], &a[end]);
    //注意：这个方法既可以排降序，也可以排升序。排升序只需要将最小的值放到最左端，最大的值放到最右端。

    //升序
    swap03(&a[maxi], &a[end]);//先执行
    swap03(&a[begin], &a[mini]);//后执行
    //例如：9, 3, 5, 2, 7, 8, 6,-1, 9, 4, 0。因为先执行a[mini], a[end]的交换，升序就不会有问题。(因为先将maxi放入了，后面不会影响maxi)
    //注意：这个方法只能排升序。和不重叠的降序。排降序就变为了“降序中的第二种情况”发生的错误。

    swap(&a[begin], &a[mini]);//先执行
    swap(&a[maxi], &a[end]);//后执行
    //注意：执行这两行代码，是会导致执行顺序的不同而出现问题。
    //例如：9, 3, 5, 2, 7, 8, 6,-1, 9, 4, 0。因为先执行a[mini], a[begin]的交换，升序就会有问题。(因为begin和maxi重叠了，先放的是mini，后面会影响maxi)
    解决方法：
    swap(&a[begin], &a[mini]);
    //如果begin和maxi重叠
    if (begin == maxi)
        maxi = mini;//由于上一步交换了值，最大的值变为了mini位置处，同时更新一下maxi的数的下标为mini的下标
    swap(&a[maxi], &a[end]);
    //注意：这个方法既可以排升序，也可以排降序。排降序只需要将最小的值放到最右端，最大的值放到最左端。

    begin++;
    end--;
************************************************************************************************************************************/
//最好或最坏的结果,(不管是不是有序)，因为每一次找两个数都得遍历所有的数，所以时间复杂度都是一样，都是O(N) = N^2
//第一次，N个数选两个,n次比较
//第二次，N-2个数选两个，n-2次比较
//第三次，N-4个数选两个，n-4次比较
//...
//第N/2次，2或3个数选两个，2次比较
//基本操作的执行次数：F(N) = N + (N-2) + (N-4) + ... + 2，故O(N) = N^2

//正确答案：
//思路：升序排列
//假设下标为0的数是最小的，依次与后n-1个数比较，如果有更小的则，记录它的下标，更新最小的数的下标，再把它放在a[0]位置
//假设下标为1的数是最小的，依次与后n-2个数比较，如果有更小的则，记录它的下标，更新最小的数的下标，再把它放在a[1]位置
//...
//即每次重复“在剩余的数中找最大数的一个下标”，最后把下标所在的数，依次从数组的第一个位置开始放入数组中。
void SelectSort03(int arr[], int len)//降序排列
{
    int i, j;
    for (i = 0; i < len - 1; i++)//需要确定多少个最大的数
    {
        int max = i;
        for (j = i + 1; j < len; j++)//假设依次下标i为最大的数和后【i+1，n-1-i】区间的数比较
        {
            if (arr[j] > arr[max])//找到目前最大值。如果升序排序if (arr[j] < arr[min])
                max = j;//记录更大的数的下标
        }
        if (max != i)//如果目前最大的数下标和之前下标没有发生变化，说明最大的数下标没有发生更新，则不交换
            swap03(&arr[max], &arr[i]);
    }
}

//错误答案：逻辑错误
void SelectSort04(int* array, int n)//升序排列
{
    int i, k, j;//k标识最大的数下标
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[k] > array[j])//小的数，则更新下标
                k = j;
            swap03(&array[k], &array[j]);
        }
    }
}

void SelectSort05(int* array, int n)//升序排列
{
    for (int i = 0; i < n; i++) {
        int num = *(array + i);//每一趟将第i个下标位置的数，当作最小的数
        int index = i;//记录最小的元素下标
        for (int j = i + 1; j < n; j++) 
        {
            if (*(array + j) < num)//如果降序排序if(*(array + j) > num)
            {
                num = *(array + j);//更新最小的数
                index = j;//更新最小的数的下标
            }
        }
        if (index != i)//将找到最小元素，与array[i]交换
        {
            //array[index]  array[i]，利用num进行交换

            *(array + index) = *(array + i);
            *(array + i) = num;
        }
    }
}
#if 0
int main()
{
    //测试用例：
    //9, 3, 5, 2, 7, 8, 6,-1, 9, 4, 0
    //6, 2, 4, 5, 1, 3, -1
    //87,78,16,94
	int a[] = { 87,78,16,94 };

	int n = sizeof(a) / sizeof(a[0]);
    SelectSort04(a, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif

//多画图。

//直接选择排序的特性总结：
//1. 直接选择排序思考非常好理解，但是效率不是很好。实际中很少使用
//2. 时间复杂度：O(N ^ 2)
//3. 空间复杂度：O(1)
//4. 稳定性：不稳定
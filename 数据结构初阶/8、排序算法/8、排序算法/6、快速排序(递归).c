#define _CRT_SECURE_NO_WARNINGS 1
//交换排序之快速排序

// 快速排序思想：
//任取待排序元素序列中的某元素作为基准值，按照该排序码将待排序集合分割成两子序列，左子序列中所有
//元素均小于基准值，右子序列中所有元素均大于基准值，然后最左右子序列重复该过程，直到所有元素都排列在相应位置上为止。

//一、挖坑法（升序）
//第1步、单趟排序：每次只排一个数
//先选一个关键字key(key的值一般取数组最左边下标对应的数，或者最右边下标对应的数)，作为对比的对象，将其取出（取出后该下标的元素可形象理解为坑）
//如果坑在右边，begin（左）去找大于关键字key的值，将较大的值放入坑中。再更新坑的位置
//如果坑在左边，end（右）去找小于关键字key的值，将较小的值放入坑中。再更新坑的位置
//继续begin,end上述方法，依次下去，直到当begin == end处时，则把key放到最后一个坑的位置，同时记录中间数位置。此时，中间数就排好了。
//第2步、分治算法思想
//通过分治思想：进行整体排序，使得最后分解成关键字左右都是一个数。将问题不断缩小到不可再分的子问题。
//以key所在下标为分界，分割左右区间。左右区间同上面的方法，继续选各自的key，进行单趟排序......
//依次如此下去，直到区间被缩小到一个数时，最终小于key的都在左边，大于key的都在右边。

//注意：降序排序就是，单趟排序，左边找小的，右边找大的 放入坑中。

#include <stdio.h>
//单趟排序：每次只排一个数
//B               E  key
//6 3 5 2 7 8 9 4 1  6

//B               E  key
//坑3 5 2 7 8 9 4 1  6
//B               E  key
//1 3 5 2 7 8 9 4坑  6
//        B       E  key
//1 3 5 2 坑8 9 4 7  6
//        B    E     key
//1 3 5 2 4 8 9坑 7  6
//          B   E    key
//1 3 5 2 4 坑9 8 7  6
//          E
//          B        key
//1 3 5 2 4 坑9 8 7  6
//          E
//          B  
//1 3 5 2 4 6 9 8 7   

/*
//单趟排序：每次只排一个数
//问题代码：
void QuickSort01(int* a, int n)
{
	int begin = 0, end = n - 1;//下标
	int pivot = begin;//坑的下标。假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
	int key = a[begin];//选最左边的下标的数为key

	while (begin < end)//begin == end相等则结束
	{
		//右边找小的，放到左边(找小于key的值)
		while (a[end] >= key)//想的是结束的条件，写的是循环的条件
		{
			end--;
		}
		//将小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;//更新坑的下标

		//左边找大的，放到右边(找大于key的值)
		while (a[begin] <= key)
		{
			begin++;
		}
		//将大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;//更新坑的下标
	}

	//此时，begin == end相遇，即最后一个坑的位置,
	pivot = begin;//或者pivot = end;//记录中间数位置
	a[pivot] = key;
}
*/
//测试：6 3 5 2 7 8 9 4 1
//注意以上代码的调试过程：
//观察a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] begin end pivot key的值的变化 
//有可能从当前end下标位置找小，一直没有找到小，就会一直end--。导致最后超过了begin的下标，都可能没有找到，出现错乱。
//有可能从当前begin下标位置找大，一直没有找到大，就会一直begin++。导致最后超过了end的下标，都可能没有找到，出现错乱。
//优化后：
/*
void QuickSort01(int* a, int n)
{
	int begin = 0, end = n - 1;
	int pivot = begin;
	int key = a[begin];

	while (begin < end)//begin == end相等则结束
	{
		//右边找小的，放到左边
		while (begin < end && a[end] >= key)//这里a[end] >= key比较，有前提begin < end也就是不能相等，或交叉，否则会交叉end和begin
		{
			end--;
		}
		//将小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大的，放到右边
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//将大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	//相遇，最后一个坑的位置
	pivot = begin;//记录中间数位置
	a[pivot] = key;
}
*/
//注意：奇数个数据和偶数个数据，最终都是到begin == end单趟排序结束。
void QuickSort01(int* a, int left, int right)//left是0下标，right是n-1下标
{
	//当区间不存在时，即一个值的时候，不需要排，结束
	if (left >= right)
		return;

	//只有区间存在才进行快排
	int begin = left, end = right;//这里begin = left, end = right;由于会递归，所以begin, end不是固定的
	int pivot = begin;
	int key = a[begin];

	while (begin < end)//begin == end相等则结束
	{
		//右边找小的，放到左边
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//将小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大的，放到右边
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//将大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	//相遇，最后一个坑的位置
	pivot = begin;//更新坑的位置，同时记录中间数位置
	a[pivot] = key;

	//【left，right】 => 【left，pivot-1】pivot【pivot+1，right】,类似二叉树前序遍历
	//左子区间和右子区间有序，则整体有序 如何让它们整体有序？分治递归
	//没有小区间优化
	QuickSort01(a, left, pivot - 1);
	QuickSort01(a, pivot + 1, right);
}

#if 0
int main()
{
	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
	int n = sizeof(a) / sizeof(int);
	QuickSort01(a, 0, sizeof(a) / sizeof(int) - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif
//时间复杂度：
//单趟排序(排一个数)的时间复杂度：两端往中间走，合计共N次，即F(N) = N = O(N)
//理想情况下（每次左右区间大小相等，将分割成满二叉树），每次选的key都在中间时，n个数，对应n个结点，则二叉树的高度h = log2 (N+1),
//每一层的时间复杂度为O(N)，一共有h = log2 (N+1)层, 故，总时间复杂度：F(N) = N * log2 (N+1) = O(N * log2 N)
//最坏的情况（有序时，不论顺序逆序），选最左边的或最右边的作key时，每次单趟排序只排好最左边或最右边的一个数
//F(N) = N + (N-1) + (N-2) + ... + 1，(等差数列)总时间复杂度：O(N^2)

//由于当有序的时候，快排的时间复杂度很大，效率就很低，如何解决这个问题？
//解决方法：key的选取
//1、取中间值作key
//2、取随机值作key
//3、三数取中，即选取左端，中间，右端。也就是取既不是最大，也不是最小的值作key

int GetMidInex(int* a, int left, int right);
void swap05(int* a, int* b);

void QuickSort02(int* a, int left, int right)//left是0下标，right是n-1下标
{
	//当区间不存在时
	if (left >= right)
		return;

	int index = GetMidInex(a, left, right); //三者的中间者
	swap05(&a[left], &a[index]);//将index作为key，与最左边left位置的数交换，使得begin位置的值为三者的中间者，从而后续逻辑不需要改动。

	//只有区间存在才进行快排
	int begin = left, end = right;
	int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置，本质上已经为三者的中间者下标
	int key = a[begin];//由于交换了一下，所以a[begin]本质上还是取三者的中间者作为key

	while (begin < end)//begin == end相等则结束
	{
		//右边找小的，放到左边
		while (begin < end && a[end] >= key)//这里a[end] >= key比较，有前提，否则会交叉end和begin
		{
			end--;
		}
		//将小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大的，放到右边
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//将大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	//相遇，最后一个坑的位置
	pivot = begin;//更新坑的位置，同时记录中间数位置
	a[pivot] = key;

	//【left，right】 => 【left，pivot-1】pivot【pivot+1，right】,前序遍历二叉树类似
	//左子区间和右子区间有序，则整体有序 如何让它们整体有序 -- 分治递归
	//没有小区间优化
	QuickSort02(a, left, pivot - 1);
	QuickSort02(a, pivot + 1, right);

	/*
	//注意：上面最后两行代码，可以用下面代码进行优化

	//将最后几层递归调用次数进行优化，即小区间优化，防止递归调用次数太大
	//假设当左或右区间数据个数小于10，使用插入排序。
	//假设当左或右区间的数据个数大于10，使用快速排序。
	//小区间优化的值，是根据数据量而定的，官方一般取13
	if ((pivot - 1) - left > 10)//官方给13
	{
		QuickSort(a, left, pivot - 1);//每次调用快排，都是从a指针开始递归
	}
	else
	{
		InsertSort(a + left, ((pivot - 1) - left) + 1);//InsertSort(某区间最左边下标的指针，元素个数)。不一定从0开始
	}
	if (right - (pivot + 1) > 10)//官方给13
	{
		QuickSort(a, pivot + 1, right);//每次调用快排，都是从a指针开始递归
	}
	else
	{
		InsertSort(a + pivot + 1, (right - (pivot + 1)) + 1);//InsertSort(某区间最左边下标的指针，元素个数)。不一定从0开始
	}
	*/

	//注意：笔试一般不建议写三数取中和小区间优化，费时。
}
//三数取中，返回左端，中间，右端，既不是最大的也不是最小的中位数。
int GetMidInex(int* a, int left, int right)
{
	int mid = (left + right) / 2;//int mid = (left + right) >> 1;这个效率高一些
	//left mid right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])//a[left] < a[mid]、a[mid] < a[right]
		{
			return mid;
		}
		else if (a[left] > a[right])//a[left] < a[mid]、a[mid] > a[right]、a[left] > a[right] 则a[right] < a[left] < a[mid]
		{
			return left;
		}
		else//a[left] < a[mid]、a[mid] > a[right]、a[left] < a[right] 则a[left] < a[right] < a[mid]
		{
			return right;
		}
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])//a[left] > a[mid]、a[mid] > a[right]
		{
			return mid;
		}
		else if (a[left] < a[right])//a[left] > a[mid]、a[mid] < a[right]、a[left] < a[right] 则a[mid] < a[left] < a[right]
		{
			return left;
		}
		else//a[left] > a[mid]、a[mid] < a[right]、a[left] > a[right] 则a[mid] < a[right] < a[left]
		{
			return right;
		}
	}
}
void swap05(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//-----------------------------------------------------------------------------------------------------------------------------------

//1、挖坑法
//单趟排序 - 确定左边小右边大 - 每次只排一个数
//返回一趟最后begin == end处，即最后一个坑的下标，从而分治算法，分割区间
int Part1Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //三者的中间者
	swap05(&a[left], &a[index]);//将index作为key，与left交换

	//只有区间存在才进行快排
	int begin = left, end = right;
	int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
	int key = a[begin];

	while (begin < end)//begin == end相等则结束
	{
		//右边找小的，放到左边
		while (begin < end && a[end] >= key)//这里a[end] >= key比较，有前提，否则会交叉end和begin
		{
			end--;
		}
		//将小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大的，放到右边
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//将大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	//相遇，最后一个坑的位置
	pivot = begin;//更新坑的位置，同时记录中间数位置
	a[pivot] = key;

	return pivot;//返回一趟排序，左边都不key小，右边都比key大，中间那个数的下标
}

//2、左右指针法(升序)，也叫hoare版本
//第1步、单趟排序：每次只排一个数
//先选一个关键字key(key的值一般取数组最左边下标，或者最右边下标)，作为对比的对象
//begin（左边）去找大于关键字key下标对应的值，end（右边）去找小于关键字key下标对应的值，然后，两个下标对应的数交换。
//继续begin,end上述方法，依次下去，直到当begin == end处时，则该下标处的对应的数与key下标对应的数交换，同时记录中间数位置。此时，中间数就排好了。
//第2步、分治算法思想
//通过分治思想：进行整体排序，使得最后分解成关键字左右都是一个数。将问题不断缩小到不可再分的子问题。
//以key下标为分界，分割左右区间。左右区间同上面的方法，继续选各自的key，进行单趟排序......
//依次如此下去，直到区间被缩小到一个数时，最终小于key的都在左边，大于key的都在右边。

//注意：降序排序就是，单趟排序，左边找小的，右边找大的 然后交换。
int Part2Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //三者的中间者
	swap05(&a[left], &a[index]);//将index作为key

	//只有区间存在才进行快排
	int begin = left, end = right;
	int keyi = begin;

	while (begin < end)//相等或交错，则结束
	{
		//右边找小的
		while (begin < end && a[end] >= a[keyi])//这里需要begin < end，否则会越界
		{//a[end] > a[keyi]，可能会死循环，如5 1 2 4 3 5 8 7 9 
			end--;
		}

		//左边找大的
		while (begin < end && a[begin] <= a[keyi])//这里需要begin < end，否则会越界
		{//a[begin] < a[keyi]，可能会死循环，如5 1 2 4 3 5 8 7 9
			begin++;
		}
		//测试：5 1 2 4 3 5 8 7 9 
		//当key为5时，a[end] > a[keyi]找小，a[begin] < a[keyi]找大。左边begin从5开始找大，右边end从9开始找小，此时不满足条件，就一直死循环卡在这里。
		//注意以上代码的调试过程：
		//观察a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] begin end  keyi的值的变化 
		//有可能从当前end下标位置找小，一直没有找到小，就会一直end--。导致最后超过了begin的下标，都可能没有找到，出现错乱。
		//有可能从当前begin下标位置找大，一直没有找到大，就会一直begin++。导致最后超过了end的下标，都可能没有找到，出现错乱。

		//交换
		swap05(&a[begin], &a[end]);
	}

	//此时begin == end，相遇，与keyi交换。如果是交错，则结束
	swap05(&a[begin], &a[keyi]);//swap05(&a[end], &a[keyi]);

	return begin;//返回一趟排序，中间位置。同时也记录了中间数位置
}
//注意：挖坑法，和左右指针法同理，a[begin] < a[key]，a[end] > a[key]都会死循环。
//注意：奇数个数据和偶数个数据，最终都是到begin == end单趟排序结束。因为内层两个循环其中一个最终都会走到另一个下标的位置。

//3、前后指针法(升序)
//第1步、单趟排序：每次只排一个数
//先选一个关键字key(key的值一般取数组最左边下标，或者最右边下标)，作为对比的对象。
//假设key是数组最左边下标。定义cur指向最左边下标+1，和prev指向最左边下标。
//cur去找小于关键字key下标对应的值，如果当前位置的数不满足，cur++。如果当前位置的数满足，则prev++，然后，cur和prev两个下标位置的数交换。
//继续cur,prev上述方法，依次下去，直到当cur == 最右边下标时，则再将prev下标的数与key下标对应的数交换，同时记录中间数位置。此时，中间数就排好了。
//第2步、分治算法思想
//通过分治思想：进行整体排序，使得最后分解成关键字左右都是一个数。将问题不断缩小到不可再分的子问题。
//以key下标为分界，分割左右区间。左右区间同上面的方法，继续选各自的key，进行单趟排序......
//依次如此下去，直到区间被缩小到一个数时，最终小于key的都在左边，大于key的都在右边。

//核心：升序排序，把小的数换到左边去
//注意：降序排序就是，单趟排序，cur找大于关键字key下标对应的值，然后换到左边。
int Part3Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //三者的中间者
	swap05(&a[left], &a[index]);//将index作为key

	//只有区间存在才进行快排
	int keyi = left;
	int prev = left, cur = left + 1;

	while (cur <= right)//cur直到大于最右边的数的下标，结束
	{
		//cur找小的
		/*
		if (a[cur] < a[keyi])
		{
			prev++;
			swap05(&a[prev], &a[cur]);
		}
		*/

		//优化一下：当prev++;之后的数的位置与cur的位置为同一个位置，可以不交换
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap05(&a[prev], &a[cur]);
		}
		cur++;
	}
	//此时，cur走到尾，与keyi交换
	swap05(&a[keyi], &a[prev]);

	return prev;//返回一趟排序后中间数位置。同时记录中间数的位置
}
void QuickSort(int* a, int left,int right)//left是0下标，right是n-1下标
{
	//当区间不存在时
	if (left >= right)
		return;

	//int keyIndex = Part1Sort(a, left, right);
	//int keyIndex = Part2Sort(a, left, right);
	int keyIndex = Part3Sort(a, left, right);

	//【left，right】 => 【left，keyIndex-1】keyIndex【keyIndex+1，right】,前序遍历二叉树类似
	//左子区间和右子区间有序，则整体有序 如何让它们整体有序 -- 分治递归
	//没有小区间优化
	QuickSort(a, left, keyIndex - 1);
	QuickSort(a, keyIndex + 1, right);
	
	//将递归调用次数进行优化，即小区间优化，防止递归调用次数太大
	/*if (keyIndex - 1 - left > 10)//官方给13
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}
	if (right - (keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
	}*/
}
#if 0
int main()
{
	int a[] = { 90, 99, 92, 93, 16, 3, 16 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif
//多注意边界值的控制。快速排序核心思想：类似于前序遍历。多调试理解逻辑。多画图。

//快速排序的特性总结：
//1. 快速排序整体的综合性能和使用场景都是比较好的，所以才敢叫快速排序
//2. 时间复杂度：O(N * logN)
//3. 空间复杂度：O(logN)
//4. 稳定性：不稳定
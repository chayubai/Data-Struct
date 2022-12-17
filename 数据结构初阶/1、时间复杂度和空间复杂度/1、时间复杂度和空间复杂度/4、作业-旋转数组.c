#define _CRT_SECURE_NO_WARNINGS 1
//4����ת����
//����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����k�ǷǸ�����
//1���������������Ľ�����������������ֲ�ͬ�ķ������Խ���������
//2�������ʹ�ÿռ临�Ӷ�ΪO(1)��ԭ���㷨������������
//ԭ���㷨���������µĿռ䣬��ԭ�����ϴ���

//���룺nums = [1,2,3,4,5,6,7],k = 3
//�����[5,6,7,1,2,3,4]
//������ת1����7��1��2��3��4��5��6
//������ת2����6��7��1��2��3��4��5
//������ת3����5��6��7��1��2��3��4

//����һ����תһ�Σ������һ�����ݱ��浽tmp�У���ǰ�漸���������󿽱�һ�£�����tmp���ݷ����һ��λ��
//����ÿ����תһ�����������һ����ǰn-1������������Ų�������һ�����ŵ���һ��λ�á�
//��תk��λ�ã�����Ҫѭ���ظ�k�Ρ�
//��תһ�� ,��ҪŲ��N-1 ��,�ͷ������һ����1�Σ�һ��N�Ρ���Ҫ��תk�Ρ�
//F(N) = [1 + (N-1)] * K = N*K��ʱ�临�Ӷ�Ϊ��O(k*N)���ռ临�Ӷȣ�O(1)
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    while(k)
    {
        //�������һ����
        int tmp = nums[numsSize-1];
        //��ǰ�漸�����ݶ�����Ųһλ
        int end = numsSize-2;//�����ڶ��������±�
        while(end>=0)
        {
            nums[end+1] = nums[end];
            end--;
        }
        //�ѱ�����������һ��λ��
        nums[0] = tmp;
        k--;
    }
}
*/

/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    //while(k--)//�������--����תk�Ρ�k--����k����k--ѭ��k��
    for(int i = 0; i < k; ++i)
    {
        int tmp = nums[numsSize - 1];//�������һ����
        //�ӵ����ڶ�����ʼ���󶼺��ƶ�һ��
        for(int end = numsSize - 2�� end >= 0; --end)//�����ڶ��������±�
        {
            nums[end + 1] = nums[end];
        }
        //�������������һ���������һ��λ��
        nums[0] = tmp;
    }
}
*/

//������������k���������뵽һ������Ϊk���������У���ʣ���������Ų��������������е����ŵ�ǰk��λ��
//��1��2��3��4��5��6��7�� -> ��5��6��7��1��2��3��4��
//F(N) = K + (N-K) + K = N+k��ʱ�临�Ӷȣ�O(N+k)
//�ռ临�Ӷȣ�O(k)��
//����Ƚ���k���������뵽һ���������У��ٽ�ʣ������������������У�������е���������ԭ�ռ��С�
//����Ҫ����k�����Ŀռ䡣��ô�ռ临�Ӷ�Ϊ��O(k)
//ע�⣺�Կռ任ʱ��
//ע�⣺k���������Ԫ�ظ���ʱ����k % Ԫ�صĸ���
#include <stdio.h>
#include <stdlib.h>
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    //����һ����СΪk��Ԫ�ص�����
    int* tmp = (int*)malloc(sizeof(int)*k);
    //����k�������뵽�������еĶ�Ӧλ����
    int i = k - 1;
    int s = numsSize-1;
    while(i >= 0)
    {
        tmp[i] = nums[s];
        i--;
        s--;
    }

    //��֤�Ƿ����ݳɹ�������������
    //i = 0;
    //while(i<k)
    //{
    //    printf("%d ",tmp[i]);
    //    i++;
    //}

    //��ǰnumsSize-k��������Ųk��λ��
    int end = numsSize - k - 1;
    while(end>=0)
    {
        nums[end+k] = nums[end];
        end--;
    }

    //���������е�k��������ԭ������
    int j = 0;
    while(j < k)
    {
        nums[j] = tmp[j];
        j++;
    }
    free(tmp);
    tmp = NULL;
}
*/

//����Ǵ���һ������Ϊn�������飬�Ѻ�k�����ȴ��������飬�ٰ�ǰn-k�������������飬�����������е���������ԭ����������
//��ʱ,F(N) = K + (N-K) + N = 2N��ʱ�临�Ӷȣ�O(N),�ռ临�Ӷ�ΪO(N)
//ע�⣺��ʱ�任�ռ䣬���������һ���ܴ�����飬����Ҫ����һ���ܴ�Ŀռ䣬���ܿռ䲻���á�
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    //����һ����СΪnumsSize��Ԫ�ص�����
    int* tmp = (int*)malloc(sizeof(int)*numsSize);
    //�Ƚ���k�������뵽�������еĶ�Ӧλ����
    int i = k - 1;
    int s = numsSize-1;
    while(i >= 0)
    {
        tmp[i] = nums[s];
        i--;
        s--;
    }
    //�ٽ�ǰnumsSize-k�������뵽��������
    int j = k;
    int s2 = 0;
    while(j < numsSize)
    {
        tmp[j] = nums[s2];
        j++;
        s2++;
    }

    //����������е�ֵ������ԭ������
    for(int i = 0;i<numsSize;i++)
    {
        nums[i]=tmp[i];
    }
}
 */

 //��������������ת��
 //[1,2,3,4,5,6,7] k = 3
 //[4,3,2,1,7,6,5],ǰn-k�����ã���k������
 //[5,6,7,1,2,3,4],��������
 //���ã���ӦΪ���˽���
 //F(N) = K/2 + (N-K)2/ + N/2 = N��ʱ�临�Ӷȣ�O(N)        
 //�ռ临�Ӷȣ�O(1)
 /*
 #include <stdio.h>
 //����
 void reverse(int* nums, int left, int right)
 {
     while (left < right)
     {
         int tmp = nums[left];
         nums[left] = nums[right];
         nums[right] = tmp;
         left++;
         right--;
     }
 }
 void rotate(int* nums, int numsSize, int k)
 {
     k %= numsSize;//k���������Ԫ�ظ��� - ���Բ���if�ж� 4 % 7 = 4

     //1,2,3,4,5,6,7
     //numsSize = 7 k = 3
     //0 - 3
     //0 - (numsSize - k - 1)
     //4 - 6
     //(numsSize - k) - (numsSize - 1)

     reverse(nums, 0, numsSize - k - 1);
     reverse(nums, numsSize - k, numsSize - 1);
     reverse(nums, 0, numsSize - 1);
 }

 int main()
 {
     int nums[] = { 1,2,3,4,5,6,7 };
     int numsSize = sizeof(nums) / sizeof(nums[0]);
     int k = 1;
     rotate(nums, numsSize, k);
     int i = 0;
     for (i = 0; i < numsSize; i++)
         printf("%d ", nums[i]);
     return 0;
 }
 */

 //��ͼ���߶����룬д���͡�
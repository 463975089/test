#include <stdio.h>
#include <stdlib.h>

#define maxSize 6

typedef struct
{
    int data;
    int cur;  //�α�
}component;

/*************************************************************************
������������
*****************************************************************************/
void reserveArr(component* array)
{
    int i;
    for (i = 0; i < maxSize; i++)
    {
        array[i].cur = i + 1;   //��ÿ������������ӵ�һ��
    }
    array[maxSize - 1].cur = 0; //�������һ���ڵ���α�Ϊ0
}

/********************************************************
��ȡ����ռ�
����������Ϊ�ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0(���������һ���ڵ�ʱ���ýڵ���α�ֵΪ0)
********************************************************/
int mallocArr(component* array)
{
    int i = array[0].cur;

    if (array[0].cur)
    {
        //array[0].data=0;
        array[0].cur = array[i].cur;
    }
    return i;
}

/***************************************************************************
��ʼ����̬����
****************************************************************************/
int initArr(component* array)
{
    int body, tempBody, i, j;
    reserveArr(array);
    body = mallocArr(array);
    tempBody = body;  //����һ������������ָ��ʹ��ָ����������һ���ڵ㣬��Ϊ����Ϊ�գ����Ժ�ͷ����غ�
    for (i = 1; i < 4; i++)
    {
        j = mallocArr(array);  //�ӱ����������ó����еķ���
        array[tempBody].cur = j;//������Ŀ��з�����������������һ��������
        array[j].data = i;  //��������ķ����������ʼ��
        tempBody = j;  //��ָ���������һ������ָ�����
    }
    array[tempBody].cur = 0;  //�µ��������һ������ָ����Ϊ0
    return body;
}

void displayArr(component* array, int body)
{
    int tempBody = body; //tempBody׼������ʹ��
    while (array[tempBody].cur)
    {
        printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}
void Insert(component* array, int body, int add, int a);
int main()
{
    int body;
    component array[maxSize];
    body = initArr(array);
    printf("static link:\n");
    displayArr(array, body);

    system("pause");
    return 0;
}
void Insert(component* array, int body, int add, int a)//body����ͷ����������е�λ�ã�add����Ԫ�ص�λ�ã�a�����Ԫ��
{
    int tempBody = body;
    int i, insert;
    for (i = 1; i < add; i++)
    {
        tempBody = array[tempBody].cur;
    }
    insert = mallocArr(array);
    array[insert].data = a;
    array[insert].cur = array[tempBody].cur;
    array[tempBody].cur = insert;
}
//����������տռ�ĺ���������arrayΪ�洢���ݵ����飬k��ʾδʹ�ýڵ�����������±�
void freeArr(component* array, int k) {
    array[k].cur = array[0].cur;
    array[0].cur = k;
}
//ɾ����㺯����a ��ʾ��ɾ��������������ŵ�����
void deletArr(component* array, int body, char a) {
    int tempBody = body;
    //�ҵ���ɾ������λ��
    while (array[tempBody].data != a) {
        tempBody = array[tempBody].cur;
        //��tempBodyΪ0ʱ����ʾ�������������˵��������û�д洢�����ݵĽ��
        if (tempBody == 0) {
            printf("������û�д�����");
            return;
        }
    }
    //���е��ˣ�֤���иý��
    int del = tempBody;
    tempBody = body;
    //�ҵ��ý�����һ����㣬��ɾ������
    while (array[tempBody].cur != del) {
        tempBody = array[tempBody].cur;
    }
    //����ɾ�������α�ֱ�Ӹ���ɾ��������һ�����
    array[tempBody].cur = array[del].cur;
    //���ձ�ժ���ڵ�Ŀռ�
    freeArr(array, del);
}
int SelectElem(component* array, int body, char elem) {
    int tempBody = body;
    while (array[tempBody].cur != 0) //���α�ֵΪ0ʱ����ʾ�������
    {
        if (array[tempBody].data == elem) {
            return tempBody;
        }
        tempBody = array[tempBody].cur;
    }
    return -1;//����-1����ʾ��������û���ҵ���Ԫ��
}
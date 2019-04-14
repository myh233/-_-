#include<iostream>
using namespace std;
#define MAX 20
#define LISTINCREMENT 10

//定义数据结构
typedef struct {
	int *elem;  //存储空间基址
	int lenght;  //当前长度
	//int listsize;  //当前分配的存储容量
}SqList;
//建立一个线性表
void InitList(SqList &L)
{
	L.elem = (int*)malloc(MAX * sizeof(int));
	if (!L.elem)
		return; //exit(0)
	//L.listsize = MAX;
	printf("输入表的长度：");
	scanf_s("%d", &L.lenght);
	printf("输入%d个数：", L.lenght);
	for (int i = 0; i < L.lenght; i++)
		scanf_s("%d", &L.elem[i]);
}

//遍历
void Traverse(SqList &L) {
	//遍历
	printf("表中数据为：");
	for (int i = 0; i < L.lenght; i++)
		printf("%3d", L.elem[i]);
	printf("\n");
}
//销毁线形表
void DestoryList(SqList &L) {
	free(&L);
}
//将线性表置为空表
void ClearList(SqList &L){
	L.lenght = 0;
}
//判断线性表L是否为空
void ListEmpty(SqList &L) {
	if(L.lenght == 0)
		printf("空表\n");
	else
		printf("非空表\n");
}
//输出元素个数
void ListLength(SqList &L) {
	
	printf("元素个数为：%d\n",L.lenght);
}
//用e返回L中第i个数据元素的值
void GetElem(SqList &L,int i, int &e)
{
	e = L.elem[i];
	printf("第%d个元素为%d\n", i, e);
}
//找出线性表中第一个与e相同的，存在则返回该值再线性表中的位序
int LocateElem(SqList &L, int e)
{
	for (int i = 0; i < L.lenght; i++)
		if (L.elem[i] == e)
		{
			return(i);
		}
	return 0;
}
//返回前驱,如果cur_e为L中的元素且不为第一个元素，则用pre_e返回他的前驱，否则操作失败，pre_e无定义
int PriorElem(SqList &L, int cur_e, int &pre_e)
{
	for (int i = 1; i < L.lenght; i++)
		if (cur_e == L.elem[i])
		{
			pre_e = L.elem[i - 1];
			return pre_e;
		}
	return 0;
}
//返回前驱,如果cur_e为L中的元素且不为最后一个元素，则用next_e返回他的后继，否则操作失败，next_e无定义
int NextElem(SqList &L, int cur_e, int &next_e)
{
	for(int i=0; i < L.lenght-1; i++)
		if (cur_e == L.elem[i])
		{
			next_e = L.elem[i + 1];
			return next_e;
		}
	return 0;
}
//在线性表L的i号位置加入e，L长度加一
void ListInsert(SqList &L, int i, int e)
{

}


int main() {
	int e;
	SqList L;
	InitList(L);
	//DestoryList(L);
	Traverse(L);
	ListLength(L);
	//ClearList(L);
	ListEmpty(L);
	GetElem(L, 3, e);
	printf("相等元素位序为：%d\n",LocateElem(L, 4));
	printf("前驱为：%d\n", PriorElem(L, 2, e));
	printf("后继为：%d\n", NextElem(L, 2, e));
	system("PAUSE");
 	return 0;
}
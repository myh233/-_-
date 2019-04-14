#include<iostream>
using namespace std;
#define MAX 20
#define LISTINCREMENT 10

//�������ݽṹ
typedef struct {
	int *elem;  //�洢�ռ��ַ
	int lenght;  //��ǰ����
	//int listsize;  //��ǰ����Ĵ洢����
}SqList;
//����һ�����Ա�
void InitList(SqList &L)
{
	L.elem = (int*)malloc(MAX * sizeof(int));
	if (!L.elem)
		return; //exit(0)
	//L.listsize = MAX;
	printf("�����ĳ��ȣ�");
	scanf_s("%d", &L.lenght);
	printf("����%d������", L.lenght);
	for (int i = 0; i < L.lenght; i++)
		scanf_s("%d", &L.elem[i]);
}

//����
void Traverse(SqList &L) {
	//����
	printf("��������Ϊ��");
	for (int i = 0; i < L.lenght; i++)
		printf("%3d", L.elem[i]);
	printf("\n");
}
//�������α�
void DestoryList(SqList &L) {
	free(&L);
}
//�����Ա���Ϊ�ձ�
void ClearList(SqList &L){
	L.lenght = 0;
}
//�ж����Ա�L�Ƿ�Ϊ��
void ListEmpty(SqList &L) {
	if(L.lenght == 0)
		printf("�ձ�\n");
	else
		printf("�ǿձ�\n");
}
//���Ԫ�ظ���
void ListLength(SqList &L) {
	
	printf("Ԫ�ظ���Ϊ��%d\n",L.lenght);
}
//��e����L�е�i������Ԫ�ص�ֵ
void GetElem(SqList &L,int i, int &e)
{
	e = L.elem[i];
	printf("��%d��Ԫ��Ϊ%d\n", i, e);
}
//�ҳ����Ա��е�һ����e��ͬ�ģ������򷵻ظ�ֵ�����Ա��е�λ��
int LocateElem(SqList &L, int e)
{
	for (int i = 0; i < L.lenght; i++)
		if (L.elem[i] == e)
		{
			return(i);
		}
	return 0;
}
//����ǰ��,���cur_eΪL�е�Ԫ���Ҳ�Ϊ��һ��Ԫ�أ�����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
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
//����ǰ��,���cur_eΪL�е�Ԫ���Ҳ�Ϊ���һ��Ԫ�أ�����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���
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
//�����Ա�L��i��λ�ü���e��L���ȼ�һ
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
	printf("���Ԫ��λ��Ϊ��%d\n",LocateElem(L, 4));
	printf("ǰ��Ϊ��%d\n", PriorElem(L, 2, e));
	printf("���Ϊ��%d\n", NextElem(L, 2, e));
	system("PAUSE");
 	return 0;
}
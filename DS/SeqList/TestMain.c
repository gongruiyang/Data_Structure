#include "seqlist.h"

int main(){
	SeqList list;
	SeqListInitial(&list);	//初始化顺序表
	
	while (1){
		printf("******************************************************\n");
		printf("*[1]退出系统                 [2]展示数据             *\n");
		printf("*[3]头部增加数据             [4]尾部增加数据         *\n");
		printf("*[5]头部删除数据             [6]尾部删除数据         *\n");
		printf("*[7]获取当前最大容量         [8]获取当前表大小       *\n");
		printf("*[9]清空表中数据             [10]升序排列表中数据    *\n");
		printf("*[11]按照值插入数据          [12]按照位置插入数据    *\n");
		printf("*[13]按照值删除数据          [14]按照位置删除数据    *\n");
		printf("*[15]按照值查找位置          [16]按照位置查找数据    *\n");
		printf("*[17]反转表中数据                                    *\n");
		printf("******************************************************\n");

		printf("请输入你的选择：");
		int select = 0;
		scanf("%d", &select);

		int value = 0;
		int pos = 0;


		switch (select)
		{
		case 1:
			printf("Bye!!!!!\n");
			SeqListDestroy(&list);
			system("pause");
			return 0;
		case 2:
			SeqListShowData(&list);
			break;
		case 3:
			printf("请输入你要从头部插入表中的数据<以-1结束>：");
			while (scanf("%d", &value), value != -1){
				SeqListAddDataFromFront(&list, value);
			}
			printf("尾插数据完成！\n");
			break;
		case 4:
			printf("请输入你要从尾部插入表中的数据<以-1结束>：");
			while (scanf("%d", &value), value != -1){
				SeqListAddDataFromBack(&list, value);
			}
			printf("尾插数据完成！\n");
			break;
		case 5:
			SeqListDeleteFromFront(&list);
			printf("头删数据完成！\n");
			break;
		case 6:
			SeqListDeleteFromBack(&list);
			printf("尾删数据完成！\n");
			break;
		case 7:
			printf("当前表最大容量为：%d\n", SeqListGetCurrentCapacity(&list));
			break;
		case 8:
			printf("当前表大小为：%d\n", SeqListGetCurrentSize(&list));
			break;
		case 9:
			SeqListClearData(&list);
			printf("表已清空！\n");
			break;
		case 10:
			SeqListSort(&list);
			printf("表已升序排列！\n");
			break;
		case 11:
			printf("请输入你要按值大小插入表中的数据<以-1结束>：");
			while (scanf("%d", &value), value != -1){
				SeqListInsertByValue(&list, value);
			}
			printf("按值大小插入完毕！\n");
			break;
		case 12:
			printf("请输入你要插入的数据和位置：");
			scanf("%d%d", &value, &pos);
			SeqListInsertByPosition(&list, value, pos);
			break;
		case 13:
			printf("你要删除的数据为：");
			scanf("%d", &value);
			SeqListDeleteByValue(&list, value);
			break;
		case 14:
			printf("你要删除的数据的位置为：");
			scanf("%d", &pos);
			SeqListDeleteByPosition(&list, pos);
			break;
		case 15:
			printf("你要查找的数据为：");
			scanf("%d", &value);
			SeqListFindByValue(&list, value);
			break;
		case 16:
			printf("你要查找的位置为：");
			scanf("%d", &pos);
			SeqListFindByPosition(&list, pos);
			break;
		case 17:
			SeqListReverse(&list);
			printf("逆置完成！\n");
			break;
		default:
			printf("输入不合法！\n");
			break;
		}
		system("pause");
		system("cls");
	}


	SeqListDestroy(&list);
	system("pause");
	return 0;
}
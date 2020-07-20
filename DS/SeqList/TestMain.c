#include "seqlist.h"

int main(){
	SeqList list;
	SeqListInitial(&list);	//��ʼ��˳���
	
	while (1){
		printf("******************************************************\n");
		printf("*[1]�˳�ϵͳ                 [2]չʾ����             *\n");
		printf("*[3]ͷ����������             [4]β����������         *\n");
		printf("*[5]ͷ��ɾ������             [6]β��ɾ������         *\n");
		printf("*[7]��ȡ��ǰ�������         [8]��ȡ��ǰ���С       *\n");
		printf("*[9]��ձ�������             [10]�������б�������    *\n");
		printf("*[11]����ֵ��������          [12]����λ�ò�������    *\n");
		printf("*[13]����ֵɾ������          [14]����λ��ɾ������    *\n");
		printf("*[15]����ֵ����λ��          [16]����λ�ò�������    *\n");
		printf("*[17]��ת��������                                    *\n");
		printf("******************************************************\n");

		printf("���������ѡ��");
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
			printf("��������Ҫ��ͷ��������е�����<��-1����>��");
			while (scanf("%d", &value), value != -1){
				SeqListAddDataFromFront(&list, value);
			}
			printf("β��������ɣ�\n");
			break;
		case 4:
			printf("��������Ҫ��β��������е�����<��-1����>��");
			while (scanf("%d", &value), value != -1){
				SeqListAddDataFromBack(&list, value);
			}
			printf("β��������ɣ�\n");
			break;
		case 5:
			SeqListDeleteFromFront(&list);
			printf("ͷɾ������ɣ�\n");
			break;
		case 6:
			SeqListDeleteFromBack(&list);
			printf("βɾ������ɣ�\n");
			break;
		case 7:
			printf("��ǰ���������Ϊ��%d\n", SeqListGetCurrentCapacity(&list));
			break;
		case 8:
			printf("��ǰ���СΪ��%d\n", SeqListGetCurrentSize(&list));
			break;
		case 9:
			SeqListClearData(&list);
			printf("������գ�\n");
			break;
		case 10:
			SeqListSort(&list);
			printf("�����������У�\n");
			break;
		case 11:
			printf("��������Ҫ��ֵ��С������е�����<��-1����>��");
			while (scanf("%d", &value), value != -1){
				SeqListInsertByValue(&list, value);
			}
			printf("��ֵ��С������ϣ�\n");
			break;
		case 12:
			printf("��������Ҫ��������ݺ�λ�ã�");
			scanf("%d%d", &value, &pos);
			SeqListInsertByPosition(&list, value, pos);
			break;
		case 13:
			printf("��Ҫɾ��������Ϊ��");
			scanf("%d", &value);
			SeqListDeleteByValue(&list, value);
			break;
		case 14:
			printf("��Ҫɾ�������ݵ�λ��Ϊ��");
			scanf("%d", &pos);
			SeqListDeleteByPosition(&list, pos);
			break;
		case 15:
			printf("��Ҫ���ҵ�����Ϊ��");
			scanf("%d", &value);
			SeqListFindByValue(&list, value);
			break;
		case 16:
			printf("��Ҫ���ҵ�λ��Ϊ��");
			scanf("%d", &pos);
			SeqListFindByPosition(&list, pos);
			break;
		case 17:
			SeqListReverse(&list);
			printf("������ɣ�\n");
			break;
		default:
			printf("���벻�Ϸ���\n");
			break;
		}
		system("pause");
		system("cls");
	}


	SeqListDestroy(&list);
	system("pause");
	return 0;
}
#include <stdio.h>
#define n 1000

typedef struct //�������Ա�ṹ�� 
{
	int a[n];
	int last;
}seqlist;

void setList(seqlist *L)
{
	int i;
	printf("���������빹��˳���ĳ���:");
	scanf("%d",&L->last); 
//	printf("%d\n",L->last);

	printf("����������:");
	for(i = 1; i <= L->last; i++)
	{
		scanf("%d",&L->a[i]);
	}
	printf("������ϣ�\n");
//	for(i = 1; i <= L->last; i++)
//	{
//		printf("%d ",L->a[i]);
//	}
//	printf("\n");	
}

void traverseList(seqlist *L)
{
	int i;
	printf("�������Ϊ��");
	for(i = 1; i <= L->last; i++)
	{
		printf("%d ",L->a[i]);	
	}
	printf("\n");
}

void addNode(seqlist *L)
{
	int location,NewNum;//���ڴ�Ų���λ����������� 
	int i;

	printf("�����������������֣�");
	scanf("%d",&NewNum);
Contine:
	printf("��������������λ�ã�");
	scanf("%d",&location);
//	printf("%d %d\n",location,NewNum);
	
	if(location > L->last+1 || location < 1)//�ж��û������Ƿ�Ϸ� 
	{
		printf("����λ�ò��Ϸ���\n");
		goto Contine;		//������Ϸ����������û���д�����λ�� 
	}else{
		for(i = L->last; i >= location; i--)
		{
			L->a[i + 1] = L->a[i];
		}
		L->a[location] = NewNum;
		printf("������ϣ�\n"); 
	}
	
	L->last++;	//�������Ա���
	
	printf("�������Ϊ��");
	for(i = 1; i <= L->last; i++)
	{
		printf("%d ",L->a[i]);	
	}
	printf("\n");	
}

void DeleteNode(seqlist *L)
{
	int location; //���ڴ��ɾ��λ��
	int i;

Contine:
	printf("����������ɾ����λ�ã�");
	scanf("%d",&location);

	
	if(location > L->last || location < 1)//�ж��û�ɾ���Ƿ�Ϸ� 
	{
		printf("ɾ��λ�ò��Ϸ���\n");
		goto Contine;		//������Ϸ����������û���дɾ����λ�� 
	}else{
		for(i = location; i <  L->last; i++)
		{
			L->a[i] = L->a[i + 1] ;

		}
		printf("ɾ����ϣ�\n"); 
	}
	
	L->last--;	//�������Ա���
	
	printf("ɾ������Ϊ��");
	for(i = 1; i <= L->last; i++)
	{
		printf("%d ",L->a[i]);	
	}
	printf("\n");	
}

void ModifyNode(seqlist *L)
{
	int location,NewNum;//���ڴ���޸ĵ�λ�����޸ĺ������ 
	int i;

	printf("�������޸�֮������֣�");
	scanf("%d",&NewNum);
Contine:
	printf("�����������޸ĵ�λ�ã�");
	scanf("%d",&location);
//	printf("%d %d\n",location,NewNum);
	
	if(location > L->last+1 || location < 1)//�ж��û��޸��Ƿ�Ϸ� 
	{
		printf("�޸�λ�ò��Ϸ���\n");
		goto Contine;		//������Ϸ����������û���д�޸ĵ�λ�� 
	}else{
		L->a[location] = NewNum; //�޸ĸ�λ���ϵ����� 
		printf("�޸���ϣ�\n"); 
	}
	
	printf("�޸ĺ���Ϊ��");
	for(i = 1; i <= L->last; i++)
	{
		printf("%d ",L->a[i]);	
	}
	printf("\n");
	
	
	
	
	
	
}

void FindNode(seqlist *L)
{
	int loc = 0;
	int FindNum;
	int i;
	printf("�����������ѯ�����֣�");
	scanf("%d",&FindNum);
	
	for(i = 1; i <= L->last; i++)
	{
		if(L->a[i] == FindNum)
		{
			loc = i;
			printf("%d�������λ�ڵ�%dλ!\n",FindNum,loc);
		}
	}
	if(loc == 0){
		printf("û���ҵ�%d������֣�\n",FindNum);
	}	
}

void menu()
{
	printf(" ____________________________________\n");
	printf("|<0>�˳�                             |\n");
	printf("|<1>ʵ��˳����˳��洢             |\n");	
	printf("|<2>˳���ı������                 |\n");
	printf("|<3>����                             |\n");
	printf("|<4>ɾ��                             |\n");
	printf("|<5>�޸�                             |\n");
	printf("|<6>��ѯ                             |\n");
	printf("|____________________________________|\n");
	
	int choice;

	
	seqlist L; //����һ�����Ա� 
	while(1)
	{
		printf("����������ѡ��");
		scanf("%d",&choice);
		 
		switch(choice)
		{
			case 0 :
				printf("byebye!!!!!!\n");
				return ;
				break;
			case 1 :
				setList(&L);
				break;
			case 2 :
				traverseList(&L); 
				break;			
			case 3 :
				addNode(&L);
				break;			
			case 4 :
				DeleteNode(&L);
				break;			
			case 5 :
				ModifyNode(&L);
				break;								
			case 6 :
				FindNode(&L);
				break;
			default:
				printf("�������\n");	
		}
		printf("-------------------------------\n");
	}
}

int main()
{
	menu();	
	return 0;
 } 

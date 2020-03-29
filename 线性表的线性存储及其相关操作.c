#include <stdio.h>
#define n 1000

typedef struct //定义线性表结构体 
{
	int a[n];
	int last;
}seqlist;

void setList(seqlist *L)
{
	int i;
	printf("请输入你想构建顺序表的长度:");
	scanf("%d",&L->last); 
//	printf("%d\n",L->last);

	printf("请输入数据:");
	for(i = 1; i <= L->last; i++)
	{
		scanf("%d",&L->a[i]);
	}
	printf("输入完毕！\n");
//	for(i = 1; i <= L->last; i++)
//	{
//		printf("%d ",L->a[i]);
//	}
//	printf("\n");	
}

void traverseList(seqlist *L)
{
	int i;
	printf("遍历结果为：");
	for(i = 1; i <= L->last; i++)
	{
		printf("%d ",L->a[i]);	
	}
	printf("\n");
}

void addNode(seqlist *L)
{
	int location,NewNum;//用于存放插入位置与插入数据 
	int i;

	printf("请输入您想插入的数字：");
	scanf("%d",&NewNum);
Contine:
	printf("请输入您想插入的位置：");
	scanf("%d",&location);
//	printf("%d %d\n",location,NewNum);
	
	if(location > L->last+1 || location < 1)//判断用户插入是否合法 
	{
		printf("插入位置不合法！\n");
		goto Contine;		//如果不合法就重新让用户填写插入的位置 
	}else{
		for(i = L->last; i >= location; i--)
		{
			L->a[i + 1] = L->a[i];
		}
		L->a[location] = NewNum;
		printf("插入完毕！\n"); 
	}
	
	L->last++;	//自增线性表长度
	
	printf("插入后结果为：");
	for(i = 1; i <= L->last; i++)
	{
		printf("%d ",L->a[i]);	
	}
	printf("\n");	
}

void DeleteNode(seqlist *L)
{
	int location; //用于存放删除位置
	int i;

Contine:
	printf("请输入您想删除的位置：");
	scanf("%d",&location);

	
	if(location > L->last || location < 1)//判断用户删除是否合法 
	{
		printf("删除位置不合法！\n");
		goto Contine;		//如果不合法就重新让用户填写删除的位置 
	}else{
		for(i = location; i <  L->last; i++)
		{
			L->a[i] = L->a[i + 1] ;

		}
		printf("删除完毕！\n"); 
	}
	
	L->last--;	//自增线性表长度
	
	printf("删除后结果为：");
	for(i = 1; i <= L->last; i++)
	{
		printf("%d ",L->a[i]);	
	}
	printf("\n");	
}

void ModifyNode(seqlist *L)
{
	int location,NewNum;//用于存放修改的位置与修改后的数据 
	int i;

	printf("请输入修改之后的数字：");
	scanf("%d",&NewNum);
Contine:
	printf("请输入您想修改的位置：");
	scanf("%d",&location);
//	printf("%d %d\n",location,NewNum);
	
	if(location > L->last+1 || location < 1)//判断用户修改是否合法 
	{
		printf("修改位置不合法！\n");
		goto Contine;		//如果不合法就重新让用户填写修改的位置 
	}else{
		L->a[location] = NewNum; //修改该位置上的数据 
		printf("修改完毕！\n"); 
	}
	
	printf("修改后结果为：");
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
	printf("请输入您想查询的数字：");
	scanf("%d",&FindNum);
	
	for(i = 1; i <= L->last; i++)
	{
		if(L->a[i] == FindNum)
		{
			loc = i;
			printf("%d这个数字位于第%d位!\n",FindNum,loc);
		}
	}
	if(loc == 0){
		printf("没有找到%d这个数字！\n",FindNum);
	}	
}

void menu()
{
	printf(" ____________________________________\n");
	printf("|<0>退出                             |\n");
	printf("|<1>实现顺序表的顺序存储             |\n");	
	printf("|<2>顺序表的遍历输出                 |\n");
	printf("|<3>增加                             |\n");
	printf("|<4>删除                             |\n");
	printf("|<5>修改                             |\n");
	printf("|<6>查询                             |\n");
	printf("|____________________________________|\n");
	
	int choice;

	
	seqlist L; //定义一个线性表 
	while(1)
	{
		printf("请输入您的选择：");
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
				printf("输入错误！\n");	
		}
		printf("-------------------------------\n");
	}
}

int main()
{
	menu();	
	return 0;
 } 

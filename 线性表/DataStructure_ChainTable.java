/*
作者：宫瑞阳
时间：2020/3/27
*/
import java.io.IOException;
import java.util.Scanner;

public class DataStructure_ChainTable {
	
	Scanner sc = new Scanner(System.in);
	
	//定义结点类
	class Node		//定义结点
	{
		char  data;			//结点数据域
		Node nextNode; 		//结点指针域
		
		public Node(char data) //向数据域传递数据
		{
			this.data = data;
		}
	}
	
	public Node HeadNode = new Node('H');    	//定义头结点
	public Node CurrentNode = new Node('C');;  	//定义目前操作结点
	
	//初始化头结点函数
	public void IniHeadNode()	//初始化头结点
	{
		HeadNode.nextNode = null;  
	}
	
	//创建列表函数
	public void CreateChainTable() throws IOException 	//添加新节点功能的函数
	{
		boolean flag = true;  	//用于控制循环
		char d;				//用于暂时存放输入的值
		System.out.print("请输入你想插入的值：");

		while(flag)			//将输入的值放到头结点之后
		{
			d = (char)System.in.read();
			if(d != '$' )
			{
				if(d != ' ') {	//将除空格外的字符放到链表之中
				Node NewNode = new Node(d);  //创建一个新结点然后将键盘中的值传入data域中
				NewNode.nextNode  = HeadNode.nextNode;	//当前操作结点指针 指向 头结点指针 指向的 结点
				HeadNode.nextNode = NewNode;//头结点指针 指向 新插入的结点
				}else {
					continue;
				}
			}else {
				flag = false;			//当输入$字符时代表输入结束，便结束输入循环
			}
		}
		System.out.println("\n插入结束！");
	}
	
	//遍历函数
	public void TraverseChainTable(Node node) //遍历链表并输出所有的值，传入头结点
	{
		if(node == null)//如果head结点之后没有创建新结点，即链表中只有一个头结点
		{
			System.out.println("\n未创建链表！");
		}
		CurrentNode = node;	//用于移动输出的结点
		while( CurrentNode != null)	//当操作结点未到达链表的末端
		{
			System.out.print(CurrentNode.data+" ");//输出当前值
			CurrentNode = CurrentNode.nextNode; //移动CurrentNode
		}
	}
	
	//增加结点函数
	public void AddNode(Node node) throws IOException
	{
		int count = -1; //用于统计链表除了头结点外一共多少个结点
		CurrentNode = node;	//用于移动输出的结点
		
		System.out.print("请输入插入的位置：");
		int location = sc.nextInt();//用于接收插入位置
		System.out.print("请输入插入的数据：");
		char d = (char)System.in.read();//用于存放插入结点的data值
		
		Node NewNode = new Node(d);    //创建插入的结点
		
		while( CurrentNode != null ) //用于统计链表长度
		{
			if( CurrentNode.data != ' ' ) 
			{
				CurrentNode = CurrentNode.nextNode;
				count++;
			}else {
				continue;
			}
		}
		CurrentNode = node;		//让CurrentNode重新回到HeadNode处
//		System.out.println(count);
		if(location > count || location < 0)//判断位置location是否合法
		{
			System.out.println("输入不合法！");
		}else {
			
			for(int i = 1 ; i <= location; i++)
			{
				CurrentNode = CurrentNode.nextNode; //定位到location处	
			}
			
			NewNode.nextNode = CurrentNode.nextNode; //插入结点操作
			CurrentNode.nextNode = NewNode;
			System.out.println("插入成功！");
		}
	}
	
	//删除结点函数
	public void DeleteNode(Node node) throws IOException
	{
		int count = -1; //用于统计链表除了头结点外一共多少个结点
	
		CurrentNode = node;	//用于移动统计结点
		
		System.out.print("请输入删除的位置：");
		int location = sc.nextInt();//用于接收删除位置

		while( CurrentNode != null ) //用于统计链表长度
		{
			if( CurrentNode.data != ' ' ) 
			{
				CurrentNode = CurrentNode.nextNode;
				count++;
			}else {
				continue;
			}
		}
		
		CurrentNode = node;		//让CurrentNode重新回到HeadNode处
		
		if(location > count || location < 0)//判断位置location是否合法
		{
			System.out.println("输入不合法！");
		}else {
			
			for(int i = 1 ; i < location ; i++)
			{
				CurrentNode = CurrentNode.nextNode; //定位到要删除结点的前一个结点处	
			}
			CurrentNode.nextNode = CurrentNode.nextNode.nextNode;
			System.out.println("删除成功！");
		}
	}
	
	//交互函数
	public void menu()
	{
		int choice = 0;//用于用户选择
		//交互界面
		while(true) {
			System.out.println("\n==================================================");
			System.out.println("0.退出");
			System.out.println("1.创建链表");
			System.out.println("2.遍历并输出链表");
			System.out.println("3.删除某个结点");
			System.out.println("4.增加结点");
			System.out.println("==================================================\n");
			
			System.out.print("请输入你的选择：");
			choice = sc.nextInt();
			switch(choice) {
			case 0: 
				System.out.println("bye!");
				System.exit(0);
			case 1: 
				try {
					CreateChainTable();
					}catch (IOException e) {
						e.printStackTrace();
					}
				break;
			case 2:
				TraverseChainTable(HeadNode);
				break;
			case 3:
				try {
					DeleteNode(HeadNode);
				}catch (IOException e) {
					e.printStackTrace();
				}
				break;
			case 4:
				try {
					AddNode(HeadNode);
				}catch (IOException e) {
					e.printStackTrace();
				}
				break;
			default:
				System.out.println("输入不合法！");
				break;
			}
		}
	}
	
	//主函数
	public static void main(String[] args)
	{
		DataStructure_ChainTable list = new DataStructure_ChainTable();
		list.IniHeadNode();
		list.menu();
	}

	
}

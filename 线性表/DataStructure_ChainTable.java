/*
���ߣ�������
ʱ�䣺2020/3/27
*/
import java.io.IOException;
import java.util.Scanner;

public class DataStructure_ChainTable {
	
	Scanner sc = new Scanner(System.in);
	
	//��������
	class Node		//������
	{
		char  data;			//���������
		Node nextNode; 		//���ָ����
		
		public Node(char data) //�������򴫵�����
		{
			this.data = data;
		}
	}
	
	public Node HeadNode = new Node('H');    	//����ͷ���
	public Node CurrentNode = new Node('C');;  	//����Ŀǰ�������
	
	//��ʼ��ͷ��㺯��
	public void IniHeadNode()	//��ʼ��ͷ���
	{
		HeadNode.nextNode = null;  
	}
	
	//�����б���
	public void CreateChainTable() throws IOException 	//����½ڵ㹦�ܵĺ���
	{
		boolean flag = true;  	//���ڿ���ѭ��
		char d;				//������ʱ��������ֵ
		System.out.print("��������������ֵ��");

		while(flag)			//�������ֵ�ŵ�ͷ���֮��
		{
			d = (char)System.in.read();
			if(d != '$' )
			{
				if(d != ' ') {	//�����ո�����ַ��ŵ�����֮��
				Node NewNode = new Node(d);  //����һ���½��Ȼ�󽫼����е�ֵ����data����
				NewNode.nextNode  = HeadNode.nextNode;	//��ǰ�������ָ�� ָ�� ͷ���ָ�� ָ��� ���
				HeadNode.nextNode = NewNode;//ͷ���ָ�� ָ�� �²���Ľ��
				}else {
					continue;
				}
			}else {
				flag = false;			//������$�ַ�ʱ����������������������ѭ��
			}
		}
		System.out.println("\n���������");
	}
	
	//��������
	public void TraverseChainTable(Node node) //��������������е�ֵ������ͷ���
	{
		if(node == null)//���head���֮��û�д����½�㣬��������ֻ��һ��ͷ���
		{
			System.out.println("\nδ��������");
		}
		CurrentNode = node;	//�����ƶ�����Ľ��
		while( CurrentNode != null)	//���������δ���������ĩ��
		{
			System.out.print(CurrentNode.data+" ");//�����ǰֵ
			CurrentNode = CurrentNode.nextNode; //�ƶ�CurrentNode
		}
	}
	
	//���ӽ�㺯��
	public void AddNode(Node node) throws IOException
	{
		int count = -1; //����ͳ���������ͷ�����һ�����ٸ����
		CurrentNode = node;	//�����ƶ�����Ľ��
		
		System.out.print("����������λ�ã�");
		int location = sc.nextInt();//���ڽ��ղ���λ��
		System.out.print("�������������ݣ�");
		char d = (char)System.in.read();//���ڴ�Ų������dataֵ
		
		Node NewNode = new Node(d);    //��������Ľ��
		
		while( CurrentNode != null ) //����ͳ��������
		{
			if( CurrentNode.data != ' ' ) 
			{
				CurrentNode = CurrentNode.nextNode;
				count++;
			}else {
				continue;
			}
		}
		CurrentNode = node;		//��CurrentNode���»ص�HeadNode��
//		System.out.println(count);
		if(location > count || location < 0)//�ж�λ��location�Ƿ�Ϸ�
		{
			System.out.println("���벻�Ϸ���");
		}else {
			
			for(int i = 1 ; i <= location; i++)
			{
				CurrentNode = CurrentNode.nextNode; //��λ��location��	
			}
			
			NewNode.nextNode = CurrentNode.nextNode; //���������
			CurrentNode.nextNode = NewNode;
			System.out.println("����ɹ���");
		}
	}
	
	//ɾ����㺯��
	public void DeleteNode(Node node) throws IOException
	{
		int count = -1; //����ͳ���������ͷ�����һ�����ٸ����
	
		CurrentNode = node;	//�����ƶ�ͳ�ƽ��
		
		System.out.print("������ɾ����λ�ã�");
		int location = sc.nextInt();//���ڽ���ɾ��λ��

		while( CurrentNode != null ) //����ͳ��������
		{
			if( CurrentNode.data != ' ' ) 
			{
				CurrentNode = CurrentNode.nextNode;
				count++;
			}else {
				continue;
			}
		}
		
		CurrentNode = node;		//��CurrentNode���»ص�HeadNode��
		
		if(location > count || location < 0)//�ж�λ��location�Ƿ�Ϸ�
		{
			System.out.println("���벻�Ϸ���");
		}else {
			
			for(int i = 1 ; i < location ; i++)
			{
				CurrentNode = CurrentNode.nextNode; //��λ��Ҫɾ������ǰһ����㴦	
			}
			CurrentNode.nextNode = CurrentNode.nextNode.nextNode;
			System.out.println("ɾ���ɹ���");
		}
	}
	
	//��������
	public void menu()
	{
		int choice = 0;//�����û�ѡ��
		//��������
		while(true) {
			System.out.println("\n==================================================");
			System.out.println("0.�˳�");
			System.out.println("1.��������");
			System.out.println("2.�������������");
			System.out.println("3.ɾ��ĳ�����");
			System.out.println("4.���ӽ��");
			System.out.println("==================================================\n");
			
			System.out.print("���������ѡ��");
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
				System.out.println("���벻�Ϸ���");
				break;
			}
		}
	}
	
	//������
	public static void main(String[] args)
	{
		DataStructure_ChainTable list = new DataStructure_ChainTable();
		list.IniHeadNode();
		list.menu();
	}

	
}

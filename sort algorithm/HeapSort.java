/*
���ߣ�������
ʱ�䣺2020/3/28
*/
import java.util.Scanner;

public class HeapSort {

	static int N = 10;
	
	public static void swap(int a[],int i, int j)//���ڽ���
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	public static void smallheapify(int a [],int N,int i)//��iλ�ÿ�ʼ��ÿ��С�����С��
	{
		if( i >= N )  //���ڵݹ����
		{
			return ;
		}
		int c1 = 2 * i + 1; //�ҵ���Ҫ�ѻ��Ľ����������ӽڵ�
		int c2 = 2 * i + 2;
		
		int max = i;  //�ҵ���iΪ���׽ڵ��С���д���������Ľڵ�
		if(c1 < N && a[c1] > a[max]) //c1<N��Ϊ��ȷ����c1�ӽڵ�
		{
			max = c1;
		}
		if(c2 < N && a[c2] > a[max]) //c2<N��Ϊ��ȷ����c2�ӽڵ�
		{
			max = c2;
		}
		
		if(max != i) //���max���ǵ���i������ڵ㣬����Ҫ���ӽڵ����������ֽ��������ڵ㴦
		{
			swap(a,max,i);
			smallheapify(a,N,max);
		}
		
	}
	
	public static void bigheapify(int a[],int N)//������������ɴ��
	{
		int lastnode = N - 1;			//�ҵ����һ�����
		int parentnode = (lastnode - 1) / 2; //�ҵ����һ�����ĸ��ڵ�
		int i;
		for(i = parentnode; i >= 0; i--) //�����һ�����ڵ㿪ʼֱ����һ�����
		{
			smallheapify(a,N,i);
		}	
	}
	
	public static void heap_sort(int a[],int N) //�����򣬽�ÿ��
	{
		bigheapify(a,N);
		int i;
		for(i = N - 1; i >= 0; i--) 
		{
			swap(a, i, 0);
			smallheapify(a, i, 0);
		
		}
	}
	
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		Scanner sc = new Scanner(System.in);
		int []a = new int[N]; 
		
		for(int i = 0; i < N;i++) {
			a[i] = sc.nextInt();
		}
		
		heap_sort(a,N);
		
		for(int i = 0; i < N; i++) {
			System.out.print(a[i]+" ");
		}
		sc.close();
		
	}

}

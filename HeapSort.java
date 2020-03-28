/*
作者：宫瑞阳
时间：2020/3/28
*/
import java.util.Scanner;

public class HeapSort {

	static int N = 10;
	
	public static void swap(int a[],int i, int j)//用于交换
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	public static void smallheapify(int a [],int N,int i)//从i位置开始将每个小树变成小堆
	{
		if( i >= N )  //用于递归出口
		{
			return ;
		}
		int c1 = 2 * i + 1; //找到需要堆化的结点的两个孩子节点
		int c2 = 2 * i + 2;
		
		int max = i;  //找到以i为父亲节点的小树中存放数字最大的节点
		if(c1 < N && a[c1] > a[max]) //c1<N是为了确保有c1子节点
		{
			max = c1;
		}
		if(c2 < N && a[c2] > a[max]) //c2<N是为了确保有c2子节点
		{
			max = c2;
		}
		
		if(max != i) //如果max不是等于i这个父节点，最需要把子节点中最大的数字交换到父节点处
		{
			swap(a,max,i);
			smallheapify(a,N,max);
		}
		
	}
	
	public static void bigheapify(int a[],int N)//将整个大树变成大堆
	{
		int lastnode = N - 1;			//找到最后一个结点
		int parentnode = (lastnode - 1) / 2; //找到最后一个结点的父节点
		int i;
		for(i = parentnode; i >= 0; i--) //从最后一个父节点开始直到第一个结点
		{
			smallheapify(a,N,i);
		}	
	}
	
	public static void heap_sort(int a[],int N) //堆排序，将每次
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
		// TODO 自动生成的方法存根
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

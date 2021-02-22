import java.util.Scanner;
public class Selection_Sort {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner sc = new Scanner(System.in);

		int[] arr = new int[sc.nextInt()];		//规定数组长度
		
		for(int i = 0 ; i< arr.length ; i++){	//向数组中读入待排序数据
			arr[i] = sc.nextInt();
		}
		
		for(int i = 0; i < arr.length ; i++) { 	//选择排序
			int temp = arr[i];
			for(int j = i+1 ; j < arr.length ; j++)
			if(temp < arr[j]) {
				temp   = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
		
		System.out.print("["+arr[0]);
		for(int i = 1 ; i< arr.length ; i++){
			System.out.print(", "+arr[i]);
		}
		System.out.print("]");
		
		sc.close();
	}
}

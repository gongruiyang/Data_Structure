import java.util.Scanner;
public class Bubble_Sort {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner sc = new Scanner(System.in);
		//动态创建数组
		int[] arr = new int[sc.nextInt()];
		for(int i = 0 ; i< arr.length ; i++){
			arr[i] = sc.nextInt();
		}
		/********** Begin **********/
		for(int i = arr.length - 1; i >= 0; i--) {
			for(int j = 0; j < i; j++) {
				if(arr[j]>arr[j+1]) {
					int temp = arr[j];
					arr[j]  = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		
		System.out.print("["+arr[0]);
		for(int i = 1 ; i< arr.length ; i++){
			System.out.print(", "+arr[i]);
		}
		System.out.print("]");
		
		sc.close();		
		
		
		
		
		
		
		
		
		/********** End **********/
	}

}

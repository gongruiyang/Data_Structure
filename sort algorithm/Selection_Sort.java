import java.util.Scanner;
public class Selection_Sort {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		Scanner sc = new Scanner(System.in);

		int[] arr = new int[sc.nextInt()];		//�涨���鳤��
		
		for(int i = 0 ; i< arr.length ; i++){	//�������ж������������
			arr[i] = sc.nextInt();
		}
		
		for(int i = 0; i < arr.length ; i++) { 	//ѡ������
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

import java.util.Scanner;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

class Test{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack<Integer> stack = new Stack<>(); //Integer stack생성
		List<Integer> input_list = new ArrayList<>(); //입력한 순서의 리스트
		List<Integer> origin_list = new ArrayList<>(); //1-n까지 정렬된 리스트
		
		int count = sc.nextInt(); //전체 입력 개수
		StringBuilder rslt = new StringBuilder(); //*String을 사용하여 concat이나 +를 많이 사용하면 속도가 현저히 느려짐
		int flag = 1; //불가능 여부
		
    //입력
		for (int i = 0; i < count; i++) {
			origin_list.add(i+1);
			input_list.add(sc.nextInt());
		}
    
		int input_index = 0; //입력한 리스트의 index
		for(int want_to_find : input_list) {
			if (input_index == input_list.size()) //index out of error 해결용....
				break;
			//stack에 먼저가서 찾음
			if (stack.search(want_to_find) != -1) {//있으면
				rslt.append("-\n");
				stack.pop();
			}
			//origin_list를 stack에 담으면서 찾음
			else if (origin_list.contains(want_to_find)) { //있으면
				int index = 0; //왜인지.. 0을 넣어주는것보다 변수를 사용하는게 조금 더 빠름
				while(index < origin_list.size() &&	want_to_find != origin_list.get(index)) {
					stack.push(origin_list.get(index));
					origin_list.remove(index);
					rslt.append("+\n");
				}
				rslt.append("+\n-\n"); //찾은 애를 stack에 넣었다가 다시 뺌을 표시
				origin_list.remove(index);
			}
			else {
				System.out.println("NO");
				flag = 0;
				break;
			}	
			input_index++; //이제 다음 것 찾기
		}
		if (flag == 1)
			System.out.println(rslt);
		sc.close();
	}
}

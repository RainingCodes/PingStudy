import java.util.Scanner;
import java.util.Stack;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); //Scanner가져오기
		Stack<String> stack = new Stack<>(); //String stack생성
		
		int count = sc.nextInt(); //전체 입력 개수
		
		int[] rslt = new int[count]; //true&false 결과를 담을 배열
		int index = 0; //배열의 index
    
		for (int i = 0; i < count; i++) { //전체 입력 개수번 반복
			String str = sc.next(); //문자열 읽고
			int k = 0; //문자열의 index
			while(k < str.length()) { //문자열을 앞에서부터 하나씩 가져옴
				String tmp = Character.toString(str.charAt(k)); //가져온 char형을 String으로 변환
				if (stack.empty() == false){ //stack이 비어있지 않으면
					if (stack.peek().equals("(") && tmp.equals(")")) //비교 후
						stack.pop(); //pop 또는
					else 
            stack.push(tmp); //push
				}
				else 
          stack.push(tmp); //비어있으면 push
				k++; //다음 문자열 받기
			}
			if (stack.empty() == true) //모두 짝이 맞으면
				rslt[index++] = 1; //결과 배열에 1(참)넣기
			else {
				rslt[index++] = 0; //짝이 안맞으면 결과 배열에 0(거짓)넣고 
				while(stack.empty() == false) //stack초기화
					stack.pop();
			} 
		}
		
		for (int i = 0; i < count; i++) //결과 배열을 돌면서
			if (rslt[i] == 1) //참이면
				System.out.println("YES");
			else //거짓이면 
				System.out.println("NO");
		
		sc.close(); //Scanner 닫기
	}
}

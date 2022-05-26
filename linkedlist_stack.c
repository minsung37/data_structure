#include <stdio.h>
// 연결리스트로 스택구현


// 0. 스택 구조체
typedef struct stack
{
  char data;
	struct stack* next; 
} stack;

// 스택의 top부분
stack* top;


// 1. 공백 상태인지 검사하는 함수
int isEmpty() {
    if (top == NULL) {
			printf("stack is Empty\n");
			return 1;
		}
		return 0;
}

// 2. 스택에 노드를 넣는 함수
void push(data) {
	// new_node 동적할당
	stack* new_node = (stack *)malloc(sizeof(stack));
	// 새로운 노드의 데이터와 top이어주기
	new_node->data = data;
	new_node->next = top;
	// top에 new_node 할당
	top = new_node;
}

// 3. 스택의 노드를 제거하는 함수
void pop() {
	// 스택이 비어있지 않으면
	if (!isEmpty()) {
		// 맨위 노드의 주소값을 저장
		stack* temp = top;
		// 맨위 노드의 값을 저장
		char data = temp->data;
		// top노드는 기존의 top 노드가 가르키는 노드가된다.
		top = temp->next;
		// 동적할당 해제
		free(temp);
		return data;
	}
}

// 4. 스택의 맨위 노드를 확인하는 함수
char peek() {
	if (!isEmpty){
		return top->data;
	}
}

// 5. 스택의 노드에 있는 데이터를 출력하는 함수 
void print_stack() {
	if (!isEmpty()) {
		stack* temp = top;
		while (temp)
		{
			printf("%c ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}


int main(void) {
  print_stack();
	push('A');
	push('B');
	push('C');
	print_stack();
	pop();
	push('D');
	push('E');
	push('F');
	print_stack();
	pop();
	pop();
	print_stack();
}

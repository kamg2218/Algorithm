//11000 강의실 배정 - 우선순위 큐

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	pair
{
	int			start;
	int			end;
}				pair;

//qsort 정렬 함수
int			cmp(const void* p1, const void* p2)
{
	pair	*a = (pair *)p1;
	pair	*b = (pair *)p2;

	if (a->start > b->start)
		return (1);
	else if (a->start < b->start)
		return (-1);
	return (0);
}

//강의 종료 시간 저장
void		push(int *room, int *cnt, int num)
{
	int i = *cnt + 1;

	//강의실 수 1 증가
	*cnt += 1;
	//입력하려는 값보다 큰 값이 있으면
	//마지막으로 옮기고, 다시 탐색
	while(i!=1 && num < room[i / 2])
	{
		room[i] = room[i / 2];
		i /= 2;
	}
	//새로운 값 저장
	room[i] = num;
}

//최소 종료 시간 꺼내기
void		pop(int *room, int *cnt)
{
	int i = *cnt;	//최대 위치
	int child = 2;	//탐색 위치
	int parent = 1;	//변경할 위치

	*cnt -= 1;
	//두번째로 작은 값 탐색
	while(child <= *cnt)
	{
		//더 작은 값이 있으면 1을 더해 이동
		if(child < *cnt && room[child] > room[child + 1])
			child++;
		//마지막 값이 두번째로 작은 값보다 작으면 중단
		if(room[i] < room[child])
			break;
		//값 변경
		room[parent] = room[child];
		//기준 변경
		parent = child;
		//탐색 위치 이동
		child *= 2;
	}
	//빈자리에 마지막 값 저장
	room[parent] = room[i];
}

int			main(void)
{
	int		n;
	int		cnt;
	pair	*class;
	int		room[200000] = {0, };
	
	//강의 수 입력
	scanf("%d", &n);
	getchar();
	//동적할당
	if ((class = (pair *)malloc(sizeof(pair) * n)) == NULL)
		return (-1);
	//강의 시간 입력
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &class[i].start, &class[i].end);
		getchar();
	}
	//시작 기준으로 정렬
	qsort(class, n, sizeof(pair), cmp);
	//강의실 수 초기화
	cnt = 0;
	//첫번째 강의 추가
	push(room, &cnt, class[0].end);
	//두번째 강의부터
	for (int i = 1; i < n; i++)
	{
		//최소 종료시간 보다 시작 시간이 크거나 같은 경우,
		//최솟값을 지우기
		if (room[1] <= class[i].start)
			pop(room, &cnt);
		//종료시간 저장
		push(room, &cnt, class[i].end);
	}
	//강의실 수 출력
	printf("%d", cnt);
	//메모리 해제
	free(class);
	return (0);
}

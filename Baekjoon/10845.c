#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int				num;
	struct node*	next;
}node;

node	*new_node(int num){
	node	*tmp;

	tmp = (node *)malloc(sizeof(node));
	tmp->num = num;
	tmp->next = NULL;
	return tmp;
}

void	push(node **head, node **tail, node *new_node){
	if (*head == NULL){
		*head = new_node;
		*tail = *head;
	}
	else{
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

int		pop(node **head, node **tail){
	int		num;
	node	*tmp = NULL;

	if (*head == NULL)
		return -1;
	tmp = *head;
	num = tmp->num;
	*head = (*head)->next;
	if (!(*head))
		*tail = NULL;
	free(tmp);
	return num;
}

int		size(node *head){
	int		cnt;
	node	*tmp;

	cnt = 0;
	tmp = head;
	while (tmp){
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int		empty(node *head){
	if (head)
		return 0;
	return 1;
}

int		front(node *head){
	if (head)
		return (head->num);
	return (-1);
}

int		back(node *tail){
	if (tail)
		return (tail->num);
	return (-1);
}

void	clear(node **head){
	node *tmp;
	node *prev;

	tmp = *head;
	while (tmp){
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

int		main(void){
	int		n, m;
	char	str[10] = {0, };
	node	*head = NULL;
	node	*tail = NULL;

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++){
		scanf("%s", str);
		getchar();
		if (!strcmp(str, "push")){
			scanf("%d", &m);
			getchar();
			push(&head, &tail, new_node(m));
		}
		else if (!strcmp(str, "front"))
			printf("%d\n", front(head));
		else if (!strcmp(str, "back"))
			printf("%d\n", back(tail));
		else if (!strcmp(str, "empty"))
			printf("%d\n", empty(head));
		else if (!strcmp(str, "size"))
			printf("%d\n", size(head));
		else if (!strcmp(str, "pop"))
			printf("%d\n", pop(&head, &tail));
		for (int j = 0; j < 10; j++)
			str[j] = 0;
	}
	clear(&head);
	return 0;
}

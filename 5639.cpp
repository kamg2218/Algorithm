#include <iostream>

using namespace std;

typedef struct node{
	int				content;
	int				print;
	struct node*	prev;
	struct node*	left_next;
	struct node*	right_next;
}t_node;

t_node	*new_node(int value){
	t_node*	tmp;

	tmp = new t_node;
	tmp->content = value;
	tmp->prev = 0;
	tmp->left_next = 0;
	tmp->right_next = 0;
	return tmp;
}

void			insert(t_node **head, t_node *new_node)
{
	t_node		*tmp;

	cout << "insert = " << new_node->content << endl;
	tmp = *head;
	if (tmp == NULL)
	{
		*head = new_node;
		return ;
	}
	while (tmp)
	{
		if (new_node->content > tmp->content)
		{
			if (tmp->right_next == NULL)
				break ;
			tmp = tmp->right_next;
		}
		else
		{
			if (tmp->left_next == NULL)
				break ;
			tmp = tmp->left_next;
		}
	}
	if (new_node->content > tmp->content)
		tmp->right_next = new_node;
	else
		tmp->left_next = new_node;
	new_node->prev = tmp;
}

void	traverse(t_node* head){
	if (head->left_next)
		traverse(head->left_next);
	if (head->right_next)
		traverse(head->right_next);
	cout << head->content << endl;
}

int		main(){
	int			num;
	t_node*		head = NULL;

	while (cin >> num){
		insert(&head, new_node(num));
	}
	traverse(head);
	return 0;
}

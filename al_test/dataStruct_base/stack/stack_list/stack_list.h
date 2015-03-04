#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

#define offsetof(TYPE, MEMBER) ((size_t) &(((TYPE *)0)->MEMBER))
#define container_of(ptr, type, member) ({	\

			(type *)((char *)__mptr - offsetof(type, member));})
#define list_entry(ptr, type, member) container_of(ptr, type, member)
#define list_for_each_entry(pos, head, member) \
		for (pos = list_entry((head)->next, typeof(*pos), member);	\
			&pos->member != (head);	\
			pos = list_entry(pos->member.next, typeof(*pos), member))
#define list_for_each_entry_safe(pos, n, head, member) \
		for (pos = list_entry((head)->next, typeof(*pos), member),	\
			n = list_entry(pos->member.next, typeof(*n), member);	\
			&pos->member != (head);	\
			pos = n, n = list_entry(n->member.next, typeof(*n),member))

struct list_head
{
	struct list_head *next;
};

typedef int ELEMENT_TYPE;
struct stack_node
{
	ELEMENT_TYPE element;
	struct list_head list;
};

int stack_empty(struct stack_node *stack);
struct stack_node *create_stack(void);
void free_stack(struct stack_node *stack);
void make_stack_empty(struct stack_node *stack);
void stack_push(ELEMENT_TYPE x, struct stack_node *stack);
ELEMENT_TYPE stack_top(struct stack_node *stack);
void stack_pop(struct stack_node *stack);

#endif


#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H
#include <stdlib.h>
struct list_head
{
	struct list_head *prev, *next;
};

typedef int node_type;
struct double_node
{
	node_type element;
	struct list_head list;
};

#define offsetof(TYPE, MEMBER) ((size_t) &(((TYPE *)0)->MEMBER))
#define container_of(ptr, type, member) ({	\
			const typeof(((type *)0)->member) *__mptr = (ptr);	\
			(type *)((char *)__mptr - offsetof(type, member)); })
#define list_entry(ptr, type, member) container_of(ptr, type, member)
#define list_for_each_entry(pos, head, member) \
		for (pos = list_entry((head)->next, typeof(*pos), member);	\
			&pos->member != (head);	\
			pos = list_entry(pos->member.next, typeof(*pos), member))
#define list_for_each_entry_safe(pos, n, head, member)			\
		for (pos = list_entry((head)->next, typeof(*pos), member),	\
							n = list_entry(pos->member.next, typeof(*pos), member);	\
						     &pos->member != (head);					\
						     pos = n, n = list_entry(n->member.next, typeof(*n), member))


#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

void INIT_LIST_HEAD(struct list_head *list)
{
	list->prev = list;
	list->next = list;
}

static inline void __list_add(struct list_head *new,
			struct list_head *prev,
			struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	prev->next = next;
	next->prev = prev;
}

static inline void __list_del_entry(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_head *entry)
{
	__list_del_entry(entry);
	entry->prev = NULL;
	entry->next = NULL;
}
	
static inline void list_replace(struct list_head *old, struct list_head *new)
{
	new->next = old->next;
	new->next->prev = new;
	new->prev = old->prev;
	new->prev->next = new;
}

static inline void list_replace_init(struct list_head *old, struct list_head *new)
{
	list_replace(old, new);
	INIT_LIST_HEAD(old);
}

static inline void list_del_init(struct list_head *entry)
{
	__list_del_entry(entry);
	INIT_LIST_HEAD(entry);
}

static inline void list_move(struct list_head *list, struct list_head *head)
{
	__list_del_entry(list);
	list_add(list, head);
}

static inline void list_move_tail(struct list_head *list, struct list_head *head)
{
	__list_del_entry(list);
	list_add_tail(list, head);
}

static inline int list_is_last(struct list_head *list, struct list_head *head)
{
	return list->next == head;
}

static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

static inline int list_empty_careful(const struct list_head *head)
{
	struct list_head *next = head->next;
	return (next == head) && (next == head->prev);
}

static inline void list_rotate_left(struct list_head *head)
{

}

static inline int list_is_singular(struct list_head *head)
{
	return !list_empty(head) && (head->next == head->prev);
}

static inline void __list_cut_position(struct list_head *list,
			struct list_head *head, struct list_head *entry)
{
	struct list_head *new_first = entry->next;
	list->next = head->next;
	list->next->prev = list;
	list->prev = entry;
	entry->next = list;
	
	head->next = new_first;
	new_first->prev = head;
}

static inline void list_cut_position(struct list_head *list,
			struct list_head *head, struct list_head *entry)
{
	if (list_empty(head))
		return;
	
	if (list_is_singular(head) 
				&& (head->next != entry && head != entry))
		return;
	
	if (entry == head)
		INIT_LIST_HEAD(list);
	else
		__list_cut_position(list, head, entry);
}

static inline void __list_splice(struct list_head *list,
			struct list_head *prev, struct list_head *next)
{
	struct list_head *first = list->next;
	struct list_head *last = list->prev;

	list->prev = prev;
	prev->next = list;

	last->next = next;
	next->prev = last;
}

static inline void list_splice(struct list_head *list, 
			struct list_head *head)
{
	if (!list_empty(head))
		__list_splice(list, head, head->next);
}

static inline void list_splice_init(struct list_head *list,
			struct list_head *head)
{
	if (!list_empty(head)) {
		__list_splice(list, head, head->next);
		INIT_LIST_HEAD(list);
	}
}

static inline void list_splice_tail_init(struct list_head *list,
			struct list_head *head)
{
	if (!list_empty(head)) {
		__list_splice(list, head->prev, head);
		INIT_LIST_HEAD(list);
	}
}

struct double_node *alloc_double_node(void)
{
	struct double_node *node;
	node = (struct double_node *)malloc(sizeof(struct double_node));
	if (NULL == node)
		printf("alloc node fail!\n");

	return node;
}

void free_double_list(struct list_head *head)
{
	struct double_node *node, *tmp_node;

	list_for_each_entry_safe(node, tmp_node, head, list) {
		list_del(&node->list);
		free(node);
	}
}

#endif
	

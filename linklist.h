#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef struct list List;

struct list {
	int id;
	int data;
	List* next;
};

List* create_list(int count);

void show_list(List* list);

List* find_node(List* list, int find_data);

List* find_node_pos(List* list, int find_pos);

int inset_node(List* list, int pos, int data);

int delete_node(List* list, int data);

#endif /* __LINKLIST_H__ */
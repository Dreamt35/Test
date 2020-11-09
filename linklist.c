#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/* Head insertion */
List* create_list(int count)
{
	int id;
	int data;
	int i;
	List *node, *head;

	head = (List*)malloc(sizeof(List));
	if (!head) {
		printf("alloc fail\n");
		return NULL;
	}
	head->next = NULL;

	for (i = 0; i < count; i++) {
		scanf_s("%d", &data);
		node = (List*)malloc(sizeof(List));
		if (!node) {
			printf("alloc fail\n");
			return NULL;
		}

		node->id = i;
		node->data = data;
		node->next = head->next;
		head->next = node;
	}

	return head;
}

void show_list(List *list)
{
	List* temp_list = list->next;

	while (temp_list != NULL) {
		printf("%d\t", temp_list->data);
		temp_list = temp_list->next;
	}

	printf("\n");
}

List* find_node(List* list, int find_data)
{
	List* temp_list = list->next;

	while (temp_list != NULL && temp_list->data != find_data)
		temp_list = temp_list->next;

	return temp_list;
}

List* find_node_pos(List* list, int find_pos)
{
	List* node;
	int i = 0;

	if (find_pos == 0)
		return list;

	if (find_pos < 1)
		return NULL;
	node = list;
	while (node && i < find_pos) {
		node = node->next;
		i++;
	}

	if (node == NULL) {
		printf("out of range!\n");
		return NULL;
	}

	return node;
}

int inset_node(List* list, int pos, int data)
{
	List* node;
	List* new_node;

	new_node = (List*)malloc(sizeof(List));
	if (!new_node) {
		printf("alloc fail!\n");
		return -1;
	}

	new_node->data = data;
	node = find_node_pos(list, pos - 1);
	new_node->next = node->next;
	node->next = new_node;

	return 0;
}

/* Delete the next node of the node with data = 4 */
int delete_node(List* list, int data)
{
	List* node;
	List* temp;

	node = find_node(list, data);

	temp = node->next;
	node->next = temp->next;

	free(temp);
}
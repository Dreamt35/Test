#include "linklist.h"

int main()
{
	List *testlink;
	List* node3;

	testlink = create_list(5);

	show_list(testlink);

	node3 = find_node(testlink, 3);

	printf("node3:%d\n", node3->data);

	inset_node(testlink, 3, 100);

	show_list(testlink);

	delete_node(testlink, 4);

	show_list(testlink);
	return 0;
}

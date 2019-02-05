#define 	STACK_SIZE_LIMIT   3
#include "stack.h"
struct Product{
  int serial_no;
};
typedef struct DepotImplementation* Depot;

Depot 	create_depot ();

void 	delete_depot (Depot depot);

void 	push_depot (Depot depot, Product *product);

int get_count (Depot depot);

Product* pop_depot (Depot depot);

#include "depot.h"
#include <stdlib.h>
#include "memcheck.h"
struct DepotImplementation{
  Stack stack;
};

Depot create_depot(){
  Depot newdepot = (Depot)smalloc(sizeof(DepotImplementation));
  newdepot->stack = create_stack();
  return newdepot;
}

void 	delete_depot (Depot depot){
  if (depot->stack != 0) {
    delete_stack(depot->stack);
    sfree(depot);
  }
}

void 	push_depot (Depot depot, Product *product){
  if (depot->stack != 0) {
    push_stack(depot->stack,product);
  }
  
}

int get_count (Depot depot){
  return get_count(depot->stack);
}

Product* pop_depot (Depot depot){
  return (Product*)pop_stack(depot->stack);
}

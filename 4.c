#include <stdio.h>
#include <stdlib.h>


struct zona{
    int size;
    struct zona* ponteiro_next;
};


char heap[16024];

struct zona* free_list;

void meminit(void){
   free_list = &heap;
   free_list->size = 16024;
   free_list->ponteiro_next = 0;
}


int main(){
    return 0;
}

#ifdef
char tap[tamanho];

int next_size = 0;


    
void * memalloc(int size){

    if (next_size + size > tamanho){
        printf("ERREUR");
        exit(1);
    }

   void* ptr = &tap[next_size];

   next_size += size;

    return ptr

}


   



void memfree(void *);

#endif









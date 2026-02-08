```c
void* alligned_malloc(size_t required_size, size_t alligned_size) {
    void* p1;
    void** p2;
    size_t offset = alligned_size - 1 + sizeof(void*);
    p1 = (void*)malloc(required_size + offset);
    if(p1) {
        p2 = (void**)(((size_t)p1 + offset) & ~(alligned_size - 1));
        p2[-1] = p1;
        return p2;
    }
    else {
        return NULL;
    }
}

void alligned_free(void* alligned_ptr) {
//    void** p2 = (void**)alligned_ptr;
//    void* p1 = p2[-1];
//    free(p1);
    free(((void**)alligned_ptr)[-1]);
}
```
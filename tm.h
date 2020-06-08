#ifndef TM_H_
# define TM_H_

// Init Tiny Malloc
int tm_init(char* mem, int mem_size, int block_size);

// Get Memory
void* tm_malloc(void);

// Free previous given memory block
void tm_free(void* data);

// Print stat on memory usage
void tm_stats(void);

#endif //! !TM_H_

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

//using double linked list data structure
struct map{
	unsigned long m_size;
	char* m_addr;
	struct map *next, *prior;
};

typedef struct map Map;
//Map memFree

typedef struct map_mem_manage
{
    Map *mem_now;
    char *m_start_addr;
    unsigned long m_rest;
    unsigned long m_size;
    unsigned long m_free_count;//count of free space
} Manage;

//initialize the memory
void initMemManage(Manage *mem_manager, unsigned long size, char *addr);
//allocate algorithm
void lmalloc(Manage *mem_manager, unsigned long size);
//recycle algorithm
void lfree(Manage *mem_manager, unsigned long size, char *addr);
//show free block status
void printFree(Manage *mem_manager);
//print error...
void printError(char *str);
//show current status
void printMemFree(Manage *mem_manager, Map *mem_free);
//related information
void printDeclaration();


int main(){
    // create mem_manager and malloc 1024B for operation
    Manage *mem_manager = (Manage *)malloc(sizeof(Manage));
    char *mem_addr = (char *)malloc(MAX_SIZE * sizeof(int));
    char *tmp_addr;

    // allocate space to initialize
    initMemManage(mem_manager, MAX_SIZE, mem_addr);

    // judge input
    char command_char;// input mode(F/f,M/m)
    unsigned long size;// input size
    unsigned long addr;// input address
    while (scanf("%c", &command_char))
    {
        if (command_char == 'm')
        {
            scanf("%lu", &size);
            printf("=============================================\n");
            printf("command:%calloc,size:%lu\n", command_char, size);
            lmalloc(mem_manager, size);
            printf("================the rest mem :===============\n");
            printFree(mem_manager);
            printf("=============================================\n\n");
            getchar();
            //printf("command_char:%csize:%lu\n",command_char,size);
        }
        if (command_char == 'f')
        {
            scanf("%lu %lu", &size, &addr);
            getchar();
            tmp_addr = mem_addr + addr;
            printf("=============================================\n");
            printf("command:l%cree,addr:%lu,size:%lu\n", command_char, mem_addr + addr, size);
            lfree(mem_manager, size, tmp_addr);
            printf("================the rest mem :===============\n");
            printFree(mem_manager);
            printf("=============================================\n\n");
        }
        if (command_char == 'e')
        {
            printf("exit\n");
            break;
        }
    }
    printDeclaration();
    Map *tmp;
    Map *ptr = mem_manager->mem_now;
    for(int i=0;i<(mem_manager->m_free_count-1);++i){
        tmp = ptr->next;
        free(ptr);
        ptr=tmp;
    }
    free(ptr);
    free(mem_manager);
    fclose(stdin);
    fclose(stdout);
    return 0;
}


/**
 * @brief initMemManage
 * @param mem_manager
 * @param size
 * @param addr // initial address
 */
void initMemManage(Manage *mem_manager, unsigned long size, char *addr)
{
    Map *mem_free = (Map *)malloc(sizeof(Map));
    mem_free->m_addr = addr;
    mem_free->m_size = size;
    mem_free->next = mem_free;
    mem_free->prior = mem_free;
    mem_manager->mem_now = mem_free;
    mem_manager->m_start_addr = addr;
    mem_manager->m_rest = size;
    mem_manager->m_size = size;
    mem_manager->m_free_count = 1;
}


/**
 * @brief lmalloc: allocate memory
 * @param mem_manager
 * @param size
 */
void lmalloc(Manage *mem_manager, unsigned long size)
{
    /*  
    *  case0:  Boundary conditions: no enough space (more than 1024B)
    *          Nothing to change
    */
    if (size > mem_manager->m_rest)
    {
        printError("======no more free size!!=========");
        return;
    }

    int count = 1;
    Map *ptr = mem_manager->mem_now;
    char *tmp_addr = ptr->m_addr;
    while (ptr)
    { 
        /*  
        *  case1:  The memory to be allocated is larger than the current free block
        *          But there is still enough space in total;
        *          Nothing to change
        */
        if (ptr->m_addr == tmp_addr)
        {
            if ((count--) == 0)
            {
                printError("can not find fitable field;");
                break;
            }
        }

        /*  
        *  case2:  The memory to be allocated is smaller than the current free block
        *          Change the start address of the free block;
        *          Make some modifications to the value in the memory manager.
        */
        if (size < (ptr->m_size))
        {
            ptr->m_addr += size;
            ptr->m_size -= size;
            mem_manager->m_rest -= size;
            mem_manager->mem_now = ptr;
            //printFree(mem_manager);
            break;
        }
        /*
        *  case3:  The memory to be allocated is exactly equal to the current free block
        *          Remove the current free block from the linked list;
        *          Make some modifications to the value in the memory manager;
        */
        else if (size == (ptr->m_size))
        {
            Map *tmp = ptr;
            mem_manager->mem_now = ptr->next;
            tmp->prior->next = tmp->next;
            tmp->next->prior = tmp->prior;
            free(tmp);
            mem_manager->m_rest -= size;
            mem_manager->m_free_count -= 1;
            break;
        }

        else
        {
            ptr = ptr->next;
        }
    }
}

/**
 * @brief lfree: recycle memory 
 * @param mem_manager
 * @param size
 * @param addr
 */
void lfree(Manage *mem_manager, unsigned long size, char *addr)
{
    if (size == 0)
    {
        printError("no size;");
        return;
    }
    if (addr < mem_manager->m_start_addr)
    {
        printError("too low;");
        return;
    }
    if (addr > mem_manager->m_start_addr + mem_manager->m_size)
    {
        printError(" too high;");
        return;
    }
    if ((addr + size) > (mem_manager->m_start_addr + mem_manager->m_size))
    {
        printError("too high;");
        return;
    }
    if(mem_manager->m_rest==0){
        Map *mem_free = (Map *)malloc(sizeof(Map));
        mem_free->m_addr = addr;
        mem_free->m_size = size;
        mem_free->next = mem_free;
        mem_free->prior = mem_free;
        mem_manager->mem_now = mem_free;
        mem_manager->m_rest = size;
        mem_manager->m_free_count = 1;
        return;
    }
    Map *ptr = mem_manager->mem_now;
    Map *pre;
    Map *m_next;
    if (addr < ptr->m_addr)
    {
        while (ptr->prior->m_addr >= addr && (ptr->prior->m_addr) < ptr->m_addr)
        {
            ptr = ptr->prior;
        }
        if (ptr->m_addr == addr)
        {
            printError("error: addr overlay");
            return;
        }
        if ((addr > ptr->prior->m_addr && addr < ptr->prior->m_addr + ptr->prior->m_size) || (addr + size) > ptr->m_addr)
        {
            printError("error:addr overlay");
            return;
        }
        else if (addr > ptr->prior->m_addr && addr == ptr->prior->m_addr + ptr->prior->m_size)
        {
            if ((addr + size) < ptr->m_addr)
            {
                pre = ptr->prior;
                pre->m_size += size;
                mem_manager->m_rest += size;
            }
            else if ((addr + size) == ptr->m_addr)
            {
                pre = ptr->prior;
                pre->prior->next = ptr;
                ptr->prior = pre->prior;
                ptr->m_addr = pre->m_addr;
                ptr->m_size = pre->m_size + size;
                mem_manager->m_rest += size;
                mem_manager->m_free_count -= 1;
                free(pre);
            }
        }
        else if ((addr + size) == ptr->m_addr)
        {
            ptr->m_addr -= size;
            ptr->m_size += size;
            mem_manager->m_rest += size;
        }
        else
        {
            Map *new_mem_free = (Map *)malloc(sizeof(Map));
            new_mem_free->m_addr = addr;
            new_mem_free->m_size = size;
            new_mem_free->next = ptr;
            new_mem_free->prior = ptr->prior;
            ptr->prior->next = new_mem_free;
            ptr->prior = new_mem_free;
            mem_manager->m_rest += size;
            mem_manager->m_free_count += 1;
            return;
        }
    }

    else if (addr > ptr->m_addr)
    {
        while (ptr->next->m_addr <= addr && (ptr->next->m_addr) > ptr->m_addr)
        {
            ptr = ptr->next;
        }
        if (ptr->m_addr == addr)
        {
            printError("error: addr overlay");
            return;
        }
        if ((addr < ptr->next->m_addr && (addr + size) > ptr->next->m_addr) || (addr) < (ptr->m_addr + ptr->m_size))
        {
            printError("error:addr overlay");
            return;
        }
        else if (addr < ptr->next->m_addr && (addr + size) == ptr->next->m_addr)
        {
            if (addr > (ptr->m_addr + ptr->m_size))
            {
                pre = ptr->next;
                pre->m_addr -= size;
                pre->m_size += size;
                mem_manager->m_rest += size;
            }
            else if (addr == (ptr->m_addr + ptr->m_size))
            {
                pre = ptr->next;
                pre->next->prior = ptr;
                ptr->next = pre->next;
                ptr->m_size = pre->m_size + size;
                mem_manager->m_rest += size;
                mem_manager->m_free_count -= 1;
                free(pre);
            }
        }
        else if (addr == (ptr->m_addr + ptr->m_size))
        {
            ptr->m_size += size;
            mem_manager->m_rest += size;
        }
        else
        {
            Map *new_mem_free = (Map *)malloc(sizeof(Map));
            new_mem_free->m_addr = addr;
            new_mem_free->m_size = size;
            new_mem_free->prior = ptr;
            new_mem_free->next = ptr->next;
            ptr->next->prior = new_mem_free;
            ptr->next = new_mem_free;
            mem_manager->m_rest += size;
            mem_manager->m_free_count += 1;
            return;
        }
    }
    
    else
    {
        printError("error:addr overlay");
        return;
    }
}



void printFree(Manage *mem_manager)
{
    if (mem_manager->m_rest == 0)
    {
        printf("===============start print!!================\n");

        printf("==============no free print!!================\n");
        printf("==============finish print!!=================\n");
        return;
    }
    Map *ptr = mem_manager->mem_now;
    char *flag_addr = ptr->m_addr;
    int count = 1;
    printf("==============start print!!=================\n");

    printf("==============number of free:%lu===============\n", mem_manager->m_free_count);
    printf("============all size of free:%lu=============\n", mem_manager->m_rest);
    while (1)
    {
        if (ptr->m_addr == flag_addr)
        {
            if ((count--) == 0)
            {
                printf("==============finish print!!=================\n");
                break;
            }
        }
        printMemFree(mem_manager, ptr);
        ptr = ptr->next;
    }
}
void printError(char *str)
{
    printf("error:%s\n", str);
}

void printMemFree(Manage *mem_manager, Map *mem_free)
{
    printf("=============================================\n");
    printf("addr:%lu\nsize:%lu\n", mem_free->m_addr - mem_manager->m_start_addr, mem_free->m_size);
    printf("=============================================\n");
}

void printDeclaration()
{
    printf("=============================================\n");
    printf("===============end program!!===============\n");
    printf("===========519021910917 feiyang===========\n");
    printf("=============================================\n");
}
#define CreateBookNode(p) p=(Book *)malloc(sizeof(Book));
#define CreateUserNode(p) p=(User *)malloc(sizeof(User));
#define DeleteNode(p) free((void *)p);

#include "book_management.h"
#include "interface.h"


char username[40];
_Bool login = 0;
BookList library;

int main(){
    interface();
    return 0;
}

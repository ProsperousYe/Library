app:main.o interface.o user.o book_management.o librarian.o visitor.o
	gcc main.o interface.o user.o book_management.o librarian.o visitor.o -o app

main.o:main.c
	gcc -c main.c

interface.o:interfce.c
	gcc -c interface.c

book_management.o:book_management.c
	gcc -c book_management.c

librarian.o:librarian.c
	gcc -c librarian.c

visitor.o:visitor.c
	gcc -c visitor.c

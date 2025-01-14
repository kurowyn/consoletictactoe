CC=gcc
compile: main.c cttt.c
  @$(CC) cttt.c main.c -o cttt

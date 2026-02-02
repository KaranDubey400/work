shared memory, multi threaded  processing system written in C

two processes producer and consumer pattern , both using same shared memory 

both have multiple threads , producer have writer, updater and clearner
while here  consumer only do everything in read mode , so it have snapshot, query and watchdog threads 

pthreads locks (reader writer lock we used )
and mutex 


we worked in a group, we brainstormed the soltuion , wrote algo and psuedocode to write the bug free code 
implemented shared memory , also we used indexing instead of pointers , used linked list data structure 

list for events node and free list which have free nodes which can be used to fill data
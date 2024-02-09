CC = gcc
FLAGS = -Wall -g
OBJECTS_MY_GRAPH = my_graph.o my_mat.o
OBJECTS_MY_KNAPSACK = my_Knapsack.o 
AR = ar

all: my_graph my_Knapsack

# my_Knapsack part:
my_Knapsack: $(OBJECTS_MY_KNAPSACK) 
	$(CC) $(FLAGS) -o $@ $^


# my_graph part:

my_graph: $(OBJECTS_MY_GRAPH)
	$(CC) $(FLAGS) -o $@ $^

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o my_graph my_Knapsack
	
a.out: main.cc tree.h bst_wrapper.h
	g++ -g -std=c++2a -fsanitize=address main.cc -lcurl -lbridges

clean:
	rm -f a.out *.o

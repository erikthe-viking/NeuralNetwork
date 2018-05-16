all: brain

brain: main.o neuron.o net.o train.o
	g++ -std=c++11 main.o neuron.o net.o train.o -o brain

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

nueron.o: neuron.cpp neuron.h
	g++ -std=c++11 -c neuron.cpp

net.o: net.cpp net.h
	g++ -std=c++11 -c net.cpp 

train.o: train.cpp train.h
	g++ -std=c++11 -c train.cpp 

clean:
	rm -rf *.o brain

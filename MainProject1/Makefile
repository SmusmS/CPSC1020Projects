COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.cpp

all: #(PROGRAM)

run: $(PROGRAM)
	 ./$(PROGRAM)

$(PROGRAM): main.cpp calcDays.cpp Date.cpp
	$(COMPILER) $(OPTIONS) main.cpp calcDays.cpp Date.cpp -o $(PROGRAM)

clean:
	rm *.out
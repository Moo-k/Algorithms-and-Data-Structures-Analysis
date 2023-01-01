output: Player.o Human.o Computer.o Referee.o FistfullODollars.o RandomComputer.o Avalanche.o Bureaucrat.o Toolbox.o Crescendo.o PaperDoll.o Tournament.o main.o
	g++ Player.o Human.o Computer.o Referee.o FistfullODollars.o RandomComputer.o Avalanche.o Bureaucrat.o Toolbox.o Crescendo.o PaperDoll.o Tournament.o main.o -o output

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Human.o: Human.cpp Human.h
	g++ -c Human.cpp

Computer.o: Computer.cpp Computer.h
	g++ -c Computer.cpp

Referee.o: Referee.cpp Referee.h
	g++ -c Referee.cpp

FistfullODollars.o: FistfullODollars.cpp FistfullODollars.h
	g++ -c FistfullODollars.cpp

RandomComputer.o: RandomComputer.cpp RandomComputer.h
	g++ -c RandomComputer.cpp

Avalanche.o: Avalanche.cpp Avalanche.h
	g++ -c Avalanche.cpp

Bureaucrat.o: Bureaucrat.cpp Bureaucrat.h
	g++ -c Bureaucrat.cpp

Toolbox.o: Toolbox.cpp Toolbox.h
	g++ -c Toolbox.cpp

Crescendo.o: Crescendo.cpp Crescendo.h
	g++ -c Crescendo.cpp

PaperDoll.o: PaperDoll.cpp PaperDoll.h
	g++ -c PaperDoll.cpp

Tournament.o: Tournament.cpp Tournament.h
	g++ -c Tournament.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o output
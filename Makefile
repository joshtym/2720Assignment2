CFLAGS = -I /home/lib2720/allegro5/include/ -I /usr/include
LIBDIR = -L /home/lib2720/allegro5/lib -L /usr/lib
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
OBJECTS = Simulator.o Triangle.o Square.o Circle.o ShapeContainer.o main.o MySimulator.o Shape.o Display.o

animatedShapes: $(OBJECTS)
	g++ $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : %.cc
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f animatedShapes

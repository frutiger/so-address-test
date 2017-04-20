all: app/app

factory/factory.o: factory/factory.h factory/factory.cpp
	c++ -fPIC \
	    -c -o$@ \
	    -Ifactory \
	    factory/factory.cpp

1/lib1.o: 1/lib1.h 1/lib1.cpp
	c++ -fPIC \
	    -c -o$@ \
	    -Ifactory -I1 \
	    1/lib1.cpp

2/lib2.o: 2/lib2.h 2/lib2.cpp
	c++ -fPIC \
	    -c -o$@ \
	    -Ifactory -I2 \
	    2/lib2.cpp

app/app.m.o: app/app.m.cpp
	c++ \
	    -c -o$@ \
	    app/app.m.cpp

1/lib1.so: 1/lib1.o factory/factory.o
	c++ -shared \
	    -o$@ \
	    1/lib1.o factory/factory.o

2/lib2.so: 2/lib2.o factory/factory.o
	c++ -shared \
	    -o$@ \
	    2/lib2.o factory/factory.o

app/app: app/app.m.o 1/lib1.so 2/lib2.so
	c++ \
	    -o$@ \
	    app/app.m.o \
	    -ldl

clean:
	rm -f factory/factory.o \
	    1/lib1.o 1/lib1.so \
	    2/lib2.o 2/lib2.so \
	    app/app.m.o app/app

.PHONY: clean


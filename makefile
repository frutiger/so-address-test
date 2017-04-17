all: factory/libfactory.so 1/lib1.so 2/lib2.so app/app

factory/libfactory.so: factory/factory.o
	c++ -shared \
	    -ofactory/libfactory.so \
	    factory/factory.o

factory/factory.o: factory/factory.h factory/factory.cpp
	c++ -fPIC \
	    -c -ofactory/factory.o \
	    -Ifactory \
	    factory/factory.cpp

1/lib1.so: 1/lib1.o factory/libfactory.so
	c++ -shared \
	    -o1/lib1.so \
	    -Wl,-rpath=factory -Lfactory \
	    1/lib1.o -lfactory

1/lib1.o: 1/lib1.h 1/lib1.cpp
	c++ -fPIC \
	    -c -o1/lib1.o \
	    -Ifactory -I1 \
	    1/lib1.cpp

2/lib2.so: 2/lib2.o factory/libfactory.so
	c++ -shared \
	    -o2/lib2.so \
	    -Wl,-rpath=factory -Lfactory \
	    2/lib2.o -lfactory

2/lib2.o: 2/lib2.h 2/lib2.cpp
	c++ -fPIC \
	    -c -o2/lib2.o \
	    -Ifactory -I2 \
	    2/lib2.cpp

app/app: app/app.m.o 1/lib1.so 2/lib2.so
	c++ -L1 -Wl,-rpath=1 -L2 -Wl,-rpath=2 app/app.m.o -l1 -l2 -oapp/app

app/app.m.o: app/app.m.cpp
	c++ \
	    -c -oapp/app.m.o \
	    -I1 -I2 \
	    app/app.m.cpp

clean:
	rm -f factory/factory.o factory/libfactory.so \
	    1/lib1.o 1/lib1.so \
	    2/lib2.o 2/lib2.so \
	    app/app.m.o app/app

.PHONY: clean


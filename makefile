CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJS = data.o node.o table.o appmgr.o app.o

app: $(OBJS)

app.o: data.o node.o table.o appmgr.o

appmgr.o: appmgr.h table.h node.h data.h

table.o: table.h node.h data.h

node.o: node.h data.h

data.o: data.h

clean: 
	rm *.o app

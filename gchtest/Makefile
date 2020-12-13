
srcs = $(wildcard *.cpp)
objs = $(srcs:%.cpp=%.o)

#all : check\
#    a.out
#
#
hehe := ${shell ./modi.sh}

all : a.out

$(objs) : %.o: %.cpp temp.h.gch
	g++ -H  -g -Winvalid-pch -c $< -o $@
a.out : $(objs) temp.h.gch
	g++ -H $(objs) -o $@ 

temp.h.gch : temp.h
	g++ -c -g $< 

clean: 
	@rm -rf a.out temp.h.gch *.o

check:
	@./modi.sh
	

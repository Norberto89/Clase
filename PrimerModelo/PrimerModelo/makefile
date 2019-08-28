SYSTEM     = x86-64_linux
LIBFORMAT  = static_pic


# When you adapt this makefile to compile your CPLEX programs
# please copy this makefile and set CPLEXDIR and CONCERTDIR to
# the directories where CPLEX and CONCERT are installed.
#
#------------------------------------------------------------


CPLEXDIR      = /opt/ibm/ILOG/CPLEX_Studio129/cplex
CONCERTDIR    = /opt/ibm/ILOG/CPLEX_Studio129/concert

# ---------------------------------------------------------------------
# Compiler selection 
# ---------------------------------------------------------------------

CCC = g++
CC  = gcc
JAVAC = javac

# ---------------------------------------------------------------------
# Compiler options 
# ---------------------------------------------------------------------

CCOPT = -DNDEBUG -DIL_STD -pthread -O3
COPT  = -xtarget=ultra -xarch=v9 -KPIC -pthread -O3
JOPT  = -classpath $(CPLEXDIR)/lib/cplex.jar -O

# ---------------------------------------------------------------------
# Link options and libraries
# ---------------------------------------------------------------------

CPLEXBINDIR   = $(CPLEXDIR)/bin/$(BINDIST)
CPLEXJARDIR   = $(CPLEXDIR)/lib/cplex.jar
CPLEXLIBDIR   = $(CPLEXDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR = $(CONCERTDIR)/lib/$(SYSTEM)/$(LIBFORMAT)

CCLNFLAGS = -L$(CPLEXLIBDIR) -lilocplex -lcplex -L$(CONCERTLIBDIR) -lconcert -lm -xarch=v9 -lnsl -ldl
CLNFLAGS  = -L$(CPLEXLIBDIR) -lcplex -lm -xarch=v9 -lnsl
JAVA      = java -d64 -Djava.library.path=$(CPLEXDIR)/bin/ultrasparc64_9_9 -classpath $(CPLEXJARDIR):


all:
	make all_cpp

execute: all
	make execute_cpp

CONCERTINCDIR = $(CONCERTDIR)/include
CPLEXINCDIR   = $(CPLEXDIR)/include

EXDIR         =  $(shell pwd)
EXSRC         = $(EXDIR)
EXINC         = $(EXDIR)
EXDATA        = $(EXDIR)

CFLAGS  = $(COPT)  -I$(CPLEXINCDIR)
CCFLAGS = $(CCOPT) -I$(CPLEXINCDIR) -I$(CONCERTINCDIR) 
JCFLAGS = $(JOPT)


#------------------------------------------------------------
#  make all      : to compile the examples. 
#  make execute  : to compile and execute the examples.
#------------------------------------------------------------


CPP_EX = main

all_cpp: $(CPP_EX)

execute_cpp: $(CPP_EX)
	 ./main

# ------------------------------------------------------------

clean :
	/bin/rm -rf *.o *~ *.class
	/bin/rm -rf $(C_EX) $(CPP_EX)
	/bin/rm -rf *.mps *.ord *.sos *.lp *.sav *.net *.msg *.log *.clp

# ------------------------------------------------------------
#
# The examples
#

main: main.o 
	$(CCC) $(CCFLAGS) main.o -o main $(CCLNFLAGS)
main.o: $(EXSRC)/main.cpp
	$(CCC) -c $(CCFLAGS) $(EXDIR)/ 	main.cpp -o main.o






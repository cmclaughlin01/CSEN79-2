#
# Curran McLaughlin <cmclaughlin2@scu.edu>
# For CSEN79 Exercise
# 

TMPMAKE=tmpMake
STD=-std=c++20
OPT=-g
CXXFLAGS=${STD} ${OPT}

# Source files and object files
RATNUM_SRCS=ratnum.cxx ratNumIntakeOp.cxx ratnummain.cxx
RATNUM_OBJS=$(RATNUM_SRCS:.cxx=.o)
EXAMINE_SRCS=examine.cxx
EXAMINE_OBJS=$(EXAMINE_SRCS:.cxx=.o)
ALL=ratnumTest examine

# Default target to build everything
all: $(ALL)

# Build the ratnumTest executable
ratnumTest: $(RATNUM_OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $^

# Build the examine executable
examine: $(EXAMINE_OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $^

# Compile each .cxx file to a corresponding .o object file
%.o: %.cxx
	$(CXX) -c $(CXXFLAGS) $<

# Clean up generated files
clean:
	/bin/rm -f $(RATNUM_OBJS) $(EXAMINE_OBJS) $(ALL) testdata.txt output.txt
	/bin/rm -rf $(ALL:=.dSYM)

# Generate dependencies automatically
depend: $(RATNUM_SRCS) $(EXAMINE_SRCS)
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
ratnum.o: ratnum.cxx ratnum.h
ratNumIntakeOp.o: ratNumIntakeOp.cxx ratnum.h ratNumIntakeOp.h
ratnummain.o: ratnummain.cxx ratnum.h ratNumIntakeOp.h
examine.o: examine.cxx

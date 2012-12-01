#!/bin/bash
# File: Makefile

bla: Args.o Instr.o InstrTypeRV.o Main.o TextSegment.o Operand.o Assembler.o InstrTypeB.o Integer.o Variable.o Register.o Binary.o InstrTypeR.o Label.o Segment.o DataSegment.o InstrTypeRI.o Lex.o TextSegment.o
	g++ Args.o Instr.o InstrTypeRV.o Main.o TextSegment.o Operand.o Assembler.o InstrTypeB.o Integer.o Variable.o Register.o Binary.o InstrTypeR.o Label.o Segment.o DataSegment.o InstrTypeRI.o Lex.o TextSegment.o -o bla
	rm -f *.o

Args.o: Args.cpp
	g++ -c Args.cpp

Instr.o: Instr.cpp
	g++ -c Instr.cpp

InstrTypeRV.o: InstrTypeRV.cpp
	g++ -c InstrTypeRV.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

TextSegment.o: TextSegment.cpp
	g++ -c TextSegment.cpp

Operand.o: Operand.cpp
	g++ -c Operand.cpp

Assembler.o: Assembler.cpp
	g++ -c Assembler.cpp

InstrTypeB.o: InstrTypeB.cpp
	g++ -c InstrTypeB.cpp

Integer.o: Integer.cpp
	g++ -c Integer.cpp

Variable.o: Variable.cpp
	g++ -c Variable.cpp

Register.o: Register.cpp
	g++ -c Register.cpp

Binary.o: Binary.cpp
	g++ -c Binary.cpp

InstrTypeR.o: InstrTypeR.cpp
	g++ -c InstrTypeR.cpp

Label.o: Label.cpp
	g++ -c Label.cpp

Segment.o: Segment.cpp
	g++ -c Segment.cpp

DataSegment.o: DataSegment.cpp
	g++ -c DataSegment.cpp

InstrTypeRI.o: InstrTypeRI.cpp
	g++ -c InstrTypeRI.cpp

Lex.o: Lex.cpp
	g++ -c Lex.cpp

TextSegment.o: TextSegment.cpp
	g++ -c TextSegment.cpp
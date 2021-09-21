all: DominoView DominoController DominoModel DominoApp DominoData     

DominoModel: DominoModel.c DominoModel.h
	gcc -c DominoModel.c
DominoData: DominoData.c DominoData.h
	gcc -c DominoData.c
DominoView: DominoView.c DominoView.h
	gcc -c DominoView.c
DominoController: DominoController.c DominoController.h
	gcc -c DominoController.c

DominoApp: DominoApp.c DominoView.o DominoController.o DominoModel.o DominoData.o     
	gcc -g -o Domino DominoApp.c DominoController.o DominoModel.o DominoView.o DominoData.o

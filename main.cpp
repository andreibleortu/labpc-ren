#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int nrLab = 1;

char charPCName[100], charPCID[5], renameCommand[100], inPath[50], outPath[50], deleteCommand[100], moveCommand[100], charLabID[5];

void generatePaths()
{
	snprintf(charLabID, 5, "%d", nrLab);
	strcat(inPath, "Z:\\lab");
	strcat(inPath, charLabID);
	strcat(inPath, ".txt");

	strcat(outPath, "Z:\\lab");
	strcat(outPath, charLabID);
	strcat(outPath, ".tmp");
}
void mountSMB()
{
	system("net use Z: \\\\STORAGE\\deploynaming");
}
void unmountSMB()
{
	system("net use Z: /delete");
}
void changeName(int crtPCID)
{
	snprintf(charPCID, 5, "%d", crtPCID);
	strcpy(charPCName, "LAB");
	strcat(charPCName, charLabID);
	strcat(charPCName, "-");
	strcat(charPCName, charPCID);
	strcat(renameCommand, "Rename-Computer -NewName \"");
	strcat(renameCommand, charPCName);
	strcat(renameCommand, "\" ");
	system(renameCommand);
}
void flushCounter()
{
	strcpy(deleteCommand, "del ");
	strcat(deleteCommand, inPath);

	strcpy(moveCommand, "move ");
	strcat(moveCommand, outPath);
	strcat(moveCommand, " ");
	strcat(moveCommand, inPath);

	system(deleteCommand);
	system(moveCommand);
}
int main()
{
	mountSMB();
	generatePaths();
	ifstream fin(inPath);
	ofstream fout(outPath);
	int lastPCID;
	fin >> lastPCID;
	lastPCID++;
	changeName(lastPCID);
	fout << lastPCID;
	fin.close();
	fout.close();
	flushCounter();
	unmountSMB();
}
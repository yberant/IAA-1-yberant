#include<stdlib.h>
#include<ctime>
#include<cmath>
#include<cstddef>
#include<iterator>
#include<algorithm> 
#include<fstream>
#include<chrono>
#include<iostream>
#include<vector>
#include <cstdlib>

using namespace::std;

int n;
vector<vector<double>> D;

void printMatrix(vector<vector<int>> M);
void printVector(vector<int> v);
vector<vector<int>> transpose(vector<vector<int>> M);
void swapElements(vector<vector<int>> &M, int x1, int y1,int x2,int y2);
void insertGame(vector<vector<int>> & S, int Ti, int Tj, int r);
vector<int> rotateVector(vector<int> teams, int permutation);
vector<vector<int>> DoubleRoundRobin();

double scheduleDistance(vector<vector<int>> S);
double teamScheduleDistance(vector<vector<int>> S, int j);
double distance(int i, int j);
void atMostConflicts(vector<vector<int>> S, vector<int> & conflictedRows, vector<int> & conlfictedColumns);
void noRepeatConflicts(vector<vector<int>> S, vector<int> & conflictedRows, vector<int> & conlfictedColumns);
int conflictsCount(vector<vector<int>>S);

void add(vector<int> & arr, int value);
void addValues(vector<int> & arr, vector<int> & values);
void resetVector(vector<int> & v);
int totalConflicts(vector<vector<int>> S);

void swapRounds(vector<vector<int>> & S, int i, int j);
void swapTeams(vector<vector<int>> & S, int i, int j);


int greedyFix(vector<vector<int>> & S);
bool updateBest(vector<vector<int>> candidateS,vector<vector<int>> & bestS,int & bestConflicts, double & bestDistance);



/*



*/


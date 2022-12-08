#ifndef __FUNCTIONS_ARRAY_H__
#define __FUNCTIONS_ARRAY_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "Game_Defaults.h"

// the only things a grid struct at any location XY needs to store is,
// 1: the index of the boat, if any, and if it's NO_BOAT, there is no boat there...
// 2: if somebody (you or the computer, there are 2 grids) have guessed this location or not

struct GridData
{
	// a guess at an xy location that has no boat there, will have boatIndex = NO_BOAT and guessed = true
	int boatIndex; // 0-based boat index
	bool guessed;
} GridPoint;

struct BoatInfo
{
	int index; // which index in the array is it
	int x;
	int y;
	int len;
	int isHorz;
	int sunk;
};

struct Grid
{
	struct GridData* m_pArray;
	struct BoatInfo m_Boats[BoatCount];
};

struct Grid* CreateGrid();
void DestroyGrid(struct Grid* pGrid);
void GetGridDataAtXY(struct Grid* pGrid, int x, int y, int* pBoatIndex, bool* pGuessed);
int GetGridBoatAtXY(struct Grid* pGrid, int x, int y);
bool IsGridGuessedAtXY(struct Grid* pGrid, int x, int y);
void SetGridDataAtXY(struct Grid* pGrid, int x, int y, int boat, bool guessed);
void FindAnyNonSunkHitInGrid(struct Grid* pGrid, struct BoatInfo* pBoats, int* pX, int* pY, int Direc[]);

#endif

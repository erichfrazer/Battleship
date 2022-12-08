#ifndef __FUNCTIONS_THEREST_H__
#define __FUNCTIONS_THEREST_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "Game_Defaults.h"
#include "Functions_Array.h"

bool AnyUntriedPathsAroundUs(struct Grid* pGrid, int x, int y);
bool HasAnythingInSquareBlockBeenGuessed(struct Grid* pGrid, int x, int y, int len);
bool FindUnguessedSpotWithinSquareLen(struct Grid* pGrid, int* px, int* py, int len);
bool IsSpaceForBoat(struct Grid* pGrid, struct BoatInfo* ProposedBoat);
// returns WHICH boat. returns NO_BOAT if boat is not sunk at that point
int IsEntireBoatSunkAtXY(struct Grid* pGrid, int x, int y);
void PlaceBoatInGrid(struct Grid* pGrid, struct BoatInfo* NewBoat);
void PrintGrid(struct Grid* pGrid, struct Grid* pOpponentGrid);

#endif

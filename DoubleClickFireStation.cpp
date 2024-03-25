/**
 * @file DoubleClickFireStation.cpp
 * @author Mannan Dhillon
 *

 */
#include "pch.h"
#include "DoubleClickFireStation.h"
#include "TileFireStation.h"
void DoubleClickFireStation::VisitFireStation(TileFireStation *fireStation)
{
    mIsFireStation= true;
    if(fireStation->OnReady())
    {
        fireStation->Opening();
    }
}
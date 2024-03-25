/**
 * @file FireCountVisitor.cpp
 * @author Mannan Dhillon
 *
 */
#include "pch.h"
#include "FireCountVisitor.h"
#include "TileBuilding.h"
void FireCountVisitor::VisitBuilding(TileBuilding* building)
{
    if (building->OnFire())
    {
        mCountFire++;
    }
}
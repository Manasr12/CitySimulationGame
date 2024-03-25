/**
 * @file ExtinguishVisitor.cpp
 * @author Mannan Dhillon
 *
 */
#include "pch.h"
#include "ExtinguishVisitor.h"
#include "TileBuilding.h"

/** Visit a TileLandscape object
 *
* @param building Landscape tile we are visiting */
void ExtinguishVisitor::VisitBuilding(TileBuilding* building)
{


    if (building->OnFire())
    {
        building->ExtinguishFire();

    }

}

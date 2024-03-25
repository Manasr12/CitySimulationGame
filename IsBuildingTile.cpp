/**
 * @file IsBuildingTile.cpp
 * @author Mannan Dhillon
 *
 *
 */

#include "pch.h"


#include "IsBuildingTile.h"
#include "TileBuilding.h"

/** Visit a TileLandscape object
*
* @param building Landscape tile we are visiting
*/
void IsBuildingTileVisitor::VisitBuilding(TileBuilding *building)
{
    mIsBuilding = true;

     if (building->OnBurnt())
    {
        building->Reset();

    }
    else if(building -> OnNormal())
    {
        building ->SetOnFire();

    }
}
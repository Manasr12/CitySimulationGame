/**
 * @file BuildingCounter.h
 * @author Mannan Dhillon
 *
 *  Gets the number of buildings
 *
 */

#ifndef CITY_BUILDINGCOUNTER_H
#define CITY_BUILDINGCOUNTER_H

#include "TileBuilding.h"
/**
 * building counter class
 */
class BuildingCounter : public TileVisitor
{
private:
    /// Buildings counter
    int mNumBuildings = 0;

public:
    /**
     * Get the number of buildings
     * @return Number of buildings
     */
    int GetNumBuildings() const { return mNumBuildings; }
    /**
 * Visit a TileBuilding object
 * @param building Building we are visiting
 */
    void VisitBuilding(TileBuilding* building)
    {
        mNumBuildings++;
    }
};

#endif //CITY_BUILDINGCOUNTER_H

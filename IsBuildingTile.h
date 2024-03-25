/**
 * @file IsBuildingTile.h
 * @author Mannan Dhillon
 *
 * Vistor that goes to every building tile
 *
 * sets it on fire and resets the tile
 */

#ifndef CITY_ISBUILDINGTILE_H
#define CITY_ISBUILDINGTILE_H


#include "TileVisitor.h"
/**
 * This class check if the tile is  building tile then sets it on fire or resets it
 */
class IsBuildingTileVisitor : public TileVisitor
        {
public:
/**
* visitor funciton for building
*
*/
    virtual void VisitBuilding(TileBuilding* building) override;
    /**
      * This check if the tile is a building
      * @return the boolean
      */
    bool IsBuilding() { return mIsBuilding; }

private:
    /// member variable to check for building
    bool mIsBuilding = false;

};


#endif //CITY_ISBUILDINGTILE_H

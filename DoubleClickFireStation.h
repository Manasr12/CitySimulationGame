/**
 * @file DoubleClickFireStation.h
 * @author Mannan Dhillon
 *
 *  Goes to the fire station tile if it is ready then it opens it
 *
 */

#ifndef CITY_DOUBLECLICKFIRESTATION_H
#define CITY_DOUBLECLICKFIRESTATION_H


#include "TileFireStation.h"
/**
 * This class check if the tile is fire station
 */
class DoubleClickFireStation: public TileVisitor {
public:
    /**
     * visitor funciton for fire station
     * @param fireStation
     */

    virtual void VisitFireStation(TileFireStation* fireStation) override;
    /**
    * This check if the tile is fire station
    * @return the boolean
    */
    bool IsFireStation() { return mIsFireStation; }

private:
    /// is fire station boolean
    bool mIsFireStation = false;

};


#endif //CITY_DOUBLECLICKFIRESTATION_H

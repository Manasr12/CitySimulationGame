/**
 * @file ExtinguishVisitor.h
 * @author Mannan Dhillon
 *
 *  Visits the tile that has fire and Extinguishes it
 */

#ifndef CITY_EXTINGUISHVISITOR_H
#define CITY_EXTINGUISHVISITOR_H


#include "TileFireStation.h"
/**
 * This class checks if there is fire then Extinguishes it
 */
class ExtinguishVisitor : public TileVisitor{
public:
    virtual void VisitBuilding(TileBuilding* building) override;



private:

};


#endif //CITY_EXTINGUISHVISITOR_H

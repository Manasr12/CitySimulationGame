/**
 * @file FireCountVisitor.h
 * @author Mannan Dhillon
 *
 *  Visits the tiles and counts the number of fires
 *
 */
#ifndef CITY_FIRECOUNTVISITOR_H
#define CITY_FIRECOUNTVISITOR_H


#include "TileVisitor.h"
/**
 * This class check how many fires there are
 */
class FireCountVisitor: public TileVisitor {
public:
    /**
     * visitor funciton for building
     * @param building
     */

    virtual void VisitBuilding(TileBuilding* building) override;
    /**
  * counts fires
  * @return the boolean
  */
    double CountNum(){return mCountFire;}
private:
    /// count fire variable
    double mCountFire = 0;
};


#endif //CITY_FIRECOUNTVISITOR_H

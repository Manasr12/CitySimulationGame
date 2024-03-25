/**
 * @file TileFireStation.h
 * @author Mannan Dhillon
 *
 * Class that implements a fire station tile
 */

#ifndef CITY_TILEFIRESTATION_H
#define CITY_TILEFIRESTATION_H

#include "Tile.h"
#include "IsBuildingTile.h"

/**
 * Class that implements a fire station tile
 */
class TileFireStation : public Tile {
private:
    /// The fire station state possibilities
    enum class State {Ready, Opening, OneEngine, TwoEngines};

    /// The current fire station state
    State mState = State::Ready;
public:
    TileFireStation(City *city);

    /// Default constructor (disabled)
    TileFireStation() = delete;

    /// Copy constructor (disabled)
    TileFireStation(const TileFireStation &) = delete;

    /// Assignment operator
    void operator=(const TileFireStation &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    void Update(double elapsed) override;
    /**
   * Accept a visitor
   * @param visitor The visitor we accept
   */
    void Accept(TileVisitor* visitor) override { visitor->VisitFireStation(this); }
    /**
     * Extinguishes the fires
     */
    void ExtinguishFires();
    /**
     * Extinguishes the fires
     * @return mState
     */
    bool OnReady() {return mState == State::Ready;}
    /**
     * funciton for opening
     */
    void Opening();
    /**
     * funciton for counting fire
     * @return number of fires
     */
    double CountFire();
};

#endif //CITY_TILEFIRESTATION_H

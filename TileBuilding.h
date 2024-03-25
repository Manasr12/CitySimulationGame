/**
* @file TileBuilding.h
*
* @author Mannan Dhillon
*
*  Class that implements a Building tile
*/

#pragma once

#include "Tile.h"



/**
*  A Building tile
*/
class TileBuilding : public Tile
{
private:
    /// The building image file
    std::wstring mBuildingImageFile;

    /// Possible building states
    enum class State {Normal, Fire, Burnt};

    /// The current building state
    State mState = State::Normal;

    /// Current fire image index
    int mFireImageIndex = 0;

    /// The duration for the current file image
    double mFireImageDuration = 0;

public:
    TileBuilding(City *city);

    ///  Default constructor (disabled)
    TileBuilding() = delete;

    ///  Copy constructor (disabled)
    TileBuilding(const TileBuilding &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    void Update(double elapsed) override;

    /**
     * Is this building on fire?
     * @return True if on file
     */
    bool OnFire() {return mState == State::Fire;}
    /**
    * Is this building on burnt?
    * @return True if on file
    */
    bool OnBurnt() {return mState == State::Burnt;}
    /**
    * Is this building on normal?
    * @return True if on file
    */
    bool OnNormal() {return mState == State::Normal;}

    void ExtinguishFire();

    void SetImage(const std::wstring& file) override;

    void SetOnFire();

    void Reset();
    /**
 * Accept a visitor
 * @param visitor The visitor we accept
 */
    void Accept(TileVisitor* visitor) override { visitor->VisitBuilding(this); }

};


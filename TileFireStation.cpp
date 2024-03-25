/**
 * @file TileFireStation.cpp
 * @author Mannan Dhillon
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "TileFireStation.h"
#include "City.h"
#include "MemberReport.h"
#include "IsBuildingTile.h"
#include "ExtinguishVisitor.h"
#include "FireCountVisitor.h"

/// Image for the fire station with the doors closed
const std::wstring FireStationReadyImage = L"firestation1.png";
/// Image of the fire station with the doors opening
const std::wstring FireStationOpeningImage = L"firestation2.png";

/// Image of the fire station with one engine out
const std::wstring FireStationOneEngineImage = L"firestation3.png";

/// Image of the fire station with two engines out
const std::wstring FireStationTwoEnginesImage = L"firestation4.png";

/// Time the door opening image is displayed
const double FireStationDoorOpeningTime = 1.0;

/// Time one or two engines are displayed
const double FireStationEngineDisplayTime = 1.0;
/// sets the image duration of fire station at zero
double mFireStationImageDuration = 0;

/// count fire function
void CountFire();

/**
 * Constructor
 * @param city The city this is a member of
*/
TileFireStation::TileFireStation(City *city) : Tile(city)
{
    SetImage(FireStationReadyImage);
}




/**
 * Update the building animation in time
 * @param elapsed Elapsed time in seconds
 */
void TileFireStation::Update(double elapsed)
{
    Tile::Update(elapsed);

    switch(mState)
    {
        // One state presented as an example, the rest are up to you
        case State::Opening:
            mFireStationImageDuration += elapsed;
            if(mFireStationImageDuration >= FireStationDoorOpeningTime)
            {
                if (CountFire() == 0)
                {
                    mState = State::Ready;
                }
                if (CountFire() > 0)
                {

                    SetImage(FireStationOpeningImage);
                    mState = State::OneEngine;

                }

                mFireStationImageDuration = 0;
            }
            break;
        case State::Ready:
            mFireStationImageDuration += elapsed;
            if(mFireStationImageDuration >= FireStationDoorOpeningTime)
            {
                SetImage(FireStationReadyImage);
            }
            break;
        case State::OneEngine:
            mFireStationImageDuration += elapsed;
            if(mFireStationImageDuration >= FireStationEngineDisplayTime)
            {

                if (CountFire() == 1) {
                    //mState = State::OneEngine;

                    SetImage(FireStationOneEngineImage);
                    ExtinguishFires();
                    mState = State::Ready;
                }
                if (CountFire() >1) {

                    SetImage(FireStationOneEngineImage);
                    mState = State::TwoEngines;


                }
                mFireStationImageDuration = 0;
            }
            break;
        case State::TwoEngines:
            mFireStationImageDuration += elapsed;
            if(mFireStationImageDuration >= FireStationEngineDisplayTime)
            {
                //if (CountFire() == 1) {
                //mState = State::OneEngine;


                SetImage(FireStationTwoEnginesImage);
                ExtinguishFires();
                mState = State::Ready;
                mFireStationImageDuration = 0;
                //}



            }
            break;

        default:
            break;
    }

}




/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileFireStation::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"fire-station");

    return itemNode;
}


/**
* brief Load the attributes for an item node.
* @param node The Xml node we are loading the item from
*/
void TileFireStation::XmlLoad(wxXmlNode* node)
{
    Tile::XmlLoad(node);
}



/**
 * Generate a report for this  tile.
 * @param report
*/
void TileFireStation::Report(std::shared_ptr<MemberReport> report)
{
    std::wstringstream str;
    str << L"Building - Fire Station";

    report->SetReport(str.str());
}

void TileFireStation::ExtinguishFires()
{


    ExtinguishVisitor visitor;
    GetCity()->Accept(&visitor);

}
void TileFireStation::Opening()
{
    // Set the fire state
    mState = State::Opening;

}
double TileFireStation::CountFire()
{
    FireCountVisitor visitor;
    GetCity()->Accept(&visitor);
    return visitor.CountNum();
}


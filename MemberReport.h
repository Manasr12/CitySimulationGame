/**
 * @file MemberReport.h
 *
 * @author Mannan Dhillon
 *
 * This is a single report from a member object in the
 * city. It contains a pointer to the tile and a string 
 * generated by the tile.
 */

#pragma once

#include <string>
#include <memory>

class Tile;

/**
 * This is a single report from a member object in the
 * city. It contains a pointer to the tile and a string
 * generated by the tile.
*/
class MemberReport
{
public:
    MemberReport(std::shared_ptr<Tile> tile);

    std::wstring Report();

    /**
     * Set the report for this file
     * @param str New report text.
    */
    void SetReport(std::wstring str) { mReport = str; }

private:
    /// Tile this report is for
    std::shared_ptr<Tile>  mTile;

    /// The generated report from the file
    std::wstring mReport;
};


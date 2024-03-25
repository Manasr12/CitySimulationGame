project(CityLib)

set(SOURCE_FILES
        pch.h
        City.h City.cpp
        Tile.h Tile.cpp
        CityReport.h CityReport.cpp
        MemberReport.h MemberReport.cpp
        TileBuilding.h TileBuilding.cpp
        TileGarden.h TileGarden.cpp
        TileLandscape.h TileLandscape.cpp
        MainFrame.cpp MainFrame.h
        CityReport.cpp CityView.cpp CityView.h ids.h TileWater.cpp TileWater.h TileFireStation.cpp TileFireStation.h TileVisitor.h BuildingCounter.h IsBuildingTile.cpp IsBuildingTile.h ExtinguishVisitor.cpp ExtinguishVisitor.h NumberFireVisitor.h DoubleClickFireStation.cpp DoubleClickFireStation.h FireCountVisitor.cpp FireCountVisitor.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
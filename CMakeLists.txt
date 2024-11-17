cmake_minimum_required( VERSION 3.10.0 ) 

project(LightYears 
        VERSION 1.0.0
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD            11)
set(CMAKE_CXX_STANDARD_REQUIRED   ON)
set(CMAKE_CXX_EXTENSIONS         OFF) 

#creates a variable
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

# LightYears is a directory, located where the current CMakeList is
add_subdirectory(LightYears)
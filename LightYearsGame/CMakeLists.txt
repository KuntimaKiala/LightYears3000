
# add_subdirectory(LightYearsGame) in the CMakeList under LightYears3000 is responsible to this CMakeLists being seen.

add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
               ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp

               ${CMAKE_CURRENT_SOURCE_DIR}/include/spaceship/Spaceship.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/spaceship/Spaceship.cpp

               ${CMAKE_CURRENT_SOURCE_DIR}/include/player/PlayerSpaceship.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/player/PlayerSpaceship.cpp

               ${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/Shooter.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/Shooter.cpp

               ${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/BulletShooter.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/BulletShooter.cpp

               ${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/Bullet.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/Bullet.cpp
)

target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Linking the Libraries to our project
target_link_libraries( ${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${LIGHT_YEARS_ENGINE_TARGET_NAME} )


function(CopyLibDirToTarget LIB_NAME TARGET_NAME )

add_custom_command(
    TARGET ${TARGET_NAME} 
    POST_BUILD 
    COMMAND ${CMAKE_COMMAND} 
    ARGS -E copy_directory 
    $<TARGET_FILE_DIR:${LIB_NAME}> 
    $<TARGET_FILE_DIR:${TARGET_NAME}> 
)

endfunction()

CopyLibDirToTarget( ${LIGHT_YEARS_ENGINE_TARGET_NAME} ${LIGHT_YEARS_GAME_TARGET_NAME})

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
    TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
    POST_BUILD 
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy_directory
    ${RESOURCE_SRC_DIR}
    $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}

)



configure_file(
    "Config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h" ESCAPE_QUOTES

)
















# add custom command exemple
#add_custom_command
#(
#    TARGET ${LIGHT_YEARS_GAME_TARGET_NAME} POST_BUILD  # Adds a post-build event to ${LIGHT_YEARS_GAME_TARGET_NAME} == LightYearsGame
#    COMMAND 
#    ${CMAKE_COMMAND}
#    ARGS -E copy_if_different # copy if there is difference
#    $<TARGET_FILE:sfml-graphics> #the generator build files for (sfml-graphics/sfml-window/sfml-system/sfml-audio/...etc)
#    $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}> # to where the executable is [somehow  $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}> become a path]
#)
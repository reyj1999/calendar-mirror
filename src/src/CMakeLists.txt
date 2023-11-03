set(CS_VERSION 1.8)



list(APPEND caspercalendar_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/daylistmodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/event.h
    ${CMAKE_CURRENT_SOURCE_DIR}/preferences.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogpreferences.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogwords.h
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/speechengine.h
    ${CMAKE_CURRENT_SOURCE_DIR}/wavcat.h

)

list(APPEND caspercalendar_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/daylistmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogevent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogevent.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogpreferences.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogpreferences.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogwords.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogwords.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/speechengine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/wavcat.cpp


    qrc_app.cpp
   
)

# use copperspice resource macro generates a call to the appropriate resource compiler
# run rcc to generate qrc output
COPPERSPICE_RESOURCES(
   ${CMAKE_CURRENT_SOURCE_DIR}/../app.qrc

)



# run uic to generate source
COPPERSPICE_RESOURCES(
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogevent.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogpreferences.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogwords.ui
    
)



add_executable(caspercalendar ${caspercalendar_SOURCES})

target_include_directories(caspercalendar PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(caspercalendar
    CopperSpice::CsCore
    CopperSpice::CsGui
    CopperSpice::CsXml
    CopperSpice::CsMultimedia
)


if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
set_target_properties(caspercalendar PROPERTIES OUTPUT_NAME caspercalendar)
endif()

install(TARGETS caspercalendar DESTINATION .)

# Copy the libraries and plugins necessary for the application to the install path

cs_copy_library(CsCore)
cs_copy_library(CsGui)
cs_copy_library(CsXml)
cs_copy_library(CsMultimedia)
cs_copy_plugins(CsGui)


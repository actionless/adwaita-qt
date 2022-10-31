
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

configure_file(config-oodwaita.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-oodwaita.h )
configure_file(oodwaita-qt.pc.cmake "${CMAKE_CURRENT_BINARY_DIR}/oodwaita-qt${OODWAITAQT_SUFFIX}.pc" @ONLY)

set(liboodwaitaqt_priv_SRCS
    # Animations
    animations/oodwaitaanimation.cpp
    animations/oodwaitaanimations.cpp
    animations/oodwaitaanimationdata.cpp
    animations/oodwaitabaseengine.cpp
    animations/oodwaitabusyindicatordata.cpp
    animations/oodwaitabusyindicatorengine.cpp
    animations/oodwaitadialdata.cpp
    animations/oodwaitadialengine.cpp
    animations/oodwaitaenabledata.cpp
    animations/oodwaitagenericdata.cpp
    animations/oodwaitaheaderviewdata.cpp
    animations/oodwaitaheaderviewengine.cpp
    animations/oodwaitascrollbardata.cpp
    animations/oodwaitascrollbarengine.cpp
    animations/oodwaitaspinboxengine.cpp
    animations/oodwaitaspinboxdata.cpp
    animations/oodwaitastackedwidgetdata.cpp
    animations/oodwaitastackedwidgetengine.cpp
    animations/oodwaitatabbarengine.cpp
    animations/oodwaitatabbardata.cpp
    animations/oodwaitatoolboxengine.cpp
    animations/oodwaitatransitiondata.cpp
    animations/oodwaitatransitionwidget.cpp
    animations/oodwaitawidgetstateengine.cpp
    animations/oodwaitawidgetstatedata.cpp

    # Others
    oodwaitaaddeventfilter.cpp
    oodwaitamnemonics.cpp
    oodwaitasplitterproxy.cpp
    oodwaitawidgetexplorer.cpp
    oodwaitawindowmanager.cpp
)

set(liboodwaitaqt_SRCS
    oodwaita.cpp
    oodwaitacolors.cpp
    oodwaitarenderer.cpp
)

set(liboodwaitaqt_HEADERS
    oodwaita.h
    oodwaitacolors.h
    oodwaitarenderer.h
    oodwaitaqt_export.h
)

add_library("oodwaitaqt${OODWAITAQT_SUFFIX}priv" SHARED ${liboodwaitaqt_priv_SRCS})
target_link_libraries("oodwaitaqt${OODWAITAQT_SUFFIX}priv"
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::DBus
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

# We need this done before we start building oodwaitaqt public library
find_program(SASSC_EXECUTABLE sassc)
if (SASSC_EXECUTABLE)
    #set(Variants "light" "dark" "hc" "hc-dark")
    set(Variants "light")
    #foreach(VARIANT IN LISTS Variants)
    #    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/stylesheet/Oodwaita-${VARIANT}.css"
    #                       COMMAND "${SASSC_EXECUTABLE}"
    #                              -a -M -t compact
    #                              "${CMAKE_CURRENT_SOURCE_DIR}/stylesheet/Oodwaita-${VARIANT}.scss"
    #                              "${CMAKE_CURRENT_BINARY_DIR}/stylesheet/Oodwaita-${VARIANT}.css"
    #                       COMMENT "Stylesheet variant: ${VARIANT}")
    #endforeach()
    foreach(VARIANT IN LISTS Variants)
        add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/stylesheet/Oodwaita-${VARIANT}.css"
                           COMMAND "cp"
								  "${CMAKE_CURRENT_SOURCE_DIR}/stylesheet/processed/Oodwaita-${VARIANT}.css"
								  "${CMAKE_CURRENT_BINARY_DIR}/stylesheet/Oodwaita-${VARIANT}.css"
                           COMMENT "Stylesheet variant: ${VARIANT}")
    endforeach()
    set(STYLESHEET_PATH "${CMAKE_CURRENT_BINARY_DIR}/stylesheet")
else()
    set(STYLESHEET_PATH "${CMAKE_CURRENT_SOURCE_DIR}/stylesheet/processed")
endif()

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/stylesheet/stylesheet.qrc.in" "${CMAKE_CURRENT_BINARY_DIR}/stylesheet/stylesheet.qrc")

if (USE_QT6)
    qt6_add_resources(liboodwaitaqt_SRCS "${CMAKE_CURRENT_BINARY_DIR}/stylesheet/stylesheet.qrc")
else()
    qt5_add_resources(liboodwaitaqt_SRCS "${CMAKE_CURRENT_BINARY_DIR}/stylesheet/stylesheet.qrc")
endif()

add_library("oodwaitaqt${OODWAITAQT_SUFFIX}" SHARED ${liboodwaitaqt_SRCS})
add_library("OodwaitaQt${OODWAITAQT_SUFFIX}" ALIAS "oodwaitaqt${OODWAITAQT_SUFFIX}")

target_link_libraries("oodwaitaqt${OODWAITAQT_SUFFIX}"
    PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE
    "oodwaitaqt${OODWAITAQT_SUFFIX}priv"
)

set_target_properties("oodwaitaqt${OODWAITAQT_SUFFIX}priv" PROPERTIES VERSION ${OODWAITAQT_VERSION} SOVERSION 1)
if(MINGW AND BUILD_SHARED_LIBS)
    get_target_property(OODWAITA_QT_SOVERSION "oodwaitaqt${OODWAITAQT_SUFFIX}priv" SOVERSION)
    set_target_properties("oodwaitaqt${OODWAITAQT_SUFFIX}priv" PROPERTIES SUFFIX "-${OODWAITA_QT_SOVERSION}${CMAKE_SHARED_LIBRARY_SUFFIX}")
endif()

set_target_properties("oodwaitaqt${OODWAITAQT_SUFFIX}" PROPERTIES VERSION ${OODWAITAQT_VERSION} SOVERSION 1)
if(MINGW AND BUILD_SHARED_LIBS)
    get_target_property(OODWAITA_QT_SOVERSION "oodwaitaqt${OODWAITAQT_SUFFIX}" SOVERSION)
    set_target_properties("oodwaitaqt${OODWAITAQT_SUFFIX}" PROPERTIES SUFFIX "-${OODWAITA_QT_SOVERSION}${CMAKE_SHARED_LIBRARY_SUFFIX}")
endif()

if (USE_QT6)
    target_include_directories("oodwaitaqt${OODWAITAQT_SUFFIX}" PUBLIC ${Qt6Core_INCLUDE_DIRS} ${Qt6Gui_INCLUDE_DIRS} ${Qt6Widgets_INCLUDE_DIRS})
else()
    target_include_directories("oodwaitaqt${OODWAITAQT_SUFFIX}" PUBLIC ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
endif()

install(TARGETS "oodwaitaqt${OODWAITAQT_SUFFIX}priv" EXPORT "OodwaitaQt${OODWAITAQT_SUFFIX}Targets" RUNTIME DESTINATION bin LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS "oodwaitaqt${OODWAITAQT_SUFFIX}" EXPORT "OodwaitaQt${OODWAITAQT_SUFFIX}Targets" RUNTIME DESTINATION bin LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${liboodwaitaqt_HEADERS} DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}/OodwaitaQt${OODWAITAQT_SUFFIX}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/oodwaita-qt${OODWAITAQT_SUFFIX}.pc" DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}/pkgconfig)

# create a Config.cmake and a ConfigVersion.cmake file and install them
set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBDIR}/cmake/OodwaitaQt${OODWAITAQT_SUFFIX}")

include(CMakePackageConfigHelpers)

configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/OodwaitaQtConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/OodwaitaQt${OODWAITAQT_SUFFIX}Config.cmake"
  INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR}
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/OodwaitaQt${OODWAITAQT_SUFFIX}ConfigVersion.cmake"
  VERSION ${OODWAITAQT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/OodwaitaQt${OODWAITAQT_SUFFIX}Config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/OodwaitaQt${OODWAITAQT_SUFFIX}ConfigVersion.cmake"
  DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
  COMPONENT Devel
)

install(EXPORT "OodwaitaQt${OODWAITAQT_SUFFIX}Targets" DESTINATION "${CMAKECONFIG_INSTALL_DIR}" FILE "OodwaitaQt${OODWAITAQT_SUFFIX}Targets.cmake")

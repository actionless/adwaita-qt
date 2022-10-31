prefix=@CMAKE_INSTALL_PREFIX@
libdir=@CMAKE_INSTALL_FULL_LIBDIR@
includedir=@CMAKE_INSTALL_FULL_INCLUDEDIR@

Name: oodwaita-qt@OODWAITAQT_SUFFIX@
Description: Qt Oodwaita Style
Version: @OODWAITAQT_VERSION@
Requires: @PC_REQUIRES@
@PC_REQUIRES_PRIVATE@

Libs: -L${libdir} -loodwaitaqt@OODWAITAQT_SUFFIX@
Cflags: -I${includedir}
Requires: Qt@QT_VERSION_MAJOR@Core Qt@QT_VERSION_MAJOR@Widgets

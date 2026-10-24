cmake_minimum_required(VERSION 4.1)
project(ApplicantStatsProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (DEFINED ENV{QT_ROOT})
    set(QT_ROOT_PATH $ENV{QT_ROOT})
endif ()
set(CMAKE_PREFIX_PATH "${QT_ROOT_PATH}/mingw_64")

set(Qt6_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt6")

add_subdirectory(libs)
include(FetchContent)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Qml
        Quick
        Graphs
        Sql
        QuickControls2
        REQUIRED)

add_executable(ApplicantStatsProject

        src/data-processing/cache-manager.h
        src/data-processing/magic-hat.h

        src/app-utils/app-paths-manager.h
        src/app-utils/qml-helper.h
        src/database/database-manager.h
        src/app-utils/scripts.h
        src/app-utils/logger.h
        src/windows-controlling/progress-handler.h

        src/windows-controlling/window-manager.h

        src/tables-processing/table-parser-bachelor.h
        src/applicants-faculty-priority/namespaces.h
        src/applicants-faculty-priority/faculty-direction.h
        src/applicants-faculty-priority/applicant.h
        src/applicants-faculty-priority/priority-info.h

        src/models/tree-view-model.h
        src/models/tables-list-model.h
        src/models/stats-page-model.h
        src/models/applicants-list-model.h
        src/models/entry-commisions-list-model.h
###########################################################
        src/main.cpp

        src/data-processing/cache-manager.cpp
        src/data-processing/magic-hat.cpp

        src/app-utils/app-paths-manager.cpp
        src/app-utils/qml-helper.cpp
        src/database/database-manager.cpp
        src/app-utils/logger.cpp
        src/windows-controlling/progress-handler.cpp

        src/windows-controlling/window-manager.cpp

        src/tables-processing/table-parser-bachelor.cpp
        src/applicants-faculty-priority/faculty-direction.cpp
        src/applicants-faculty-priority/applicant.cpp
        src/applicants-faculty-priority/priority-info.cpp

        src/models/tree-view-model.cpp
        src/models/tables-list-model.cpp
        src/models/stats-page-model.cpp
        src/models/applicants-list-model.cpp
        src/models/entry-commisions-list-model.cpp
#########################################################
        resources.qrc
        src/theme-managging/theme-manager.cpp
        src/theme-managging/theme-manager.h
        #########################################################
)

qt_add_qml_module(ApplicantStatsProject
        URI ApplicantStatsProjectModule
        VERSION 1.0
        NO_PLUGIN
        QML_FILES

        src/qml-gui/Main.qml
        src/qml-gui/visual-effects/LeftTopGradient.qml
        src/qml-gui/PagesMenu.qml
        src/qml-gui/StatusBar.qml

        src/qml-gui/stats-page/StatsPage.qml
        src/qml-gui/stats-page/TablesList.qml
        src/qml-gui/stats-page/FacultyTreeView.qml
        src/qml-gui/stats-page/FacultyStatsPage.qml
        src/qml-gui/stats-page/DirectionStatsPage.qml
        src/qml-gui/stats-page/EmptyStatsPlaceholder.qml
        src/qml-gui/stats-page/PageErrorPlaceholder.qml

        src/qml-gui/components/PageButton.qml
        src/qml-gui/components/ScoreDist.qml
        src/qml-gui/components/CustomComboBox.qml

        src/qml-gui/windows/NewTableSetter.qml

)

target_link_libraries(ApplicantStatsProject PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Qml
        Qt6::Quick
        Qt6::Graphs
        Qt6::Sql
        QXlsx::QXlsx
        Qt6::QuickControls2
        $<$<PLATFORM_ID:Windows>:dwmapi>
)

if (WIN32)
    get_target_property(QT_QMAKE_EXECUTABLE Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(QT_BIN_DIR "${QT_QMAKE_EXECUTABLE}" DIRECTORY)
    find_program(WINDEPLOYQT windeployqt HINTS "${QT_BIN_DIR}")

    foreach (MINGW_DLL libgcc_s_seh-1.dll libstdc++-6.dll libwinpthread-1.dll)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_BIN_DIR}/${MINGW_DLL}"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/"
                COMMENT "Copying ${MINGW_DLL}..."
        )
    endforeach ()

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND "${WINDEPLOYQT}"
            --qmldir "${CMAKE_SOURCE_DIR}"
            --no-translations
            "$<TARGET_FILE:${PROJECT_NAME}>"
            COMMENT "Running windeployqt..."
    )
endif ()
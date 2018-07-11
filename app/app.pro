#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T20:44:30
#
#-------------------------------------------------

QT       += core gui widgets svg network

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingApp
TEMPLATE = app

SOURCES += main.cpp \
    Canvas.cpp \
    MainWindow.cpp \
    VisualEntity.cpp \
    Shape.cpp \
    Group.cpp \
    DrawDialog.cpp \
    DrawDialogFactory.cpp \
    Selection.cpp \
    AbstractGroup.cpp \
    Tool.cpp \
    PropertySpinBox.cpp \
    PropertyColorButton.cpp \
    GlobalDrawProperties.cpp \
    Command.cpp \
    shapes/Circle.cpp \
    shapes/Line.cpp \
    shapes/Rectangle.cpp \
    tools/DrawCircleTool.cpp \
    tools/DrawLineTool.cpp \
    tools/DrawRectangleTool.cpp \
    tools/SelectionTool.cpp \
    ActiveSelection.cpp \
    commands/DrawCommand.cpp \
    commands/DeleteSelectedCommand.cpp \
    commands/MoveSelectionCommand.cpp \
    commands/SendBackwardCommand.cpp \
    commands/ChangeOrderCommand.cpp \
    commands/BringForwardCommand.cpp \
    commands/BringToFrontCommand.cpp \
    commands/SendToBackCommand.cpp \
    MainCommandStack.cpp \
    CommandStack.cpp \
    commands/BulkOrderCommand.cpp \
    fileio/JsonFileReader.cpp \
    fileio/JsonFileWriter.cpp \
    fileio/FileReaderFactory.cpp \
    fileio/FileWriterFactory.cpp \
    fileio/HtJsonFileReader.cpp \
    shapes/svg.cpp \
    fileio/KyJsonFileReader.cpp \
    fileio/KyJsonFileReaderV2.cpp \
    shapes/Text.cpp \
    commands/BringForwardCommand.cpp \
    commands/BringToFrontCommand.cpp \
    commands/BulkOrderCommand.cpp \
    commands/ChangeOrderCommand.cpp \
    commands/DeleteSelectedCommand.cpp \
    commands/DrawCommand.cpp \
    commands/MoveSelectionCommand.cpp \
    commands/SendBackwardCommand.cpp \
    commands/SendToBackCommand.cpp \
    fileio/FileReaderFactory.cpp \
    fileio/FileWriterFactory.cpp \
    fileio/HtJsonFileReader.cpp \
    fileio/JsonFileReader.cpp \
    fileio/JsonFileWriter.cpp \
    fileio/KyJsonFileReader.cpp \
    fileio/KyJsonFileReaderV2.cpp \
    shapes/Circle.cpp \
    shapes/Line.cpp \
    shapes/Rectangle.cpp \
    shapes/svg.cpp \
    shapes/Text.cpp \
    tools/DrawCircleTool.cpp \
    tools/DrawLineTool.cpp \
    tools/DrawRectangleTool.cpp \
    tools/SelectionTool.cpp \
    AbstractGroup.cpp \
    ActiveSelection.cpp \
    Canvas.cpp \
    Command.cpp \
    CommandStack.cpp \
    DrawDialog.cpp \
    DrawDialogFactory.cpp \
    GlobalDrawProperties.cpp \
    Group.cpp \
    main.cpp \
    MainCommandStack.cpp \
    MainWindow.cpp \
    PropertyColorButton.cpp \
    PropertySpinBox.cpp \
    Selection.cpp \
    Shape.cpp \
    Tool.cpp \
    VisualEntity.cpp \
    events/ValueChangeEvent.cpp \
    tools/ValueChangeTool.cpp \
    dataSource/GoldenDataSource.cpp \
    common/PropertySupport.cpp \
    events/BatchValueChangeEvent.cpp

HEADERS  += \
    MainWindow.hpp \
    Canvas.hpp \
    VisualEntity.hpp \
    Shape.hpp \
    Group.hpp \
    DrawDialog.hpp \
    DrawDialogFactory.hpp \
    Selection.hpp \
    Tool.hpp \
    MainCommandStack.hpp \
    AbstractGroup.hpp \
    PropertySpinBox.hpp \
    PropertyColorButton.hpp \
    GlobalDrawProperties.hpp \
    Command.hpp \
    Signal.hpp \
    ActiveSelection.hpp \
    commands/BringForwardCommand.hpp \
    commands/BringToFrontCommand.hpp \
    commands/BulkOrderCommand.hpp \
    commands/ChangeOrderCommand.hpp \
    commands/ChangePropertyCommand.hpp \
    commands/ChangePropertyCommandList.hpp \
    commands/DeleteSelectedCommand.hpp \
    commands/DrawCommand.hpp \
    commands/MoveSelectionCommand.hpp \
    commands/SendBackwardCommand.hpp \
    commands/SendToBackCommand.hpp \
    commands/ChangePropertyCommand.hpp \
    commands/ChangePropertyCommandList.hpp \
    commands/DrawCommand.hpp \
    commands/DeleteSelectedCommand.hpp \
    commands/MoveSelectionCommand.hpp \
    commands/SendBackwardCommand.hpp \
    commands/ChangeOrderCommand.hpp \
    commands/BringForwardCommand.hpp \
    commands/BringToFrontCommand.hpp \
    commands/SendToBackCommand.hpp \
    CommandStack.hpp \
    commands/BulkOrderCommand.hpp \
    fileio/HtJsonFileReader.h \
    fileio/JsonFileReader.hpp \
    fileio/JsonFileWriter.hpp \
    fileio/FileReaderFactory.hpp \
    fileio/FileWriterFactory.hpp \
    fileio/HtJsonFileReader.h \
    fileio/KyJsonFileReader.h \
    fileio/KyJsonFileReaderV2.h \
    fileio/FileReaderFactory.hpp \
    fileio/FileWriterFactory.hpp \
    fileio/HtJsonFileReader.h \
    fileio/JsonFileReader.hpp \
    fileio/JsonFileWriter.hpp \
    fileio/KyJsonFileReader.h \
    fileio/KyJsonFileReaderV2.h \
    shapes/Circle.hpp \
    shapes/Line.hpp \
    shapes/Rectangle.hpp \
    shapes/svg.h \
    shapes/Text.h \
    shapes/jsondef.h \
    shapes/Circle.hpp \
    shapes/jsondef.h \
    shapes/Line.hpp \
    shapes/Rectangle.hpp \
    shapes/svg.h \
    shapes/Text.h \
    tools/DrawCircleTool.hpp \
    tools/DrawLineTool.hpp \
    tools/DrawRectangleTool.hpp \
    tools/SelectionTool.hpp \
    tools/ValueChangeTool.h \
    AbstractGroup.hpp \
    ActiveSelection.hpp \
    Canvas.hpp \
    Command.hpp \
    CommandStack.hpp \
    DrawDialog.hpp \
    DrawDialogFactory.hpp \
    GlobalDrawProperties.hpp \
    Group.hpp \
    MainCommandStack.hpp \
    MainWindow.hpp \
    PropertyColorButton.hpp \
    PropertySpinBox.hpp \
    Selection.hpp \
    Shape.hpp \
    Signal.hpp \
    Tool.hpp \
    VisualEntity.hpp \
    events/ValueChangeEvent.h \
    dataSource/GoldenDataSource.h \
    common/PropertySupport.h \
    interfaces/IFileWriter.hpp \
    interfaces/IFileReader.hpp \
    interfaces/IDrawable.hpp \
    interfaces/IFileReader.hpp \
    interfaces/IFileWriter.hpp \
    interfaces/IFillable.hpp \
    interfaces/ILine.hpp \
    interfaces/ISelectable.hpp \
    interfaces/ITransformable.hpp \
    interfaces/IDrawable.hpp \
    interfaces/IFillable.hpp \
    interfaces/ILine.hpp \
    interfaces/ISelectable.hpp \
    interfaces/ITransformable.hpp \
    interfaces/IDataSource.h \
    interfaces/ILabel.h \
    interfaces/IImage.h \
    interfaces/IImage.h \
    interfaces/IPropertySupport.h \
    events/EventDef.h \
    events/BatchValueChangeEvent.h

FORMS    += mainwindow.ui \
    drawdialog.ui

DESTDIR = $$PWD/../build

INCLUDEPATH += \
    $$PWD \
    interfaces \
    commands \
    tools \
    shapes \
    events \
    fileio

RESOURCES += \
    resource.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$(GOLDEN_DIR)/ -lgoldenapi64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$(GOLDEN_DIR)/ -lgoldenapi64

INCLUDEPATH += $$(GOLDEN_DIR)/
DEPENDPATH += $$(GOLDEN_DIR)/

#INCLUDEPATH += $$PWD/../../../../golden/api/x64
#DEPENDPATH += $$PWD/../../../../golden/api/x64

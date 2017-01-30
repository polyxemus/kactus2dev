# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.
message("You are running qmake on a generated .pro file. This may not work!")


HEADERS += ../common/HDLParser/MetaInstance.h \
    ../common/HDLParser/HDLComponentParser.h \
    ../common/HDLParser/HDLParserCommon.h \
    ../PluginSystem/GeneratorPlugin/ViewSelection.h \
    ../VerilogImport/VerilogSyntax.h \
    ../PluginSystem/GeneratorPlugin/GeneratorConfiguration.h \
    ../PluginSystem/GeneratorPlugin/GeneratorConfigurationDialog.h \
    ../PluginSystem/GeneratorPlugin/ViewSelectionWidget.h \
    ../PluginSystem/GeneratorPlugin/FileOutputWidget.h \
    ../PluginSystem/GeneratorPlugin/FileOutput.h \
    ./VerilogGeneratorPlugin.h \
    ../PluginSystem/GeneratorPlugin/IWriterFactory.h \
    ../../editors/ComponentEditor/common/MultipleParameterFinder.h \
    ../common/NameGenerationPolicy.h \
    ./common/Writer.h \
    ./common/WriterGroup.h \
    ./ComponentInstanceVerilogWriter/ComponentInstanceVerilogWriter.h \
    ./ComponentVerilogWriter/ComponentVerilogWriter.h \
    ./veriloggeneratorplugin_global.h \
    ./ModelParameterVerilogWriter/ModelParameterVerilogWriter.h \
    ../common/PortSorter/InterfaceDirectionNameSorter.h \
    ../common/PortSorter/PortSorter.h \
    ./PortVerilogWriter/PortVerilogWriter.h \
    ./VerilogHeaderWriter/VerilogHeaderWriter.h \
    ./VerilogWireWriter/VerilogWireWriter.h \
    ./CommentWriter/CommentWriter.h \
    ../../editors/ComponentEditor/common/ComponentParameterFinder.h \
    ../../editors/ComponentEditor/common/ExpressionFormatter.h \
    ../../editors/ComponentEditor/common/IPXactSystemVerilogParser.h \
    ../../editors/ComponentEditor/common/ListParameterFinder.h \
    ../../editors/ComponentEditor/common/ParameterFinder.h \
    ../../editors/ComponentEditor/common/SystemVerilogExpressionParser.h \
    ../../designEditors/common/TopComponentParameterFinder.h \
    ./VerilogAssignmentWriter/VerilogAssignmentWriter.h \
    ./TextBodyWriter/TextBodyWriter.h \
    ./VerilogInterconnectionWriter/VerilogInterconnectionWriter.h \
    ../common/HDLParser/MetaDesign.h \
    ./PortVerilogWriter/VerilogTopDefaultWriter.h \
    ./VerilogWriterFactory/VerilogDocument.h \
    ./VerilogWriterFactory/VerilogWriterFactory.h
SOURCES += ../common/HDLParser/HDLComponentParser.cpp \
    ../PluginSystem/GeneratorPlugin/FileOutput.cpp \
    ../PluginSystem/GeneratorPlugin/FileOutputWidget.cpp \
    ../PluginSystem/GeneratorPlugin/GeneratorConfiguration.cpp \
    ../PluginSystem/GeneratorPlugin/GeneratorConfigurationDialog.cpp \
    ../PluginSystem/GeneratorPlugin/ViewSelection.cpp \
    ../PluginSystem/GeneratorPlugin/ViewSelectionWidget.cpp \
    ../VerilogImport/VerilogSyntax.cpp \
    ./VerilogGeneratorPlugin.cpp \
    ./ComponentInstanceVerilogWriter/ComponentInstanceVerilogWriter.cpp \
    ./ComponentVerilogWriter/ComponentVerilogWriter.cpp \
    ./ModelParameterVerilogWriter/ModelParameterVerilogWriter.cpp \
    ../common/PortSorter/InterfaceDirectionNameSorter.cpp \
    ./PortVerilogWriter/PortVerilogWriter.cpp \
    ./VerilogHeaderWriter/VerilogHeaderWriter.cpp \
    ./VerilogWireWriter/VerilogWireWriter.cpp \
    ./CommentWriter/CommentWriter.cpp \
    ../../editors/ComponentEditor/common/MultipleParameterFinder.cpp \
    ../common/NameGenerationPolicy.cpp \
    ./common/WriterGroup.cpp \
    ../../editors/ComponentEditor/common/ComponentParameterFinder.cpp \
    ../../editors/ComponentEditor/common/ExpressionFormatter.cpp \
    ../../editors/ComponentEditor/common/IPXactSystemVerilogParser.cpp \
    ../../editors/ComponentEditor/common/ListParameterFinder.cpp \
    ../../editors/ComponentEditor/common/SystemVerilogExpressionParser.cpp \
    ../../designEditors/common/TopComponentParameterFinder.cpp \
    ./VerilogAssignmentWriter/VerilogAssignmentWriter.cpp \
    ./TextBodyWriter/TextBodyWriter.cpp \
    ./VerilogInterconnectionWriter/VerilogInterconnectionWriter.cpp \
    ../common/HDLParser/MetaInstance.cpp \
    ../common/HDLParser/MetaDesign.cpp \
    ./PortVerilogWriter/VerilogTopDefaultWriter.cpp \
    ./VerilogWriterFactory/VerilogDocument.cpp \
    ./VerilogWriterFactory/VerilogWriterFactory.cpp
RESOURCES += VerilogGenerator.qrc

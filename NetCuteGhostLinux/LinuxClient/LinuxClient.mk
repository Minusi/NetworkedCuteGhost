##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=LinuxClient
ConfigurationName      :=Debug
WorkspacePath          :=/home/minusi/Documents/NetCuteGhostLinux
ProjectPath            :=/home/minusi/Documents/NetCuteGhostLinux/LinuxClient
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=minusi
Date                   :=13/12/18
CodeLitePath           :=/home/minusi/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="LinuxClient.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/include/ $(IncludeSwitch)/home/minusi/Documents/NetCuteGhostLinux/LinuxClient/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)pthread 
ArLibs                 :=  "libpthread.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/NetMessages.cpp$(ObjectSuffix) $(IntermediateDirectory)/LinuxUtilCustom.cpp$(ObjectSuffix) $(IntermediateDirectory)/GhostLinuxClient.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/minusi/Documents/NetCuteGhostLinux/LinuxClient/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/NetMessages.cpp$(ObjectSuffix): NetMessages.cpp $(IntermediateDirectory)/NetMessages.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/minusi/Documents/NetCuteGhostLinux/LinuxClient/NetMessages.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NetMessages.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NetMessages.cpp$(DependSuffix): NetMessages.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NetMessages.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NetMessages.cpp$(DependSuffix) -MM NetMessages.cpp

$(IntermediateDirectory)/NetMessages.cpp$(PreprocessSuffix): NetMessages.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NetMessages.cpp$(PreprocessSuffix) NetMessages.cpp

$(IntermediateDirectory)/LinuxUtilCustom.cpp$(ObjectSuffix): LinuxUtilCustom.cpp $(IntermediateDirectory)/LinuxUtilCustom.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/minusi/Documents/NetCuteGhostLinux/LinuxClient/LinuxUtilCustom.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LinuxUtilCustom.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LinuxUtilCustom.cpp$(DependSuffix): LinuxUtilCustom.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LinuxUtilCustom.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LinuxUtilCustom.cpp$(DependSuffix) -MM LinuxUtilCustom.cpp

$(IntermediateDirectory)/LinuxUtilCustom.cpp$(PreprocessSuffix): LinuxUtilCustom.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LinuxUtilCustom.cpp$(PreprocessSuffix) LinuxUtilCustom.cpp

$(IntermediateDirectory)/GhostLinuxClient.cpp$(ObjectSuffix): GhostLinuxClient.cpp $(IntermediateDirectory)/GhostLinuxClient.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/minusi/Documents/NetCuteGhostLinux/LinuxClient/GhostLinuxClient.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GhostLinuxClient.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GhostLinuxClient.cpp$(DependSuffix): GhostLinuxClient.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GhostLinuxClient.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GhostLinuxClient.cpp$(DependSuffix) -MM GhostLinuxClient.cpp

$(IntermediateDirectory)/GhostLinuxClient.cpp$(PreprocessSuffix): GhostLinuxClient.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GhostLinuxClient.cpp$(PreprocessSuffix) GhostLinuxClient.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=LinuxServer
ConfigurationName      :=Debug
WorkspacePath          :=/home/minusi/Documents/NetCuteGhostLinux
ProjectPath            :=/home/minusi/Documents/NetCuteGhostLinux/LinuxServer
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
ObjectsFileList        :="LinuxServer.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/include/ $(IncludeSwitch)/home/minusi/Documents/NetCuteGhostLinux 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)pthread 
ArLibs                 :=  "libpthread.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/ 

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
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(ObjectSuffix) $(IntermediateDirectory)/GhostLinuxServer.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/minusi/Documents/NetCuteGhostLinux/LinuxServer/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(ObjectSuffix): ../LinuxClient/NetMessages.cpp $(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/minusi/Documents/NetCuteGhostLinux/LinuxClient/NetMessages.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(DependSuffix): ../LinuxClient/NetMessages.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(DependSuffix) -MM ../LinuxClient/NetMessages.cpp

$(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(PreprocessSuffix): ../LinuxClient/NetMessages.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_LinuxClient_NetMessages.cpp$(PreprocessSuffix) ../LinuxClient/NetMessages.cpp

$(IntermediateDirectory)/GhostLinuxServer.cpp$(ObjectSuffix): GhostLinuxServer.cpp $(IntermediateDirectory)/GhostLinuxServer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/minusi/Documents/NetCuteGhostLinux/LinuxServer/GhostLinuxServer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GhostLinuxServer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GhostLinuxServer.cpp$(DependSuffix): GhostLinuxServer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GhostLinuxServer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GhostLinuxServer.cpp$(DependSuffix) -MM GhostLinuxServer.cpp

$(IntermediateDirectory)/GhostLinuxServer.cpp$(PreprocessSuffix): GhostLinuxServer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GhostLinuxServer.cpp$(PreprocessSuffix) GhostLinuxServer.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



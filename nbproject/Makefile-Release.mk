#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/App.o \
	${OBJECTDIR}/src/Globals.o \
	${OBJECTDIR}/src/Loader.o \
	${OBJECTDIR}/src/TextureManager.o \
	${OBJECTDIR}/src/camera/Camera.o \
	${OBJECTDIR}/src/controls/Controls.o \
	${OBJECTDIR}/src/import/BinaryWalker.o \
	${OBJECTDIR}/src/import/MxoEprf.o \
	${OBJECTDIR}/src/import/MxoIprf.o \
	${OBJECTDIR}/src/import/MxoMga.o \
	${OBJECTDIR}/src/import/MxoProp.o \
	${OBJECTDIR}/src/lua/LunaLoader.o \
	${OBJECTDIR}/src/primitives/IndexedModel.o \
	${OBJECTDIR}/src/primitives/ModelDatabase.o \
	${OBJECTDIR}/src/primitives/ModelVertex.o \
	${OBJECTDIR}/src/scene/Gui.o \
	${OBJECTDIR}/src/scene/Scene.o \
	${OBJECTDIR}/src/scene/SceneItem.o \
	${OBJECTDIR}/src/shader.o \
	${OBJECTDIR}/src/sound/soundManager.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gleecha

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gleecha: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gleecha ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/App.o: src/App.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/App.o src/App.cpp

${OBJECTDIR}/src/Globals.o: src/Globals.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Globals.o src/Globals.cpp

${OBJECTDIR}/src/Loader.o: src/Loader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Loader.o src/Loader.cpp

${OBJECTDIR}/src/TextureManager.o: src/TextureManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/TextureManager.o src/TextureManager.cpp

${OBJECTDIR}/src/camera/Camera.o: src/camera/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/camera
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/camera/Camera.o src/camera/Camera.cpp

${OBJECTDIR}/src/controls/Controls.o: src/controls/Controls.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/Controls.o src/controls/Controls.cpp

${OBJECTDIR}/src/import/BinaryWalker.o: src/import/BinaryWalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/import
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/import/BinaryWalker.o src/import/BinaryWalker.cpp

${OBJECTDIR}/src/import/MxoEprf.o: src/import/MxoEprf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/import
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/import/MxoEprf.o src/import/MxoEprf.cpp

${OBJECTDIR}/src/import/MxoIprf.o: src/import/MxoIprf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/import
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/import/MxoIprf.o src/import/MxoIprf.cpp

${OBJECTDIR}/src/import/MxoMga.o: src/import/MxoMga.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/import
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/import/MxoMga.o src/import/MxoMga.cpp

${OBJECTDIR}/src/import/MxoProp.o: src/import/MxoProp.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/import
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/import/MxoProp.o src/import/MxoProp.cpp

${OBJECTDIR}/src/lua/LunaLoader.o: src/lua/LunaLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/lua
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lua/LunaLoader.o src/lua/LunaLoader.cpp

${OBJECTDIR}/src/primitives/IndexedModel.o: src/primitives/IndexedModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/primitives
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/primitives/IndexedModel.o src/primitives/IndexedModel.cpp

${OBJECTDIR}/src/primitives/ModelDatabase.o: src/primitives/ModelDatabase.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/primitives
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/primitives/ModelDatabase.o src/primitives/ModelDatabase.cpp

${OBJECTDIR}/src/primitives/ModelVertex.o: src/primitives/ModelVertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/primitives
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/primitives/ModelVertex.o src/primitives/ModelVertex.cpp

${OBJECTDIR}/src/scene/Gui.o: src/scene/Gui.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scene
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scene/Gui.o src/scene/Gui.cpp

${OBJECTDIR}/src/scene/Scene.o: src/scene/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scene
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scene/Scene.o src/scene/Scene.cpp

${OBJECTDIR}/src/scene/SceneItem.o: src/scene/SceneItem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scene
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scene/SceneItem.o src/scene/SceneItem.cpp

${OBJECTDIR}/src/shader.o: src/shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/shader.o src/shader.cpp

${OBJECTDIR}/src/sound/soundManager.o: src/sound/soundManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/sound
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/sound/soundManager.o src/sound/soundManager.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gleecha

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

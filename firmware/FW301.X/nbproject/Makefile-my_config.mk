#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-my_config.mk)" "nbproject/Makefile-local-my_config.mk"
include nbproject/Makefile-local-my_config.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=my_config
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/MetLib/MET_Bootloader.c ../src/MetLib/MET_can_protocol.c ../src/MetLib/MET_can_open.c ../src/config/my_config/peripheral/can/plib_can0.c ../src/config/my_config/peripheral/can/plib_can1.c ../src/config/my_config/peripheral/clock/plib_clock.c ../src/config/my_config/peripheral/cmcc/plib_cmcc.c ../src/config/my_config/peripheral/dsu/plib_dsu.c ../src/config/my_config/peripheral/evsys/plib_evsys.c ../src/config/my_config/peripheral/nvic/plib_nvic.c ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/my_config/peripheral/pac/plib_pac.c ../src/config/my_config/peripheral/port/plib_port.c ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c ../src/config/my_config/peripheral/tc/plib_tc0.c ../src/config/my_config/stdio/xc32_monitor.c ../src/config/my_config/initialization.c ../src/config/my_config/startup_xc32.c ../src/config/my_config/interrupts.c ../src/config/my_config/exceptions.c ../src/config/my_config/libc_syscalls.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o ${OBJECTDIR}/_ext/1032945309/MET_can_open.o ${OBJECTDIR}/_ext/1761505802/plib_can0.o ${OBJECTDIR}/_ext/1761505802/plib_can1.o ${OBJECTDIR}/_ext/590292936/plib_clock.o ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o ${OBJECTDIR}/_ext/1761507328/plib_dsu.o ${OBJECTDIR}/_ext/592442422/plib_evsys.o ${OBJECTDIR}/_ext/1227547160/plib_nvic.o ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o ${OBJECTDIR}/_ext/1761518284/plib_pac.o ${OBJECTDIR}/_ext/1227494009/plib_port.o ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o ${OBJECTDIR}/_ext/220271371/plib_tc0.o ${OBJECTDIR}/_ext/967047524/xc32_monitor.o ${OBJECTDIR}/_ext/64865378/initialization.o ${OBJECTDIR}/_ext/64865378/startup_xc32.o ${OBJECTDIR}/_ext/64865378/interrupts.o ${OBJECTDIR}/_ext/64865378/exceptions.o ${OBJECTDIR}/_ext/64865378/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d ${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d ${OBJECTDIR}/_ext/1761505802/plib_can0.o.d ${OBJECTDIR}/_ext/1761505802/plib_can1.o.d ${OBJECTDIR}/_ext/590292936/plib_clock.o.d ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d ${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d ${OBJECTDIR}/_ext/592442422/plib_evsys.o.d ${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/1761518284/plib_pac.o.d ${OBJECTDIR}/_ext/1227494009/plib_port.o.d ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d ${OBJECTDIR}/_ext/220271371/plib_tc0.o.d ${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d ${OBJECTDIR}/_ext/64865378/initialization.o.d ${OBJECTDIR}/_ext/64865378/startup_xc32.o.d ${OBJECTDIR}/_ext/64865378/interrupts.o.d ${OBJECTDIR}/_ext/64865378/exceptions.o.d ${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o ${OBJECTDIR}/_ext/1032945309/MET_can_open.o ${OBJECTDIR}/_ext/1761505802/plib_can0.o ${OBJECTDIR}/_ext/1761505802/plib_can1.o ${OBJECTDIR}/_ext/590292936/plib_clock.o ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o ${OBJECTDIR}/_ext/1761507328/plib_dsu.o ${OBJECTDIR}/_ext/592442422/plib_evsys.o ${OBJECTDIR}/_ext/1227547160/plib_nvic.o ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o ${OBJECTDIR}/_ext/1761518284/plib_pac.o ${OBJECTDIR}/_ext/1227494009/plib_port.o ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o ${OBJECTDIR}/_ext/220271371/plib_tc0.o ${OBJECTDIR}/_ext/967047524/xc32_monitor.o ${OBJECTDIR}/_ext/64865378/initialization.o ${OBJECTDIR}/_ext/64865378/startup_xc32.o ${OBJECTDIR}/_ext/64865378/interrupts.o ${OBJECTDIR}/_ext/64865378/exceptions.o ${OBJECTDIR}/_ext/64865378/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/MetLib/MET_Bootloader.c ../src/MetLib/MET_can_protocol.c ../src/MetLib/MET_can_open.c ../src/config/my_config/peripheral/can/plib_can0.c ../src/config/my_config/peripheral/can/plib_can1.c ../src/config/my_config/peripheral/clock/plib_clock.c ../src/config/my_config/peripheral/cmcc/plib_cmcc.c ../src/config/my_config/peripheral/dsu/plib_dsu.c ../src/config/my_config/peripheral/evsys/plib_evsys.c ../src/config/my_config/peripheral/nvic/plib_nvic.c ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/my_config/peripheral/pac/plib_pac.c ../src/config/my_config/peripheral/port/plib_port.c ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c ../src/config/my_config/peripheral/tc/plib_tc0.c ../src/config/my_config/stdio/xc32_monitor.c ../src/config/my_config/initialization.c ../src/config/my_config/startup_xc32.c ../src/config/my_config/interrupts.c ../src/config/my_config/exceptions.c ../src/config/my_config/libc_syscalls.c ../src/main.c

# Pack Options 
PACK_COMMON_OPTIONS=-I "${CMSIS_DIR}/CMSIS/Core/Include"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-my_config.mk dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAME51J20A
MP_LINKER_FILE_OPTION=,--script="..\src\config\my_config\ATSAME51J20A.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o: ../src/MetLib/MET_Bootloader.c  .generated_files/flags/my_config/4358b1905f050d2520e7dc7ced48f7a6f9080c07 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o ../src/MetLib/MET_Bootloader.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o: ../src/MetLib/MET_can_protocol.c  .generated_files/flags/my_config/a4de057dc8b8bea1f12cd03c6ccaef91873d159b .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o ../src/MetLib/MET_can_protocol.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_open.o: ../src/MetLib/MET_can_open.c  .generated_files/flags/my_config/436d514227d1b479e22f737896b3a10fe4094d06 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_open.o ../src/MetLib/MET_can_open.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can0.o: ../src/config/my_config/peripheral/can/plib_can0.c  .generated_files/flags/my_config/11156051dc3b57a89fa1e72044110424a5f43515 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can0.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can0.o ../src/config/my_config/peripheral/can/plib_can0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can1.o: ../src/config/my_config/peripheral/can/plib_can1.c  .generated_files/flags/my_config/4793a363ef7e345ddabd6dbdaa59bf1f6766332b .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can1.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can1.o ../src/config/my_config/peripheral/can/plib_can1.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/590292936/plib_clock.o: ../src/config/my_config/peripheral/clock/plib_clock.c  .generated_files/flags/my_config/df2f5eabbeb1250db4ec04ea824bf14fada7c0b1 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/590292936" 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/590292936/plib_clock.o.d" -o ${OBJECTDIR}/_ext/590292936/plib_clock.o ../src/config/my_config/peripheral/clock/plib_clock.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227883696/plib_cmcc.o: ../src/config/my_config/peripheral/cmcc/plib_cmcc.c  .generated_files/flags/my_config/1d9ff1fc6791926c78a4f2a0151adb48eb7d7049 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227883696" 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d" -o ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o ../src/config/my_config/peripheral/cmcc/plib_cmcc.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761507328/plib_dsu.o: ../src/config/my_config/peripheral/dsu/plib_dsu.c  .generated_files/flags/my_config/b605fe38223b09474f8d9f6453ab3d4a4ee482b4 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761507328" 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d" -o ${OBJECTDIR}/_ext/1761507328/plib_dsu.o ../src/config/my_config/peripheral/dsu/plib_dsu.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/592442422/plib_evsys.o: ../src/config/my_config/peripheral/evsys/plib_evsys.c  .generated_files/flags/my_config/f64884518e3598c7e95c927aab494e6cb8d8870d .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/592442422" 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/592442422/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/592442422/plib_evsys.o ../src/config/my_config/peripheral/evsys/plib_evsys.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227547160/plib_nvic.o: ../src/config/my_config/peripheral/nvic/plib_nvic.c  .generated_files/flags/my_config/6eb54df4b25e5702a97c11eaad3ad384e17e2a0c .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227547160" 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1227547160/plib_nvic.o ../src/config/my_config/peripheral/nvic/plib_nvic.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o: ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/my_config/ee04f11add58e72382c6866eedf837f0a821a1ed .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1792891082" 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761518284/plib_pac.o: ../src/config/my_config/peripheral/pac/plib_pac.c  .generated_files/flags/my_config/816015b37efe26e238a80b2633cfe7a825b7457 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761518284" 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761518284/plib_pac.o.d" -o ${OBJECTDIR}/_ext/1761518284/plib_pac.o ../src/config/my_config/peripheral/pac/plib_pac.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227494009/plib_port.o: ../src/config/my_config/peripheral/port/plib_port.c  .generated_files/flags/my_config/37dd340792813b36ecb45ca7b06e4c27ec9a1d1b .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227494009" 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227494009/plib_port.o.d" -o ${OBJECTDIR}/_ext/1227494009/plib_port.o ../src/config/my_config/peripheral/port/plib_port.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o: ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c  .generated_files/flags/my_config/941e3ff0c9d6a660a6a536306b23bbbfbc450559 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761520795" 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/220271371/plib_tc0.o: ../src/config/my_config/peripheral/tc/plib_tc0.c  .generated_files/flags/my_config/941c8c2ecf7cbc07aad7f55a67abdb7093ec4fba .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/220271371" 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/220271371/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/220271371/plib_tc0.o ../src/config/my_config/peripheral/tc/plib_tc0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/967047524/xc32_monitor.o: ../src/config/my_config/stdio/xc32_monitor.c  .generated_files/flags/my_config/4db66fdcd594e870856a732bb4faaafaf6e064e3 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/967047524" 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/967047524/xc32_monitor.o ../src/config/my_config/stdio/xc32_monitor.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/initialization.o: ../src/config/my_config/initialization.c  .generated_files/flags/my_config/98538aea3572729b5ec314de9fced57eff31534e .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/initialization.o.d" -o ${OBJECTDIR}/_ext/64865378/initialization.o ../src/config/my_config/initialization.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/startup_xc32.o: ../src/config/my_config/startup_xc32.c  .generated_files/flags/my_config/346239ba0602dc18b50aaf54051a41c0c24f128b .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/64865378/startup_xc32.o ../src/config/my_config/startup_xc32.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/interrupts.o: ../src/config/my_config/interrupts.c  .generated_files/flags/my_config/2f102cbbfa277c410259c947629d74128adbbb90 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/interrupts.o.d" -o ${OBJECTDIR}/_ext/64865378/interrupts.o ../src/config/my_config/interrupts.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/exceptions.o: ../src/config/my_config/exceptions.c  .generated_files/flags/my_config/2f2627dcfc69fcc98136bee42cb5fb0b7fe7a8f2 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/exceptions.o.d" -o ${OBJECTDIR}/_ext/64865378/exceptions.o ../src/config/my_config/exceptions.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/libc_syscalls.o: ../src/config/my_config/libc_syscalls.c  .generated_files/flags/my_config/1930bf43277e3b669d879c17b6edebecdb02a4cf .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/64865378/libc_syscalls.o ../src/config/my_config/libc_syscalls.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/my_config/b70e0d45698a4efe813b5de58e326ec29f175511 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o: ../src/MetLib/MET_Bootloader.c  .generated_files/flags/my_config/9173ba054eb9de13dcf6c98ffe06e8896796c10d .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o ../src/MetLib/MET_Bootloader.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o: ../src/MetLib/MET_can_protocol.c  .generated_files/flags/my_config/de83f9b490a88c25ca23da0f2ba3f49eb08c3b8b .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o ../src/MetLib/MET_can_protocol.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_open.o: ../src/MetLib/MET_can_open.c  .generated_files/flags/my_config/bb37f339bfd3e76d8e24f882076f097e50fc3d95 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_open.o ../src/MetLib/MET_can_open.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can0.o: ../src/config/my_config/peripheral/can/plib_can0.c  .generated_files/flags/my_config/dc0955a627de50f1eb92e182ee62da061d42ef66 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can0.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can0.o ../src/config/my_config/peripheral/can/plib_can0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can1.o: ../src/config/my_config/peripheral/can/plib_can1.c  .generated_files/flags/my_config/8aeb9804ea81db4c4a488e0f4b7eae42cff48214 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can1.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can1.o ../src/config/my_config/peripheral/can/plib_can1.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/590292936/plib_clock.o: ../src/config/my_config/peripheral/clock/plib_clock.c  .generated_files/flags/my_config/5074ef9b137f58517836bfebaf1ef4baf5a95bb5 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/590292936" 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/590292936/plib_clock.o.d" -o ${OBJECTDIR}/_ext/590292936/plib_clock.o ../src/config/my_config/peripheral/clock/plib_clock.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227883696/plib_cmcc.o: ../src/config/my_config/peripheral/cmcc/plib_cmcc.c  .generated_files/flags/my_config/d8f57106e20772c4519134e187e2cfe3fe0dc191 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227883696" 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d" -o ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o ../src/config/my_config/peripheral/cmcc/plib_cmcc.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761507328/plib_dsu.o: ../src/config/my_config/peripheral/dsu/plib_dsu.c  .generated_files/flags/my_config/987dea40797d17acec90b17d680d73fc636d1371 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761507328" 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d" -o ${OBJECTDIR}/_ext/1761507328/plib_dsu.o ../src/config/my_config/peripheral/dsu/plib_dsu.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/592442422/plib_evsys.o: ../src/config/my_config/peripheral/evsys/plib_evsys.c  .generated_files/flags/my_config/1cb4186c56714d8e2478e3ab0b92edb041b9c38a .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/592442422" 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/592442422/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/592442422/plib_evsys.o ../src/config/my_config/peripheral/evsys/plib_evsys.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227547160/plib_nvic.o: ../src/config/my_config/peripheral/nvic/plib_nvic.c  .generated_files/flags/my_config/95f7702900ee84e2bd74e26c378a65c43c3d59d2 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227547160" 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1227547160/plib_nvic.o ../src/config/my_config/peripheral/nvic/plib_nvic.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o: ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/my_config/d31a8444a0cbcb777be9e86340d6fd9c73792a90 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1792891082" 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761518284/plib_pac.o: ../src/config/my_config/peripheral/pac/plib_pac.c  .generated_files/flags/my_config/56d571c1ea56e7bf4c57f471c5d1ba0d01dabc3f .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761518284" 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761518284/plib_pac.o.d" -o ${OBJECTDIR}/_ext/1761518284/plib_pac.o ../src/config/my_config/peripheral/pac/plib_pac.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227494009/plib_port.o: ../src/config/my_config/peripheral/port/plib_port.c  .generated_files/flags/my_config/b4c07b8057c9315dbddbe53cc4fa5cb7b38874de .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227494009" 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227494009/plib_port.o.d" -o ${OBJECTDIR}/_ext/1227494009/plib_port.o ../src/config/my_config/peripheral/port/plib_port.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o: ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c  .generated_files/flags/my_config/10dd0802e105082b755f30bfc7fe07254f5d06a9 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761520795" 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/220271371/plib_tc0.o: ../src/config/my_config/peripheral/tc/plib_tc0.c  .generated_files/flags/my_config/da1ba8b06073eb1b9be11d48e4cea029e4b3013f .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/220271371" 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/220271371/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/220271371/plib_tc0.o ../src/config/my_config/peripheral/tc/plib_tc0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/967047524/xc32_monitor.o: ../src/config/my_config/stdio/xc32_monitor.c  .generated_files/flags/my_config/9f446255a4b9066079c8b750527aeb9b34e615fe .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/967047524" 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/967047524/xc32_monitor.o ../src/config/my_config/stdio/xc32_monitor.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/initialization.o: ../src/config/my_config/initialization.c  .generated_files/flags/my_config/e7b553a9950144efbc6efeb6377ea86c27b8bf27 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/initialization.o.d" -o ${OBJECTDIR}/_ext/64865378/initialization.o ../src/config/my_config/initialization.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/startup_xc32.o: ../src/config/my_config/startup_xc32.c  .generated_files/flags/my_config/53e6573d8f5780164cc253fa3bad7d0aa73061e7 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/64865378/startup_xc32.o ../src/config/my_config/startup_xc32.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/interrupts.o: ../src/config/my_config/interrupts.c  .generated_files/flags/my_config/b6471a989ca4fb6a8292fc27448470afc2ceea77 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/interrupts.o.d" -o ${OBJECTDIR}/_ext/64865378/interrupts.o ../src/config/my_config/interrupts.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/exceptions.o: ../src/config/my_config/exceptions.c  .generated_files/flags/my_config/b5ea1fab30b6f5732b7801aab056f65575e47183 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/exceptions.o.d" -o ${OBJECTDIR}/_ext/64865378/exceptions.o ../src/config/my_config/exceptions.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/libc_syscalls.o: ../src/config/my_config/libc_syscalls.c  .generated_files/flags/my_config/a9c089ca092d0830e373231e9e00be77a33fd4a .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/64865378/libc_syscalls.o ../src/config/my_config/libc_syscalls.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/my_config/6d79882b308f9bb12ffc824aee15bfba531c3f97 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/my_config/ATSAME51J20A.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DROM_LENGTH=0xFE000,-DROM_ORIGIN=0x2200,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,-DRAM_ORIGIN=0x20000010,,-DRAM_LENGTH=0x3FFF0 -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/my_config/ATSAME51J20A.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DROM_LENGTH=0xFE000,-DROM_ORIGIN=0x2200,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,-DRAM_ORIGIN=0x20000010,,-DRAM_LENGTH=0x3FFF0 -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/FW301.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/my_config
	${RM} -r dist/my_config

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

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
${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o: ../src/MetLib/MET_Bootloader.c  .generated_files/flags/my_config/b894865db890277fd6328c4db2a185612500f18c .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o ../src/MetLib/MET_Bootloader.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o: ../src/MetLib/MET_can_protocol.c  .generated_files/flags/my_config/1c48d3da0f6a79776203277954bca710492a0546 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o ../src/MetLib/MET_can_protocol.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_open.o: ../src/MetLib/MET_can_open.c  .generated_files/flags/my_config/7487da333ab0dc53b888ff438a3a5d2a2fff50d4 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_open.o ../src/MetLib/MET_can_open.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can0.o: ../src/config/my_config/peripheral/can/plib_can0.c  .generated_files/flags/my_config/650fe90ecf24712f5b2fdf9e16f3d5e97d12e15b .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can0.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can0.o ../src/config/my_config/peripheral/can/plib_can0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can1.o: ../src/config/my_config/peripheral/can/plib_can1.c  .generated_files/flags/my_config/56ddee47fb96e322d72b9b50d7a7c57d80a37ad6 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can1.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can1.o ../src/config/my_config/peripheral/can/plib_can1.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/590292936/plib_clock.o: ../src/config/my_config/peripheral/clock/plib_clock.c  .generated_files/flags/my_config/9d6ddc699295a92ef54ab44b86cffceacaee1794 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/590292936" 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/590292936/plib_clock.o.d" -o ${OBJECTDIR}/_ext/590292936/plib_clock.o ../src/config/my_config/peripheral/clock/plib_clock.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227883696/plib_cmcc.o: ../src/config/my_config/peripheral/cmcc/plib_cmcc.c  .generated_files/flags/my_config/3ea7a685fa867c9c428be879ed1210c7b3fa274a .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227883696" 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d" -o ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o ../src/config/my_config/peripheral/cmcc/plib_cmcc.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761507328/plib_dsu.o: ../src/config/my_config/peripheral/dsu/plib_dsu.c  .generated_files/flags/my_config/52bcf706867207051314b48f14266bc466ed2750 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761507328" 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d" -o ${OBJECTDIR}/_ext/1761507328/plib_dsu.o ../src/config/my_config/peripheral/dsu/plib_dsu.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/592442422/plib_evsys.o: ../src/config/my_config/peripheral/evsys/plib_evsys.c  .generated_files/flags/my_config/579a5d9312bfcad296a42a1290b9d410b59f8908 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/592442422" 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/592442422/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/592442422/plib_evsys.o ../src/config/my_config/peripheral/evsys/plib_evsys.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227547160/plib_nvic.o: ../src/config/my_config/peripheral/nvic/plib_nvic.c  .generated_files/flags/my_config/7594ca8e90495a48a211608e4d1eddfd06938480 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227547160" 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1227547160/plib_nvic.o ../src/config/my_config/peripheral/nvic/plib_nvic.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o: ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/my_config/8daecaf7b3d02601c8e007e63164e036588ad0e0 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1792891082" 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761518284/plib_pac.o: ../src/config/my_config/peripheral/pac/plib_pac.c  .generated_files/flags/my_config/3fb5747f6c58870cebee671a76185ea2335b9f2 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761518284" 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761518284/plib_pac.o.d" -o ${OBJECTDIR}/_ext/1761518284/plib_pac.o ../src/config/my_config/peripheral/pac/plib_pac.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227494009/plib_port.o: ../src/config/my_config/peripheral/port/plib_port.c  .generated_files/flags/my_config/b2c9f8619cc0ec3417736d1999db2eec680f29c5 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227494009" 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227494009/plib_port.o.d" -o ${OBJECTDIR}/_ext/1227494009/plib_port.o ../src/config/my_config/peripheral/port/plib_port.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o: ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c  .generated_files/flags/my_config/33f5e316c6665a7ee5c1ade83638ea6fe3282888 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761520795" 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/220271371/plib_tc0.o: ../src/config/my_config/peripheral/tc/plib_tc0.c  .generated_files/flags/my_config/bebe53a0ccc49ba5908c881d5e5ca571913c4076 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/220271371" 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/220271371/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/220271371/plib_tc0.o ../src/config/my_config/peripheral/tc/plib_tc0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/967047524/xc32_monitor.o: ../src/config/my_config/stdio/xc32_monitor.c  .generated_files/flags/my_config/127ccf0aa5e52d9460bc3ffadfe41db8f833ee7 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/967047524" 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/967047524/xc32_monitor.o ../src/config/my_config/stdio/xc32_monitor.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/initialization.o: ../src/config/my_config/initialization.c  .generated_files/flags/my_config/3105f0cb6e7cf664a4500841297ec3f55146838b .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/initialization.o.d" -o ${OBJECTDIR}/_ext/64865378/initialization.o ../src/config/my_config/initialization.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/startup_xc32.o: ../src/config/my_config/startup_xc32.c  .generated_files/flags/my_config/d78fd907b8da9e50c7837252eead97dae3342368 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/64865378/startup_xc32.o ../src/config/my_config/startup_xc32.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/interrupts.o: ../src/config/my_config/interrupts.c  .generated_files/flags/my_config/dcf81ae789da9ff379c7f835af95e3679415a0c8 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/interrupts.o.d" -o ${OBJECTDIR}/_ext/64865378/interrupts.o ../src/config/my_config/interrupts.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/exceptions.o: ../src/config/my_config/exceptions.c  .generated_files/flags/my_config/54f09103fe851d3926ebc7b82374c2590a753c2e .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/exceptions.o.d" -o ${OBJECTDIR}/_ext/64865378/exceptions.o ../src/config/my_config/exceptions.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/libc_syscalls.o: ../src/config/my_config/libc_syscalls.c  .generated_files/flags/my_config/cabdef3e96efa75e119a15c2ca3b5d7e1e9aa33 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/64865378/libc_syscalls.o ../src/config/my_config/libc_syscalls.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/my_config/fe5909f507aed0eb343bb03bbf782af0580f2b3c .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o: ../src/MetLib/MET_Bootloader.c  .generated_files/flags/my_config/b1266cfb04f2ebc4b99a0dc4527f0b1049f50b8c .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_Bootloader.o ../src/MetLib/MET_Bootloader.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o: ../src/MetLib/MET_can_protocol.c  .generated_files/flags/my_config/f978bfd788a2f8c83a497ab6ed81e867b1eeee1c .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_protocol.o ../src/MetLib/MET_can_protocol.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1032945309/MET_can_open.o: ../src/MetLib/MET_can_open.c  .generated_files/flags/my_config/8348535234404b3c9165443108824e5209d21858 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1032945309" 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1032945309/MET_can_open.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1032945309/MET_can_open.o.d" -o ${OBJECTDIR}/_ext/1032945309/MET_can_open.o ../src/MetLib/MET_can_open.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can0.o: ../src/config/my_config/peripheral/can/plib_can0.c  .generated_files/flags/my_config/b3286f95ac73e489c3ed805b0549d50120941ecd .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can0.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can0.o ../src/config/my_config/peripheral/can/plib_can0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761505802/plib_can1.o: ../src/config/my_config/peripheral/can/plib_can1.c  .generated_files/flags/my_config/c006922eb5060d47920f90aba85fd5fa56afece3 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761505802" 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761505802/plib_can1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761505802/plib_can1.o.d" -o ${OBJECTDIR}/_ext/1761505802/plib_can1.o ../src/config/my_config/peripheral/can/plib_can1.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/590292936/plib_clock.o: ../src/config/my_config/peripheral/clock/plib_clock.c  .generated_files/flags/my_config/53a245b96e7217f4a4d7347392edd857acab1190 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/590292936" 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/590292936/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/590292936/plib_clock.o.d" -o ${OBJECTDIR}/_ext/590292936/plib_clock.o ../src/config/my_config/peripheral/clock/plib_clock.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227883696/plib_cmcc.o: ../src/config/my_config/peripheral/cmcc/plib_cmcc.c  .generated_files/flags/my_config/b8abd55401d73d84618aa3ffdd0238291bd8a849 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227883696" 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227883696/plib_cmcc.o.d" -o ${OBJECTDIR}/_ext/1227883696/plib_cmcc.o ../src/config/my_config/peripheral/cmcc/plib_cmcc.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761507328/plib_dsu.o: ../src/config/my_config/peripheral/dsu/plib_dsu.c  .generated_files/flags/my_config/40d50110234f37676ba5f1151b2db9a0700d41de .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761507328" 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761507328/plib_dsu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761507328/plib_dsu.o.d" -o ${OBJECTDIR}/_ext/1761507328/plib_dsu.o ../src/config/my_config/peripheral/dsu/plib_dsu.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/592442422/plib_evsys.o: ../src/config/my_config/peripheral/evsys/plib_evsys.c  .generated_files/flags/my_config/32ba7d3777c6a9ad28991128c107f965e99ff3d7 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/592442422" 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/592442422/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/592442422/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/592442422/plib_evsys.o ../src/config/my_config/peripheral/evsys/plib_evsys.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227547160/plib_nvic.o: ../src/config/my_config/peripheral/nvic/plib_nvic.c  .generated_files/flags/my_config/1f9125adadcd703a515af56b0bf6fa251e2e1b7 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227547160" 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227547160/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227547160/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1227547160/plib_nvic.o ../src/config/my_config/peripheral/nvic/plib_nvic.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o: ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/my_config/64029034649d6dffc7c761ef7769150f85c83f21 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1792891082" 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1792891082/plib_nvmctrl.o ../src/config/my_config/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761518284/plib_pac.o: ../src/config/my_config/peripheral/pac/plib_pac.c  .generated_files/flags/my_config/78d5dddd0300ae742052b3ad8c5cef0795a0a245 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761518284" 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761518284/plib_pac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761518284/plib_pac.o.d" -o ${OBJECTDIR}/_ext/1761518284/plib_pac.o ../src/config/my_config/peripheral/pac/plib_pac.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1227494009/plib_port.o: ../src/config/my_config/peripheral/port/plib_port.c  .generated_files/flags/my_config/8bbc2ef2ced9fe576eb3ceee85a4d3423db35504 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1227494009" 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1227494009/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1227494009/plib_port.o.d" -o ${OBJECTDIR}/_ext/1227494009/plib_port.o ../src/config/my_config/peripheral/port/plib_port.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o: ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c  .generated_files/flags/my_config/52625b38e693733698a8c6a25752b3f44a742a22 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/1761520795" 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/1761520795/plib_rtc_timer.o ../src/config/my_config/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/220271371/plib_tc0.o: ../src/config/my_config/peripheral/tc/plib_tc0.c  .generated_files/flags/my_config/185546fc9527558d342dc105e7c19db2c75d9b9c .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/220271371" 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/220271371/plib_tc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/220271371/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/220271371/plib_tc0.o ../src/config/my_config/peripheral/tc/plib_tc0.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/967047524/xc32_monitor.o: ../src/config/my_config/stdio/xc32_monitor.c  .generated_files/flags/my_config/471fbdae0f8791488062518ba3981226add35838 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/967047524" 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/967047524/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/967047524/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/967047524/xc32_monitor.o ../src/config/my_config/stdio/xc32_monitor.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/initialization.o: ../src/config/my_config/initialization.c  .generated_files/flags/my_config/e9ad200df1b7ca7e46d03640314db967a40004d6 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/initialization.o.d" -o ${OBJECTDIR}/_ext/64865378/initialization.o ../src/config/my_config/initialization.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/startup_xc32.o: ../src/config/my_config/startup_xc32.c  .generated_files/flags/my_config/ffd3860a3d3b8311e21fdad297cd66c72cd8dfcb .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/64865378/startup_xc32.o ../src/config/my_config/startup_xc32.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/interrupts.o: ../src/config/my_config/interrupts.c  .generated_files/flags/my_config/50ebf90c8a0f9f1efea86861a3d8bcb71f7b29ba .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/interrupts.o.d" -o ${OBJECTDIR}/_ext/64865378/interrupts.o ../src/config/my_config/interrupts.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/exceptions.o: ../src/config/my_config/exceptions.c  .generated_files/flags/my_config/3d4a3fa452a05395125d1a36f3f002a8444b367c .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/exceptions.o.d" -o ${OBJECTDIR}/_ext/64865378/exceptions.o ../src/config/my_config/exceptions.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/64865378/libc_syscalls.o: ../src/config/my_config/libc_syscalls.c  .generated_files/flags/my_config/51241fc4789791f8ec0bcca9cc477041c64e2eb7 .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
	@${MKDIR} "${OBJECTDIR}/_ext/64865378" 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/64865378/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/my_config" -I"../src/packs/ATSAME51J20A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/64865378/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/64865378/libc_syscalls.o ../src/config/my_config/libc_syscalls.c    -DXPRJ_my_config=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/my_config/542d0c5585cc0940e13242b6c0bb37647176abbf .generated_files/flags/my_config/287b6168c2390f6aae73a35d8f186754c68efcf4
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

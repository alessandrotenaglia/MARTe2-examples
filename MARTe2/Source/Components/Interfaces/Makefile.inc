#############################################################
#
# Copyright 2015 F4E | European Joint Undertaking for ITER
# and the Development of Fusion Energy ('Fusion for Energy')
#
# Licensed under the EUPL, Version 1.1 or - as soon they
# will be approved by the European Commission - subsequent
# versions of the EUPL (the "Licence");
# You may not use this work except in compliance with the
# Licence.
# You may obtain a copy of the Licence at:
#
# http://ec.europa.eu/idabc/eupl
#
# Unless required by applicable law or agreed to in
# writing, software distributed under the Licence is
# distributed on an "AS IS" basis,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied.
# See the Licence for the specific language governing
# permissions and limitations under the Licence.
#
#############################################################

PACKAGE = Components

OBJSX =

SPB = Killer.x \
	  TCPSocketMessageProxy.x

ifdef OPEN62541_LIB
	SPB += OPCUAClient.x
endif

ROOT_DIR = ../../..

MAKEDEFAULTDIR=$(MARTe2_DIR)/MakeDefaults

include $(MAKEDEFAULTDIR)/MakeStdLibDefs.$(TARGET)

LIBRARIES_STATIC += $(BUILD_DIR)/OPCUAClient/OPCUAClient$(LIBEXT)
LIBRARIES_STATIC += $(BUILD_DIR)/TCPSocketMessageProxy/TCPSocketMessageProxy$(LIBEXT)

all: $(OBJS) $(SUBPROJ) \
	$(BUILD_DIR)/Interfaces$(LIBEXT) \
	$(BUILD_DIR)/Interfaces$(DLLEXT)
	echo $(OBJS)

include $(MAKEDEFAULTDIR)/MakeStdLibRules.$(TARGET)

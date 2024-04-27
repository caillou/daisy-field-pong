# Project Name
TARGET = field_pong

USE_DAISYSP_LGPL = 1

# Sources
CPP_SOURCES = pong.cpp

# Library Locations
LIBDAISY_DIR = library/libDaisy
DAISYSP_DIR = library/DaisySP

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile


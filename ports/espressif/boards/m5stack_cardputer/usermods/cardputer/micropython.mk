USERMODULES_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(USERMODULES_DIR)/DemuxKeyMatrix.c
SRC_USERMOD += $(USERMODULES_DIR)/DemuxKeyMatrixBindings.c
SRC_USERMOD += $(USERMODULES_DIR)/cardputer.c

CFLAGS_USERMOD += -I$(USERMODULES_DIR)

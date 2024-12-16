ch32v003_lib_utils?=./
ADDITIONAL_C_FILES+=$(ch32v003_lib_utils)/stringify.c
EXTRA_CFLAGS+=-I$(ch32v003_lib_utils)
ch32v003_lib_utils_is_configured=1

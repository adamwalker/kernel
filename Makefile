$(if ${SOURCE_ROOT},, \
		$(error "Please define SOURCE_ROOT"))

CC = gcc
AS = as
LD = ld
STRIP = strip

WARNINGS = all error strict-prototypes missing-prototypes nested-externs missing-declarations undef pointer-arith no-nonnull declaration-after-statement

CFLAGS = --std=gnu99 -pedantic -ffreestanding -nostdlib -nostdinc -nostartfiles -nodefaultlibs ${WARNINGS:%=-W%} 

ifdef DEBUG
CFLAGS += -g
endif

include ${SOURCE_ROOT}/source/Makefile

OBJS = ${ASM_SOURCES:.S=.o}
OBJS += ${C_SOURCES:.c=.o}

.PHONY: all default clean

vpath %.c 	${SOURCE_ROOT}/source
vpath %.S 	${SOURCE_ROOT}/source
vpath %.h 	${SOURCE_ROOT}/include
vpath %.lds ${SOURCE_ROOT}

INCLUDE_DIRS = ${SOURCE_ROOT}/include
CFLAGS += ${INCLUDE_DIRS:%=-I%}

CFLAGS += -m32

DIRECTORIES = $(sort $(dir $(OBJS)))

default: all

all: kernel.elf kernel.elf.strip

LINKER_SCRIPT = ${SOURCE_ROOT}/linker.lds

kernel.elf: ${OBJS} ${LINKER_SCRIPT}
	@echo "[LD] $@"
	@${CC} ${CFLAGS} -T ${LINKER_SCRIPT} -o $@ ${OBJS} 

%.elf.strip: %.elf
	@echo "[STRIP] $@"
	@${STRIP} -o $@ $<

%.o: %.S | $(DIRECTORIES)
	@$(call make-depend,$<,$@,$(subst .o,.d,$@))
	@echo "[AS] $@"
	@${CC} ${CFLAGS} -c $< -o $@

%.o: %.c | $(DIRECTORIES)
	@$(call make-depend,$<,$@,$(subst .o,.d,$@))
	@echo "[CC] $@"
	@${CC} ${CFLAGS} -c $< -o $@

$(DIRECTORIES):
	@echo "[MKDIR] $@"
	@mkdir -p $@

clean:
	@echo "[CLEAN]"
	@rm -f kernel.elf kernel.elf.strip ${OBJS} ${DEPS}

DEPS = $(subst .c,.d,$(C_SOURCES))
DEPS += $(subst .S,.d,$(ASM_SOURCES))

ifneq "$(MAKECMDGOALS)" "clean"
  -include ${DEPS}
endif

# $(call make-depend,source-file,object-file,depend-file)
define make-depend
  ${CC} -MM            \
         -MF $3         \
         -MP            \
         -MT $2         \
         $(CFLAGS)      \
         $(CPPFLAGS)    \
         $1
endef


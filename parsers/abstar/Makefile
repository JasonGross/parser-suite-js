CFLAGS ?= -std=c11 -O3 -Wall -Wpedantic

.PHONY: all test

all: parserbuf

parserbuf: parserbuf.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

ab10::
	echo -n "abababababababababab" > $@

ab100: ab10
	echo -n "$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)" > $@

ab1000: ab100
	@echo -n "$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)" > $@

ab10000: ab1000
	@echo -n "$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)" > $@

ab100000: ab10000
	@echo -n "$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)" > $@

ab1000000: ab100000
	@echo -n "$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)$(shell cat $<)" > $@

ab10000000: ab1000000
	cp -f $< $@
	cat $< >> $@
	cat $< >> $@
	cat $< >> $@
	cat $< >> $@
	cat $< >> $@
	cat $< >> $@
	cat $< >> $@
	cat $< >> $@
	cat $< >> $@

test: ab10000000 parserbuf
	for F in ab10 ab100 ab1000 ab10000 ab100000 ab1000000 ab10000000; do \
	FMT="$$F (real: %e, user: %U, sys: %S, mem: %M ko)"; \
	`which time` -f "$$FMT" cat $$F>/dev/null; \
	`which time` -f "$$FMT" cat $$F | ./parserbuf; \
	echo $$?; \
	done

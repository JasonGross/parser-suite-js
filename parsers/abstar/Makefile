CFLAGS ?= -std=c11 -O3 -Wall -Wpedantic

.PHONY: all test test-big test-small

all: parserbuf parserunbuf parserbufml parserunbufml

parserswitch parserbuf parserunbuf: % : %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

parserbufml parserunbufml: % : %.ml
	ocamlopt -o $@ $<

ab10::
	echo -n "abababababababababab" > $@

%.0 : %
	@cp -f $< $@
	@cat $< >> $@
	@cat $< >> $@
	@cat $< >> $@
	@cat $< >> $@
	@cat $< >> $@
	@cat $< >> $@
	@cat $< >> $@
	@cat $< >> $@
	@cat $< >> $@

test: ab10.0.0.0.0.0.0 parserbuf parserswitch parserunbuf parserbufml parserunbufml
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0 ab10.0.0.0.0.0.0; do \
	FMT="$$F (real: %e, user: %U, sys: %S, mem: %M ko)"; \
	`which time` -f "cat     $$FMT" cat $$F>/dev/null; \
	`which time` -f "buf     $$FMT" cat $$F | ./parserbuf; \
	`which time` -f "unbuf   $$FMT" cat $$F | ./parserunbuf; \
	`which time` -f "switch  $$FMT" cat $$F | ./parserswitch; \
	`which time` -f "bufml   $$FMT" cat $$F | ./parserbufml; \
	echo $$?; \
	done

test-small: ab10.0.0.0.0.0 parserunbufml
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0; do \
	FMT="$$F (real: %e, user: %U, sys: %S, mem: %M ko)"; \
	`which time` -f "cat     $$FMT" cat $$F>/dev/null; \
	`which time` -f "bufml   $$FMT" cat $$F | ./parserbufml; \
	`which time` -f "unbufml $$FMT" cat $$F | ./parserunbufml; \
	echo $$?; \
	done

test-big: ab10.0.0.0.0.0.0.0 parserunbufml
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0 ab10.0.0.0.0.0.0 ab10.0.0.0.0.0.0.0; do \
	FMT="$$F (real: %e, user: %U, sys: %S, mem: %M ko)"; \
	`which time` -f "cat     $$FMT" cat $$F>/dev/null; \
	`which time` -f "unbufml $$FMT" cat $$F | ./parserunbufml; \
	echo $$?; \
	done

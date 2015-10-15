CFLAGS ?= -std=c99 -O3 -Wall -Wpedantic

.PHONY: all test test-big test-small

all: parserbuf parserunbuf parserbufml parserunbufml

parserswitch parserbuf parserunbuf: % : %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

parserbufml parserunbufml: % : %.ml
	ocamlopt -o $@ $<

ab10:
	echo -n "abababababababababab" > $@

ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0 ab10.0.0.0.0.0.0 ab10.0.0.0.0.0.0.0 ab10.0.0.0.0.0.0.0.0 : %.0 : %
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

make_fmt = $$(echo "$1 (real: %e, user: %U, sys: %S, mem: %M ko)" | sed s'/\.//g')

test: ab10.0.0.0.0.0.0 parserbuf parserswitch parserunbuf parserbufml parserunbufml
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0 ab10.0.0.0.0.0.0; do \
	FMT="$(call make_fmt, $$F)"; \
	$(shell which time) -f "cat     $$FMT" cat $$F>/dev/null; \
	$(shell which time) -f "buf     $$FMT" ./parserbuf $$F; \
	$(shell which time) -f "unbuf   $$FMT" ./parserunbuf $$F; \
	$(shell which time) -f "switch  $$FMT" ./parserswitch $$F; \
	$(shell which time) -f "unbufml $$FMT" ./parserunbufml $$F; \
	echo $$?; \
	done

test-pipe: ab10.0.0.0.0.0.0 parserbuf parserswitch parserunbuf parserbufml parserunbufml
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0 ab10.0.0.0.0.0.0; do \
	FMT="$(call make_fmt, $$F)"; \
	$(shell which time) -f "cat      $$FMT" cat $$F>/dev/null; \
	$(shell which time) -f "|buf     $$FMT" cat $$F | ./parserbuf; \
	$(shell which time) -f "|unbuf   $$FMT" cat $$F | ./parserunbuf; \
	$(shell which time) -f "|switch  $$FMT" cat $$F | ./parserswitch; \
	$(shell which time) -f "|unbufml $$FMT" cat $$F | ./parserunbufml; \
	echo $$?; \
	done

test-small: ab10.0.0.0.0.0 parserunbufml parserbufml
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0; do \
	FMT="$(call make_fmt, $$F)"; \
	$(shell which time) -f "cat     $$FMT" cat $$F>/dev/null; \
	$(shell which time) -f "buf     $$FMT" ./parserbuf $$F; \
	$(shell which time) -f "unbuf   $$FMT" ./parserunbuf $$F; \
	$(shell which time) -f "bufml   $$FMT" ./parserbufml $$F; \
	$(shell which time) -f "unbufml $$FMT" ./parserunbufml $$F; \
	echo $$?; \
	done

test-big: ab10.0.0.0.0.0.0.0 parserunbufml parserbuf
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0 ab10.0.0.0.0.0.0 ab10.0.0.0.0.0.0.0; do \
	FMT="$(call make_fmt, $$F)"; \
	$(shell which time) -f "cat     $$FMT" cat $$F>/dev/null; \
	$(shell which time) -f "buf     $$FMT" ./parserbuf $$F; \
	$(shell which time) -f "unbufml $$FMT" ./parserunbufml $$F; \
	echo $$?; \
	done

test-big-pipe: ab10.0.0.0.0.0.0.0.0 parserunbufml parserbuf
	for F in ab10 ab10.0 ab10.0.0 ab10.0.0.0 ab10.0.0.0.0 ab10.0.0.0.0.0 ab10.0.0.0.0.0.0 ab10.0.0.0.0.0.0.0.0 ab10.0.0.0.0.0.0.0; do \
	FMT="$(call make_fmt, $$F)"; \
	$(shell which time) -f "cat      $$FMT" cat $$F>/dev/null; \
	$(shell which time) -f "|buf     $$FMT" cat $$F | ./parserbuf; \
	$(shell which time) -f "|unbufml $$FMT" cat $$F | ./parserunbufml; \
	echo $$?; \
	done

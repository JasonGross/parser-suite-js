V = 0

Q_0 := @
Q_1 :=
Q = $(Q_$(V))

VECHO_0 := @echo
VECHO_1 := @true
VECHO = $(VECHO_$(V))

.PHONY: all language-ecmascript clean

all:

clean::
	git submodule foreach git clean -xfd

language-ecmascript::
	cd parsers/language-ecmascript && ( cabal sandbox init && \
	cabal install --only-dependencies && \
	cabal build && \
	cabal install )

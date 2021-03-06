###########################################################################
# LPRng - An Extended Print Spooler System
#
# Copyright 1988-1997 Patrick Powell, San Diego, California
#     papowell@sdsu.edu
# See LICENSE for conditions of use.
#
###########################################################################
# MODULE: FAQ/Makefile
# PURPOSE: generate utilities
# Makefile.in,v 1.7 1998/03/30 02:37:07 papowell Exp
########################################################################## 

# FAQ Makefile
#

FMT=LPRng-Reference
DSSSL=docbook-1.54
DSSSL=modular

SRC=.

CATALOGS= \
      -c /usr/local/share/sgml/catalog \
      -c /usr/local/share/sgml/docbook/dsssl/${DSSSL}/catalog

DOC=LPRng-Reference

all: license.enc license.txt y2k.txt $(DOC).html $(DOC).pdf LPRng-Reference-Multipart/index.htm purge

LICENSE= $(SRC)/../LICENSE

license.txt: $(LICENSE)
	cp $(LICENSE) $@

license.enc: $(LICENSE) Makefile
	echo "<![ CDATA [" >$@
	cat $(LICENSE) >>$@
	echo "]]>" >>$@

y2k.txt: $(SRC)/../Y2KCompliance
	cp  $(SRC)/../Y2KCompliance $@

$(DOC).html: $(DOC).sgml $(DOC).dsl Makefile license.enc
	jade -i output.html -V nochunks -t sgml \
		$(CATALOGS) -d $(FMT).dsl $(DOC).sgml >$(DOC).html
	-tidy -i -m -f /dev/null ${TIDYFLAGS} $@
	./updateheader $@

check: license.enc
	#nsgmls -s -f handbook.errs handbook.sgml
	nsgmls -s $(CATALOGS) $(DOC).sgml

$(DOC).tex: $(DOC).sgml $(FMT).dsl Makefile
	jade -Vtex-backend -ioutput.print -t tex -o $(DOC).tex \
		$(CATALOGS) -d $(FMT).dsl $(DOC).sgml

$(DOC).dvi: $(DOC).tex $(FMT).dsl Makefile
	@echo "==> TeX pass 1/3"
	-tex "&jadetex" $(DOC).tex  2>&1 >/dev/null
	@echo "==> TeX pass 2/3"
	-tex "&jadetex" $(DOC).tex  2>&1 >/dev/null
	@echo "==> TeX pass 3/3"
	tex "&jadetex" $(DOC).tex

$(DOC).ps: $(DOC).dvi
	dvips -q -t letter -o $(DOC).ps $(DOC).dvi
$(DOC).pdf: $(DOC).ps
	ps2pdf -dPDFSETTINGS=/default \
	-dEmbedAllFonts=true \
	-dAntiAliasColorImages=true \
	-dAntiAliasGrayImages=true \
	-dAntiAliasMonoImages=true \
	-dCompatibilityLevel=1.2  \
	$(DOC).ps $(DOC).pdf

purge:
	rm -f *.aux *.log *.toc *.fot *.ps *.dvi *.tex


.PHONY: all clean install ci install.zman update purge

update:
	./updatesgmlmirrors ../MIRRORS *.sgml
	./updateversion *.sgml
	cp ../CHANGES .
	rm -f genindex.sgml
	perl collateindex.pl -t "Index" -N -o genindex.sgml
	jade -V html-index -V nochunks -t sgml \
		$(CATALOGS) -d \
		/usr/local/share/sgml/docbook/dsssl/modular/html/docbook.dsl \
		$(DOC).sgml >/dev/null
	perl collateindex.pl -t "Index" -o genindex.sgml HTML.index
	${MAKE} all

# 
#
install:
	
clean:
	-rm -f *.errs HTML.* *.tex *.log *.aux *.toc *.dvi *.ps *.tex

mostlyclean distclean:: clean

realclean: clean purge
	-rm -f CHANGES HTML.* genindex.sgml
	-rm -f *.ps *.dvi *.htm *.html *.pdf
	-rm -rf LPRng-Reference-Multipart
	

#CI=
#CO=-kv
CO=-l
cifast ci: clean
	checkin() { \
		(set +e; rcs -l $$1; exit 0); \
		ci $(CI) -l -u -f -mUpdate -t-Initial $$1; \
	}; \
	for i in  *.sgml Makefile.in Makefile; do \
		checkin $$i; \
	done;

correct:
	correct -d dict *.sgml

LPRng-Reference-Multipart/index.htm: $(DOC).sgml $(DOC).dsl Makefile license.enc
	rm -rf LPRng-Reference-Multipart;
	if [ ! -d LPRng-Reference-Multipart ] ; then mkdir LPRng-Reference-Multipart; fi
	cp LPRng.jpg LPRngT-L.jpg LPRng-Reference-Multipart
	jade -i output.html -V html-manifest -t sgml \
		$(CATALOGS) -d $(FMT).dsl $(DOC).sgml
	-tidy -i -m -f /dev/null ${TIDYFLAGS} `xargs < HTML.manifest`
	./updateheader index.htm
	mv *.htm LPRng-Reference-Multipart


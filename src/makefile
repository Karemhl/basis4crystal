TOP = $(shell pwd)

all: 
	@mkdir -p  $(TOP)/bin 
	@cd $(TOP)/basis4crystal/;make;cp basis4crystal ../bin/; cd ..

install: 
	@cp $(TOP)/bin/basis4crystal /usr/local/bin/.


PLATFORM?=linux_x86_64

CACHE=.cache
RELEASE= $(CACHE)/release
TARGET=froggyhop



all: build


-include config/$(PLATFORM).mk


build: env $(RELEASE)/$(TARGET)


.PHONY: env clean


exec: build
	$(RELEASE)/$(TARGET)


env: 
	mkdir -pv $(CACHE)
	mkdir -pv $(RELEASE)


clean:
	rm -rfv $(CACHE)





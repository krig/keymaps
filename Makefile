# Based on https://github.com/patrick-elmquist/keymaps

USER = krig
KEYBOARDS = planck preonic m50a

PATH_planck = planck
PATH_preonic = preonic
PATH_m50a = wilba_tech/rama_works_m50_a

NAME_planck = planck/ez/glow
NAME_preonic = preonic/rev3
NAME_m50a = wilba_tech/rama_works_m50_a

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive
	git submodule foreach git pull origin master
	git submodule foreach make git-submodule

	# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/common qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# run lint check
	#cd qmk_firmware; qmk lint -km $(USER) -kb $(NAME_$@) 

	# run build
	mkdir -p $(shell pwd)/build
	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(NAME_$@):$(USER)

	# cleanup symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf $(shell pwd)/build


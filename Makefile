CMAKE_BINARY := x86_64-w64-mingw32-cmake
BUILD_DIRECTORY := ${PWD}/build
MOD_DIRECTORY := /mnt/LinuxHDD/SteamLibrary/steamapps/compatdata/1060230/pfx/drive_c/users/steamuser/AppData/Roaming/majicjungle/sapiens/mods
MOD_ID := sapiens_terrain_variations
MOD_DESCRIPTION := $(shell head -n 6 README.md | sed -z 's/\n/\\n/g')

init:
	${CMAKE_BINARY} -DMOD_ID=${MOD_ID} -DMOD_NAME="Terrain Variations" -DDESCRIPTION="${MOD_DESCRIPTION}" -DDEVELOPER="nmattela" -DDEVELOPER_URL="https://github.com/nmattela/sapiens_terrain_variations" -DPREVIEW_FILE="preview.png" -DMOD_MAJOR_VERSION=1 -DMOD_MINOR_VERSION=1 -DMOD_PATCH_VERSION=0 . -B build
	cmake --build build/
	- rm ${MOD_DIRECTORY}/${MOD_ID}
	ln -s ${BUILD_DIRECTORY}/${MOD_ID}/ ${MOD_DIRECTORY}/${MOD_ID}
	ln -s ${PWD}/models/ ${BUILD_DIRECTORY}/${MOD_ID}/models
	ln -s ${PWD}/scripts/ ${BUILD_DIRECTORY}/${MOD_ID}/scripts

build:
	cmake --build build/

publish:
	- rm -rf ${BUILD_DIRECTORY}/${MOD_ID}/models
	- rm -rf ${BUILD_DIRECTORY}/${MOD_ID}/scripts
	- rm -rf ${MOD_DIRECTORY}/${MOD_ID}
	- cp -r ${PWD}/models/ ${BUILD_DIRECTORY}/${MOD_ID}/models
	- cp -r ${PWD}/scripts/ ${BUILD_DIRECTORY}/${MOD_ID}/scripts
	cp ${PWD}/workshop.mjl ${BUILD_DIRECTORY}/${MOD_ID}/workshop.mjl
	- cp -r ${BUILD_DIRECTORY}/${MOD_ID} ${MOD_DIRECTORY}/${MOD_ID}
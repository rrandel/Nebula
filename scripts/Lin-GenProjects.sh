#!/bin/bash
pushd "$(dirname "$0")/.." > /dev/null

if [ ! -x "vendor/premake/premake5" ]; then
    echo "Error: premake5 not found in vendor/premake."
    popd > /dev/null
    exit 1
fi

echo "Running premake5 to generate GNU Make project files..."
"./vendor/premake/premake5" gmake2

if [ $? -ne 0 ]; then
    echo "Error: premake5 failed to generate project files."
else
    echo "Success: Project files generated."
fi

popd > /dev/null

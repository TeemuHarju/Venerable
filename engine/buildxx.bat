REM Build script for engine
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get a list of all the .cpp files.
SET cppFilenames=
FOR /R %%f in (*.cpp) do (
	SET cppFilenames=!cppFilenames! %%f
)

REM echo "Files:" %cFilenames%

SET assembly=engine
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror
REM -Wall -Werror
SET includeFlags=-Isrc -I%VULKAN_SDK%/Include -Isrc/vendor
SET linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib -llibcmtd
SET defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS -Xlinker /NODEFAULTLIB:libcmt

ECHO "Building %assembly%%..."
clang++ %cppFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%
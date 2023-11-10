@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get a list of all the .cpp files.
SET cppFilenames=
FOR /R %%f in (*.cpp) do (
    SET cppFilenames=!cppFilenames! %%f
)

REM echo "Files:" %cppFilenames%

SET assembly=engine
SET compilerFlags=-g -std=c++17 -shared -Wvarargs -Wall -Werror
REM -Wall -Werror
SET includeFlags=-Isrc -I%VULKAN_SDK%/Include
SET linkerFlags=-luser32 -lkernel32 -lgdi32 -lshell32 -lvulkan-1 -L%VULKAN_SDK%/Lib -lmsvcrtd -llibcmtd
SET defines=-D_DEBUG -DVEXPORT -D_CRT_SECURE_NO_WARNINGS -Xlinker /NODEFAULTLIB:libcmt
 
ECHO "Building %assembly%..."
clang++ %cppFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%

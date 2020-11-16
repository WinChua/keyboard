INC=-I /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/Headers/
all:
	gcc $(INC) -Wall -o alterkeys main.c -framework ApplicationServices

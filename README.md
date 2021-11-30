# Windows Glulxe

Windows Glulxe is an interpreter for the [Glulx](https://eblong.com/zarf/glulx/) virtual machine, which is widely used to play interactive fiction (text adventure) games created with [Inform 7](http://inform7.com/). It is based on Andew Plotkin's [Glulxe](https://github.com/erkyrath/glulxe) VM reference interpreter, combined with my [Windows Glk](https://github.com/DavidKinder/Windows-Glk/) library, which provides the user interface.

![Windows Glulxe playing City of Secrets](City%20of%20Secrets.png)

## Building

Download and install Visual Studio 2019 Community edition from https://visualstudio.microsoft.com/. In the installer, under "Workloads", make sure that "Desktop development with C++" is selected.

To be able to build the CHM help file, download and install Microsoft's [HTML Help Workshop](https://web.archive.org/web/20200810052030/https://www.microsoft.com/en-us/download/confirmation.aspx?id=21138). Note that this is a link to the version on the Internet Archive as the link to this on Microsoft's site does not work at the moment.

Install git. I use the version of git that is part of Cygwin, a Linux-like environment for Windows, but Git for Windows can be used from a Windows command prompt.

Open the environment that you are using git from (e.g. Cygwin), and switch to the root directory that the build environment will be created under (from here referred to as "\<root>"). Clone this and the reference Glulxe repositories with git:
```
git clone https://github.com/DavidKinder/Windows-Glulxe.git Adv/Glulxe
git clone https://github.com/erkyrath/glulxe.git Adv/Glulxe/Generic
```

Download the latest release of the Windows Glk library from https://github.com/DavidKinder/Windows-Glk/releases/ and copy everything in the WindowsGlk-nnn.zip archive to "\<root>/Adv/Glulxe/WindowsGlk".

### Third-party libraries

#### libxml2

libxml2 is only required if you want to build the version of Glulxe with the debugger included.

Download the latest version of libxml2 from http://xmlsoft.org/sources/. Unpack the archive and copy the contents of the top-level directory to "\<root>/Libraries/libxml2".

Copy the file "\<root>/Libraries/libxml2/win32/VC10/config.h" to "\<root>/Libraries/libxml2/". Open "\<root>/Libraries/libxml2/include/libxml/xmlversion.h" in a text editor, and find and replace all lines containing "#if 1" with "#if 0", except for these two:
```
#if 1
#define LIBXML_PUSH_ENABLED
#end
```
```
#if 1
#define LIBXML_READER_ENABLED
#end
```

### Compiling the project

Start Visual Studio, open the solution "\<root>/Adv/Glulxe/Win/Glulxe.sln", then build and run the "Glulxe" project. If you also want the version of Glulxe with the debugger included, build the "Glulxe_debug" project.


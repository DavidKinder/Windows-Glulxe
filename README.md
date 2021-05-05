# Windows Glulxe

Windows Glulxe is an interpreter for the [Glulx](https://eblong.com/zarf/glulx/) virtual machine, which is widely used to play interactive fiction (text adventure) games created with [Inform 7](http://inform7.com/). It is based on Andew Plotkin's [Glulxe](https://github.com/erkyrath/glulxe) VM reference interpreter, combined with my [Windows Glk](https://github.com/DavidKinder/Windows-Glk/) library, which provides the user interface.

![Windows Glulxe playing City of Secrets](City%20of%20Secrets.png)

## Building

Download and install Visual Studio 2019 Community edition from https://visualstudio.microsoft.com/. In the installer, under "Workloads", make sure that "Desktop development with C++" is selected.

Install git. I use the version of git that is part of Cygwin, a Linux-like environment for Windows, but Git for Windows can be used from a Windows command prompt.

Open the environment that you are using git from (e.g. Cygwin), and switch to the root directory that the build environment will be created under (from here referred to as "\<root>"). Clone this and the reference Glulxe repositories with git:
```
git clone https://github.com/DavidKinder/Windows-Glulxe.git Adv/Glulxe
git clone https://github.com/erkyrath/glulxe.git Adv/Glulxe/Generic
```

Download the latest release of the Windows Glk library from https://github.com/DavidKinder/Windows-Glk/releases/ and copy everything in the WindowsGlk-nnn.zip archive to "\<root>/Adv/Glulxe/WindowsGlk".

### Compiling the project

Start Visual Studio, open the solution "\<root>/Adv/Glulxe/Win/Glulxe.sln", then build and run the "Glulxe" project. If you also want the version of Glulxe with the debugger included, build the "Glulxe_debug" project.


##Installation
- [Unix-like](#unix-like-linux-unix-os-x)
  - [Troubleshooting](#troubleshooting)
- [Windows](#windows)
<br>
- [Building using Qt Creator](#building-using-qt-creator)

###Unix-like (Linux, Unix, OS X):

Grab and install Qt 5.2.0+ from [qt-project website](http://qt-project.org/downloads). Alternatively you could get it from your distro's package repository (`qtbase5-dev` on Debian Jessie).

Clone this repo and build it with Qt's qmake:
```bash
git clone https://github.com/AdrianBZG/SyncMe.git
cd SyncMe/src/SyncMe
mkdir build && cd build
qmake -Wall ../SyncMe.pro
make
```
On success, this will produce a `SyncMe` executable.

See [building using Qt Creator](#building-using-qt-creator) if you want to build the project by using Qt Creator IDE, rather than shell commands.


####Troubleshooting

- Note that `qmake` might not be found by bash or it might be found, but from Qt4 installation. In the case of qmake not working, make sure you use the right qmake.
  - If you have installed Qt5 from the qt-project website, you should specify the full path to Qt's qmake, since it's not added to /user/bin/.
    For example, in my case I used `/home/adrian/Qt5.2.0/5.2.0/gcc_64/bin/qmake`.
  - If you use qmake from your distro's package repository, you might need to pass `-qt=5` option to it.

- If Qt complains about missing GL library, install `libgl-dev` package (`libgl1-mesa-dev` on Debian). The exact package name might differ from distribution to distribution, but you get the idea of what you should look for.

- On OS X you may get a warning while running qmake: "WARNING: Could not resolve Info.plist: 'Info.plist.app'. Check if QMAKE_INFO_PLIST points to a valid file". It should be safe to ignore it.


###Windows

Grab and install MinGW version of Qt 5.2.0+ from [qt-project website](http://qt-project.org/downloads).
The MinGW version includes MinGW compiler, so you don't have to bother with installing one manually.

[Download and extract a ZIP archive of this repo's master branch](https://github.com/AdrianBZG/SyncMe/archive/master.zip), or, if you have git, clone the repository:
```cmd
git clone https://github.com/AdrianBZG/SyncMe.git
```

Create `libs` directory in repo's root and extract contents of the SyncMe archive in there.

Run `cmd.exe`, navigate to the repo' directory and run:
```cmd
set PATH=%PATH%;C:\wherever\is\your\Qt\installed\Tools\mingw48_32\bin\
cd src\SyncMe && mkdir build && cd build
C:\wherever\is\your\Qt\installed\5.2.0\mingw48_32\bin\qmake.exe -Wall ../SyncMe.pro
C:\wherever\is\your\Qt\installed\Tools\mingw48_32\bin\mingw32-make.exe
```
On success, this will produce a `SyncMe.exe` binary. If you used Qt from qt-project webite, your binary would be dynamically linked to Qt's libraries, i.e. the executable would require Qt's dlls from `C:\wherever\is\your\Qt\installed\5.2.0\mingw48_32\bin\` in order to run.

See [building using Qt Creator](#building-using-qt-creator) if you want to build the project by using Qt Creator IDE, rather than command prompt.


##Building using Qt Creator

Qt Creator is cross-platform, so the next instructions should be valid for all platforms.

If you downloaded Qt from the qt-project website, then it's likely that you already have it installed in the Qt's directory. Some generic Qt packages on Linux also install it.

To build the project with Qt Creator:

1. Open the Qt Creator.
2. Select `File -> Open File or Project...`.
3. Select the project file located at `SyncMe/src/SyncMe/SyncMe.pro`.
4. You will be prompted to configure the project, select one set of Qt5.2.0+ libraries (Release and Debug) and click on `Configure Project`.
5. You will see two `Debug`s on the left, click on the lowest one and switch it to `Release`. (or use `Debug` if you're developing)
6. Optional: if you want to speed up the building process a little:
  1. Click on `Projects` on the left.
  2. Under `Build Steps` find `Make`.
  3. Click on its `Details`.
  4. Add `-jN` to the `Make arguments`, where `N` is a number of cores your processor has + 1. For example, if your machine is dual core, add `-j3`.
  5. Close the `Details`.
7. Click the big green arrow on bottom left (or press Ctlr+R), that should build and run the project.
8. Wait for it to be built.
9. You should have a binary in whenever `Project` (on the left) `-> Build directory` points to.

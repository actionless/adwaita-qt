oomox-qtstyleplugin
===================

A native style to bend Qt5/Qt6 applications to look with Themix colors.

This style is based on Qt Adwaita theme.

## Installation

### Arch Linux

Use PKGBUILD file or get it on AUR([qt5](https://aur.archlinux.org/packages/oomox-qt5-styleplugin-git), [qt6](https://aur.archlinux.org/packages/oomox-qt6-styleplugin-git)).

### How to compile manually

The project uses the standard CMake buildsystem.

So for example, the whole compilation process could look like this:

```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr [-DUSE_QT6] ..
make
make install
```

## Usage

After install, you'll be able to either set the theme as your default via your DE's tools (like `systemsettings` or `qt-config`) or start your qt applications with the `-style oomox` parameter.


### Overriding GTK theme

By default theme would load from `GTK_THEME` env var, it could be overriden with:

```
OOMOX_QTSTYLEPLUGIN_THEME=Test qt-app-name
```

which will load the theme from `~/.config/oomox-qtstyleplugin/themes/Test.css`.


## Creating custom theme

In [Themix-GUI](https://github.com/themix-project/themix-gui) choose Export -> Base16 Plugin -> qt-oomox-styleplugin.

### Creating theme manually

Use [default theme](https://github.com/themix-project/oomox-qt-styleplugin/blob/master/src/lib/stylesheet/processed/Oodwaita-light.css) as an example.


## Plans

- load theme parameters on the fly, not only via env var
- make border radius adjustable, at least for the buttons


## Screenshot

![Screenshot](https://raw.githubusercontent.com/themix-project/oomox-qt-styleplugin/master/screenshots/2024-05-28--1716923307_3840x2160_scrot.png)

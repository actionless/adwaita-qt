oomox-qtstyleplugin
===================

A native style to bend Qt5/Qt6 applications to look with Themix colors.

This style is based on Qt Adwaita theme.


## How to compile

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

In Themix-GUI choose Export -> Base16 Plugin -> qt-oomox-styleplugin.

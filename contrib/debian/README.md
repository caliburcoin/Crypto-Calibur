
Debian
====================
This directory contains files used to package caliburd/calibur-qt
for Debian-based Linux systems. If you compile caliburd/calibur-qt yourself, there are some useful files here.

## calibur: URI support ##


calibur-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install calibur-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your calibur-qt binary to `/usr/bin`
and the `../../share/pixmaps/calibur128.png` to `/usr/share/pixmaps`

calibur-qt.protocol (KDE)


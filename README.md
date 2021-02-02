# What is this?

This repository (cde-imake) is intended to host the last release of the open
source CDE project (https://sourceforge.net/projects/cdesktopenv/)
that works with the imake build system.

# Why?

Upstream plans to switch to the autotools suite soon to facilitate packaging CDE on Linux distributions,
but the GNU build system no longer functions well on CDE's SVR4 reference platforms.

Unfortunately, much of the support for these systems has already been removed, so the cde-classic
repository is intended to be the new starting point for efforts to port CDE back to the traditional
UNIX platforms.

There is still enough similarity in the structure between the open source CDE project with imake
and the Open Group release to make this a worthwhile source for backporting bugfixes, etc.

ddui-qt
=======

Direct-drawing user interface tools for C++

## Background

I write a lot of cross-platform immediate-mode GUIs. The nature of these
applications vary dramatically, but they nonetheless share a handful of common
traits. I've bundled the most crucial common traits into this library.

The original `ddui` is built on top of glfw and nanovg. Due to portability and
rendering issues, I've decided to use Qt as the rendering engine instead. At
least for the time being until I get the chance to build fast native bindings
to the vector-drawing APIs for Mac, Windows, and Linux.

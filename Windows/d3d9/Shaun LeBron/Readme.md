# DirectX 9 Wrapper DLL  
Author: Shaun LeBron  
November 2nd, 2009  

In response to a StackOverflow question:

## [Overlaying on a 3D fullscreen application](http://stackoverflow.com/questions/925981/overlaying-on-a-3d-fullscreen-application)

This is code to build a Direct3D wrapper DLL, intercepting all calls to
Direct3D interface functions so that you can draw your own objects to display
over the game.  Just plop the DLL into the same folder as the game's
executable, and it should load it as if it were the real d3d9.dll file.  It
still forwards all calls to the real one in system32, just allows stuff to
happen in between. [original stackoverflow answer](http://stackoverflow.com/a/1662699/142317)

I got this somewhere back in 2006-2007, but I can't find the source.

There are two files

- [`d3d9.cpp`](https://gist.github.com/shaunlebron/3854bf4eec5bec297907#file-d3d9-cpp)
- [`d3d9.h`](https://gist.github.com/shaunlebron/3854bf4eec5bec297907#file-d3d9-h)

I left __notes__ for where to insert your custom code in `d3d9.cpp`:

- [initialize your custom D3D components here.](https://gist.github.com/shaunlebron/3854bf4eec5bec297907#file-d3d9-cpp-L43)
- [call onLostDevice for custom D3D components here.](https://gist.github.com/shaunlebron/3854bf4eec5bec297907#file-d3d9-cpp-L50)
- [call onResetDevice for custom D3D components here.](https://gist.github.com/shaunlebron/3854bf4eec5bec297907#file-d3d9-cpp-L54)
- [draw your custom D3D components here.](https://gist.github.com/shaunlebron/3854bf4eec5bec297907#file-d3d9-cpp-L62)

## Other resources

There are much bigger _open source projects_ which do this that you can use for reference:

- [Open Sauce for Halo](https://bitbucket.org/KornnerStudios/opensauce-release)
- [Multi Theft Auto: San Andreas](https://github.com/multitheftauto/mtasa-blue)  

  
## Source:  
https://gist.github.com/shaunlebron/3854bf4eec5bec297907  


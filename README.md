# bosch island spatial audio - linux

Linux port of the Bosch spatial voice plugin for The Isle Evrima. It hooks into Mumble and applies the gain/pan stream from the Bosch falloff server so voice fades over distance the same way the Windows plugin does.

## requirements

You need Mumble 1.4 or newer, and it has to be a native install. Flatpak and snap mumble run sandboxed, which means they won't see plugins in your home directory even if they're in the right path. The build itself needs gcc 11+ and cmake 3.15+. Tested on x86_64 linux including Steam Deck.

## build

```
cmake -S . -B build
cmake --build build
```

That produces two shared libs in `build/`. Use `theisle_spatial.so` for normal linux and `theisle_spatial_steamdeck.so` for the Steam Deck variant. Don't ship a prebuilt .so between distros, glibc versions won't match and it'll fail to load on the recipient's machine. Just build locally on whatever box you're going to run it on.

## install

Drop the .so and the matching .ini into your Mumble plugins folder:

```
cp build/theisle_spatial.so ~/.local/share/Mumble/Mumble/Plugins/
cp theisle_spatial.ini ~/.local/share/Mumble/Mumble/Plugins/
```

Restart Mumble. The plugin should show up under Configure > Plugins as "Bosch Island - Spatial Audio".

## config

Open `theisle_spatial.ini` and set your real api key before launching:

```
api_key=YOUR_REAL_KEY
active_server=server2
```

Leaving the key as `change_me` makes the plugin keep retrying auth in a loop without telling you anything useful, so this is the first thing to check if voice never fades. Set `debug_log=1` if you want to see what's actually going on. The log file lands next to the .so as `theisle_spatial.log`.

## steam deck

Build the same way and install the steamdeck variant of the .so. Has to be Desktop Mode mumble though, Gaming Mode doesn't manage background apps cleanly enough for this to work.

## unable to load plugin

It's almost always one of three things. The most common is flatpak or snap mumble, where plugins outside the sandbox just aren't visible to the running process. Switching to a native install fixes it. Second is mumble older than 1.4, since the new plugin API doesn't exist below that version. Third is a .so built on a newer distro than yours, in which case rebuild it locally instead of copying the binary across machines.

If the plugin loads but voice doesn't fade, check `theisle_spatial.log` with `debug_log=1` set in the ini. Auth failures in the log usually mean api_key is still `change_me` or wrong.

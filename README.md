# bosch island spatial audio - linux

Linux Mumble plugin for the Bosch Island spatial voice setup in The Isle Evrima.

The plugin connects to the Bosch falloff server and applies the gain/pan data it receives to Mumble voice audio. It is meant to match the Windows plugin behaviour as closely as Mumble's Linux plugin API allows.

## requirements

- Mumble 1.4 or newer
- gcc/g++ with C++17 support
- cmake 3.15 or newer
- x86_64 Linux

Build it on the machine that will run it. A `.so` built on one distro can fail to load on another because of glibc/libstdc++ version differences.

## build

```sh
cmake -S . -B build
cmake --build build
```

The build creates:

- `build/theisle_spatial.so`
- `build/theisle_spatial_steamdeck.so`

## install

Native Mumble usually uses:

```sh
mkdir -p ~/.local/share/Mumble/Mumble/Plugins
cp build/theisle_spatial.so ~/.local/share/Mumble/Mumble/Plugins/
cp theisle_spatial.ini ~/.local/share/Mumble/Mumble/Plugins/
```

Flatpak Mumble usually uses:

```sh
mkdir -p ~/.var/app/info.mumble.Mumble/data/Mumble/Mumble/Plugins
cp build/theisle_spatial.so ~/.var/app/info.mumble.Mumble/data/Mumble/Mumble/Plugins/
cp theisle_spatial.ini ~/.var/app/info.mumble.Mumble/data/Mumble/Mumble/Plugins/
```

Snap Mumble usually uses:

```sh
mkdir -p ~/snap/mumble/current/.local/share/Mumble/Mumble/Plugins
cp build/theisle_spatial.so ~/snap/mumble/current/.local/share/Mumble/Mumble/Plugins/
cp theisle_spatial.ini ~/snap/mumble/current/.local/share/Mumble/Mumble/Plugins/
```

Restart Mumble after copying the files. The plugin should appear under `Configure > Plugins` as `Bosch Island - Spatial Audio`.

## config

Edit the `.ini` next to the `.so` before starting Mumble:

The included config matches the current Bosch falloff server. Leave `api_key=change_me` unless the server admin gives you a different key.

Set `debug_log=1` while testing. The normal build writes `theisle_spatial.log` next to the plugin. The Steam Deck build writes `theisle_spatial_steamdeck.log`.

## steam deck

Use the Steam Deck build and matching config:

```sh
mkdir -p ~/.var/app/info.mumble.Mumble/data/Mumble/Mumble/Plugins
cp build/theisle_spatial_steamdeck.so ~/.var/app/info.mumble.Mumble/data/Mumble/Mumble/Plugins/
cp theisle_spatial_steamdeck.ini ~/.var/app/info.mumble.Mumble/data/Mumble/Mumble/Plugins/
```

Desktop Mode is the expected setup.

## troubleshooting

If Mumble says `Unable to load plugin`, rebuild the plugin on that same machine first. If it still fails, check that Mumble is 1.4 or newer and that the files are in the plugin folder for the Mumble package you are actually running.

If the plugin loads but voice does not fade, set `debug_log=1`, restart Mumble, and check the log next to the `.so`. Auth failures usually mean the API key is missing or wrong.

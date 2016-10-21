# Ayria Extension/Plugin Template

The idea of this repository is to act as a template for new developers. Simply add your code to an export in `DllMain.cpp` and hit compile. As easy as that. However, points of interest that you may want to familiarize yourself with:

* The general file/folder structure. While plugins are not limited to this format, it helps other developers reading your code if you keep it.
* The callback based [Bootstrap](https://github.com/AyriaPublic/NativeBootstrap) exports that will be called if the game is started by Ayrias desktop client. While they are simple and optional, they provide convenient entrypoints for different tasks so we encourage everyone to use them. Experienced developers can ofcourse add more exports for their own APIs.
* The `Utilities` and accompanying `Thirdparty` directory. It provides a lot of useful classes to simplify further development. The most recent (and more generic) implementation of these can be found in the [AyriaUtilities](https://github.com/AyriaPublic/AyriaUtilities) repository.

## Extension/plugin loading

After compiling your extension/plugin you'll find it in your `/Bin/` directory with the extension `.Ayria32` or `.Ayria64` depending on your configuration. This plugin should be copied to your games `/Plugins/` directory where the [Bootstrap](https://github.com/AyriaPublic/NativeBootstrap) module will automatically load it when the game starts.

## Configuration files and extra data

As there's quite a few plugins and more are created daily, it's easy to clutter the clients `/Plugins/` directory if plugins were to store their data in the root folder. While you may ofcourse store your data wherever you want, Ayria recommends that you create a subdirectory for your plugin e.g. `/Plugins/AyriaFS/` or based on author e.g. `/Plugins/Ayria/`. The `/Plugins/Logs/` directory is reserved for logs.

## Debugging information

Ayrias client injects the bootstrap into a new process which makes it hard to debug. As such you'll want to do this injection yourself. There is multiple ways to do this, but for Steam games we recommend compiling the [AyriaPlatform](https://github.com/AyriaPublic/AyriaPlatform) plugin as a replacement for the `steam_api.dll` which will load a [Bootstrap.dll](https://github.com/AyriaPublic/NativeBootstrap) from the games directory on startup; thus enabling you to start the game via your debugger. Other methods include modifying a files ImportAddressTable with tools like [CFF Explorer](http://www.ntcore.com/exsuite.php) to load the `bootstrap.dll` from somewhere.
